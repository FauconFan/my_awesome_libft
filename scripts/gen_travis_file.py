import os
import sys
import re
import yaml
from collections import OrderedDict

OUTPUT_FILE = ".travis.yml"
ALL_TEST_FILE = "scripts/test_all.sh"
ALL_CMDS = []

def represent_ordereddict(self, data):
	return self.represent_mapping('tag:yaml.org,2002:map', data.items())

class OrderedDumper(yaml.Dumper):
	def __init__(self, *args, **kwargs):
		yaml.Dumper.__init__(self, *args, **kwargs)
		self.add_representer(OrderedDict, type(self).represent_ordereddict)

	represent_ordereddict = represent_ordereddict

class SafeOrderedDumper(yaml.SafeDumper):
	def __init__(self, *args, **kwargs):
		yaml.SafeDumper.__init__(self, *args, **kwargs)
		self.add_representer(OrderedDict, type(self).represent_ordereddict)

	represent_ordereddict = represent_ordereddict

class TravisTest(object):
	CURRENT_STAGE = ""

	def __init__(self, name, script, after_script = "make fclean"):
		global ALL_CMDS
		self.name = name
		self.stage = self.CURRENT_STAGE
		self.script = script
		self.after_script = after_script
		if isinstance(script, type([])):
			for command in script:
				ALL_CMDS.append(command)
		else:
			ALL_CMDS.append(script)

def buildTravisData():
	ret = []
	# Verify travis yaml
	TravisTest.CURRENT_STAGE = "Verify .travis.yml"
	ret.append(TravisTest("Use python script to verify", [
		"apt-get install -y python3-yaml",
		"python3 scripts/gen_travis_file.py test.out",
		"diff test.out .travis.yml",
		"rm -f test.out"
		]))
	# Build
	TravisTest.CURRENT_STAGE = "Build"
	for cmd in ['', 'make so']:
		suffix_cmd = ''
		suffix_name = ''
		if cmd != '':
			suffix_cmd = " TEST_CMD=\"" + cmd + "\""
			suffix_name = " (" + cmd + ")"
		version_gcc = 5
		while version_gcc <= 8:
			name_test = "Build libft with gcc " + str(version_gcc) + suffix_name
			cmd_test = "make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=" + str(version_gcc) + suffix_cmd
			ret.append(TravisTest(name_test, cmd_test))
			version_gcc = version_gcc + 1
		name1 = "Build libft with gcc latest" + suffix_name
		cmd1 = "make -C libft test_docker_compile_gcc" + suffix_cmd
		name2 = "Build libft with clang (latest on Debian)" + suffix_name
		cmd2 = "make -C libft test_docker_compile_clang" + suffix_cmd
		ret.append(TravisTest(name1, cmd1))
		ret.append(TravisTest(name2, cmd2))
	ret.append(TravisTest("Build build_custom", "make build_custom"))

	TravisTest.CURRENT_STAGE = "Build custom"
	ret.append(TravisTest("Build Custom All", "make -C tests/build_custom/ all"))

	TravisTest.CURRENT_STAGE = "All"
	with open(ALL_TEST_FILE, 'w') as f:
		f.write("#!/bin/sh\n")
		f.write("\n")
		f.write("set -eux\n")
		f.write("\n")
		for cmd in ALL_CMDS:
			if re.search("apt", cmd) == None:
				f.write(cmd + "\n")
	os.chmod(ALL_TEST_FILE, 0o755)
	ret.append(TravisTest("All script", "make testall"))
	return ret

def getStages(list_tests):
	ret = []

	for test in list_tests:
		if not test.stage in ret:
			ret.append(test.stage)
	return ret

def genererateHeader(output, stages):
	output['sudo'] = 'disabled'
	output['language'] = 'c'
	output['os'] = 'linux'
	output['after_script'] = 'make fclean'
	if len(stages) != 0:
		list_stages = []
		for stage in stages:
			list_stages.append(stage)
		output['stage'] = list_stages

	return output

def buildBody(output, list):
	output['matrix'] = dict()
	output['matrix']['include'] = []
	testbook = output['matrix']['include']
	for test in list:
		testsingle = OrderedDict()
		testsingle['stage'] = test.stage
		if isinstance(test.script, type([])):
			testsingle['script'] = []
			for command in test.script:
				testsingle['script'].append(command)
		else:
			testsingle['script'] = test.script
		testsingle['after_script'] = test.after_script
		testsingle['env'] = dict()
		testsingle['env']['NAME'] = test.name
		testbook.append(testsingle)
	return output

def main():
	if len(sys.argv) == 2:
		global OUTPUT_FILE
		OUTPUT_FILE = sys.argv[1]
	odict = OrderedDict()
	list = buildTravisData()
	stages = getStages(list)
	outputContent = genererateHeader(odict, stages)
	outputContent = buildBody(outputContent, list)

	outputFileContent = yaml.dump(outputContent,
								Dumper=SafeOrderedDumper,
								explicit_start=True,
								explicit_end=True,
								indent=4,
								width=2,
								default_flow_style=False)
	with open(OUTPUT_FILE, 'w') as f:
		f.write(outputFileContent)

if __name__ == "__main__":
	main()

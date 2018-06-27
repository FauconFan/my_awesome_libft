import os
import re

class TravisTest(object):
    CURRENT_STAGE = ""

    def __init__(self, name, script, after_script = "make fclean"):
        self.name = name
        self.stage = self.CURRENT_STAGE
        self.script = script
        self.after_script = after_script

def buildTravisData():
    ret = []
    TravisTest.CURRENT_STAGE = "Verify .travis.yml"
    ret.append(TravisTest("Use python script to verify", [
        "python scripts/gen_travis_file.py > test.out",
        "diff test.out .travis.yml",
        "rm -f test.out"
        ]))
    TravisTest.CURRENT_STAGE = "Build"
    version_gcc = 5
    while version_gcc <= 8:
        ret.append(TravisTest("Build libft with gcc " + str(version_gcc),
                    "make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=" + str(version_gcc)))
        version_gcc = version_gcc + 1
    ret.append(TravisTest("Build libft with gcc latest",
                "make -C libft test_docker_compile_gcc"))
    ret.append(TravisTest("Build libft with clang (latest on Debian)",
                "make -C libft test_docker_compile_clang"))
    ret.append(TravisTest("Build ctestcom", "make ctestcom"))
    ret.append(TravisTest("Build build_custom", "make build_custom"))

    TravisTest.CURRENT_STAGE = "CTestCom"

    ret.append(TravisTest("CTestCom Main Test", "make -C ctestcom testctestcom"))

    TravisTest.CURRENT_STAGE = "Build Custom Test"
    list_tests = os.listdir('./tests/build_custom')
    list_tests.sort()
    for file in list_tests:
        if re.match('^\d\d.*', file):
            nu = file[:2]
            ret.append(TravisTest("Build_Custom Test " + str(nu),
                        "make -C tests/build_custom/ " + str(nu)))

    TravisTest.CURRENT_STAGE = "Final"
    ret.append(TravisTest("Full Build Custom All", "make -C tests/build_custom/ all"))
    return ret

def getStages(list_tests):
    ret = []

    for test in list_tests:
        if not test.stage in ret:
            ret.append(test.stage)
    return ret

def genererateHeader(stages):
    content  = "sudo: disabled\n"
    content += "language: c\n"
    content += "os: linux\n"
    content += "\n"
    content += "after_script: make fclean\n"
    content += "\n"
    if len(stages) != 0:
        content += "stages:\n"
        for stage in stages:
            content += "  - " + stage + "\n"
    content += "\n"
    content += "matrix:\n"
    content += "  include:\n"

    return content

def buildBody(content, list):
    for test in list:
        content += "    - stage: " + test.stage + "\n"
        if isinstance(test.script, type(list)):
            content += "      script:\n"
            for command in test.script:
                content += "        - " + command + "\n"
        else:
            content += "      script: " + test.script + "\n"
        content += "      after_script: " + test.after_script + "\n"
        content += "      env:\n"
        content += "        - NAME=\"" + test.name + "\"\n"
    return content

def main():
    list = buildTravisData()
    stages = getStages(list)
    content = genererateHeader(stages)
    content = buildBody(content, list)

    print(content)


if __name__ == "__main__":
    main()

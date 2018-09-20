#!/bin/sh

set -eux

python3 scripts/gen_travis_file.py test.out
diff test.out .travis.yml
rm -f test.out
make -C libft
find libft/src -name "*.c" | sed 's/\.c//g' | grep -v main | sort > c_files
find libft/src -name "*.o" | sed 's/\.o//g' | sort > o_files
diff c_files o_files
rm -f c_files o_files
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_clang TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_clang TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c90\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_clang TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_clang TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c99\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_clang TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_clang TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c11\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c18\""
make -C libft test_docker_compile_gcc TEST_CMD="make ADDITIONAL_FLAGS=\"-std=c18\""
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c18\""
make -C libft test_docker_compile_gcc TEST_CMD="make so ADDITIONAL_FLAGS=\"-std=c18\""

#!/bin/sh

set -eux

python3 scripts/gen_travis_file.py test.out
diff test.out .travis.yml
rm -f test.out
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8
make -C libft test_docker_compile_gcc
make -C libft test_docker_compile_clang
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=5 TEST_CMD="make so"
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=6 TEST_CMD="make so"
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=7 TEST_CMD="make so"
make -C libft test_docker_compile_gcc VERSION_GCC_DOCKER=8 TEST_CMD="make so"
make -C libft test_docker_compile_gcc TEST_CMD="make so"
make -C libft test_docker_compile_clang TEST_CMD="make so"
make build_custom
make -C tests/build_custom/ all

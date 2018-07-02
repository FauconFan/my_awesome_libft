# This project is not viable. It is still in development

# My awesome libft - [![Build Status](https://travis-ci.org/FauconFan/my_awesome_libft.svg?branch=master)](https://travis-ci.org/FauconFan/my_awesome_libft)

Contains the awesome libft.

The idea is to create a minimal library that contains the minimum libc as possible, just using 6 systems functions:
 - open
 - close
 - read
 - write
 - malloc
 - free

# Organisation

The repository is divided in 3 sub modules.
 - libft : The library itself.
 - build_custom : A program that builds the minimal libft that you need on a given project.
 - CTestCom : A program that generates tests from comments in the source code.

## How to test it

You can edit the file main.c in the src directory,
then use make test, it will compile the library, compile the main file, run it and delete all useless files in the same time.

## To Do list

### CTestCom
 - Create an associated script to automate tests for each test
 - Link with travis
 - Create a lot of tests for all files

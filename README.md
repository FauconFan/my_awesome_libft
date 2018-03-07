# My awesome libft - [![Build Status](https://travis-ci.org/FauconFan/my_awesome_libft.svg?branch=master)](https://travis-ci.org/FauconFan/my_awesome_libft)

Contains the awesome libft.

# This Makefile is not up to date - Check the code by your own or harass the owner to update this README file :3

## How to use it

You have to compile the library using make
Next, you have to specify one folder for the includes flags :
 - the root path of this project

## How to test it

You can edit the file main.c in the src directory,
then use make test, it will compile the library, compile the main file, run it and delete all useless files in the same time.

## To do list : CTestCom

 - Parse files and generate associated tests
 - Send an error if no tests
 - Create a little libray to make some simple test...
 	- assert
 	- assertNull
 	- assertNotNull
 	- assertNumEquals
 	- assertStrEquals
 	- assertDoubleEquals
 	- assertArrNumEquals
 	- assertArrStrEquals
 	- assertArrDoubleEquals
 - Create an associated script to automate tests for each test
 - Link with travis
 - Create a lot of tests for all files

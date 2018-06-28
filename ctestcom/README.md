# Ctestcom

Little program used to parse a c file, catch all the tests in the comment section with a specific format, generate a new file that can be executed to verify if all the given tests passed.

This program is composed by the ctestcom program and the libtestcom library.

# Exemple

```
#Compule the code to get ./ctestcom
make

#Generate the test file
./ctestcom src/main.c test.c

#Compile it with the appropriate flags
gcc test.c -o test \
    -I ../ \
    -I libtestcom/includes -L libtestcom -l ctestcom \

#Execute it
./test

#Cleaning
rm -f test.c test
```

# libtestcom

All kind of tests

- All tests
  - Normal tests
    - assert
    - assert_null
    - assert_notnull
  - Number test
    - assert_char
    - assert_short
    - assert_int
    - assert_long
    - assert_long_long
    - assert_float
    - assert_double
    - assert_long_double
    - assert_unsigned_char
    - assert_unsigned_short
    - assert_unsigned_int
    - assert_unsigned_long
    - assert_unsigned_long_long
    - assert_unsigned_float
    - assert_unsigned_double
    - assert_unsigned_long_double
  - String test
    - assert_strequ
    - assert_strlen
    - assert_strlengteq
    - assert_strlengt
    - assert_strlenlteq
    - assert_strlenlt
    - assert_str_match
    - assert_str_beginwith
    - assert_str_endwith
    - assert_str_contains
    - assert_str_countchar
    - assert_str_countlines
    - assert_str_isprintable
    - assert_str_isascii
    - assert_str_isalnum
  - Array test
    - assert_arr_str
    - assert_arr_char
    - assert_arr_short
    - assert_arr_int
    - assert_arr_long
    - assert_arr_long_long
    - assert_arr_float
    - assert_arr_double
    - assert_arr_long_double
    - assert_arr_unsigned_char
    - assert_arr_unsigned_short
    - assert_arr_unsigned_int
    - assert_arr_unsigned_long
    - assert_arr_unsigned_long_long

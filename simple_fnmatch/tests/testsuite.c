#include <criterion/criterion.h>
#include <fnmatch.h>
#include <stdarg.h>
#include <stdio.h>

#include "../simple_fnmatch.h"

// ?
Test(simple, base1)
{
    char *pattern = "";
    char *string = "";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base2)
{
    char *pattern = "?";
    char *string = "";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base3)
{
    char *pattern = "a?";
    char *string = "aa";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base4)
{
    char *pattern = "a?";
    char *string = "a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base5)
{
    char *pattern = "a?";
    char *string = "bb";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base7)
{
    char *pattern = "?a";
    char *string = "ba";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base8)
{
    char *pattern = "??";
    char *string = "va";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(simple, base9)
{
    char *pattern = "??";
    char *string = "a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

// Backslash
Test(backslash, base1)
{
    char *pattern = "\\?";
    char *string = "?";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base2)
{
    char *pattern = "\\?";
    char *string = "a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base3)
{
    char *pattern = "\\?";
    char *string = "\\a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base4)
{
    char *pattern = "\\\\?";
    char *string = "\\a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base5)
{
    char *pattern = "\\\\?";
    char *string = "?";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base6)
{
    char *pattern = "\\\\?";
    char *string = "a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base7)
{
    char *pattern = "\\\\?";
    char *string = "\\?";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base8)
{
    char *pattern = "\\a";
    char *string = "\\a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base9)
{
    char *pattern = "\\\\a";
    char *string = "\\a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base10)
{
    char *pattern = "\\\\a";
    char *string = "a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base11)
{
    char *pattern = "\\\\a";
    char *string = "\\\\a";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base12)
{
    char *pattern = "\\\\";
    char *string = "\\";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(backslash, base13)
{
    char *pattern = "\\";
    char *string = "\\";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

// Glob
Test(glob, base1)
{
    char *pattern = "*.c";
    char *string = "main.c";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base2)
{
    char *pattern = "\\*.c";
    char *string = "main.c";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base3)
{
    char *pattern = "\\*.c";
    char *string = "*.c";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base4)
{
    char *pattern = "a.*";
    char *string = "a.abadakor";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base5)
{
    char *pattern = "*.ah";
    char *string = "ah.ah";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base6)
{
    char *pattern = "***";
    char *string = "";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base7)
{
    char *pattern = "*to";
    char *string = "toto";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base8)
{
    char *pattern = "test.*.ok";
    char *string = "test.ahok.ok";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base9)
{
    char *pattern = "test.*.ok";
    char *string = "test.ok";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base10)
{
    char *pattern = "*?*?*?*?*?*?*";
    char *string = "tests";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base11)
{
    char *pattern = "***.c";
    char *string = "main.c";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base12)
{
    char *pattern = "****.c";
    char *string = ".c";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base13)
{
    char *pattern = ".?*";
    char *string = ".";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

Test(glob, base14)
{
    char *pattern = "/*/*/*/*/*/*/*/*";
    char *string = "/aa/aa/aa/aa/aa/aa/aa/aa";
    int expected = fnmatch(pattern, string, 0);
    int actual = simple_fnmatch(pattern, string);
    cr_expect_eq(actual, expected, "Expected %d. Got %d.", expected, actual);
}

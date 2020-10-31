#ifndef __UNIT_TEST_H__
#define __UNIT_TEST_H__

#include <stdio.h>
#include <stdbool.h>

bool no_way_someone_use_this_variable_name = true;

#define RUN_TEST(name) \
do { \
    if (name()) \
        printf("[\033[3;42;30m SUCCESS \033[0m"); \
    else \
        printf("[\033[3;41;30m  FAIL   \033[0m"); \
    printf("] " #name "\n"); \
} while (false)

#define EXPECT_EQ(a, b) \
do { \
    if ((a) != (b)) { \
        no_way_someone_use_this_variable_name = false; \
        return false; }\
} while (false)

#define EXPECT_NEQ(a, b) \
do { \
    if ((a) == (b)) { \
        no_way_someone_use_this_variable_name = false; \
        return false; } \
} while (false)

#define EXPECT_TRUE(cond) EXPECT_EQ(cond, true)

#define EXPECT_FALSE(cond) EXPECT_EQ(cond, false)

#define TEST(test_name, ...) \
static bool test_name() { \
    { \
        __VA_ARGS__ \
    } \
    return true; \
}

#define VALIDATE() \
do { \
    if (!no_way_someone_use_this_variable_name) \
        printf("\nSome tests failed.\n"); \
    else \
        printf("\nAll tests succeeded.\n"); \
} while(false)

#endif /* __UNIT_TEST_H__ */

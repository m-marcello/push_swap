#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"

Test(test_suite, test_one)
{
    int res = ft_atoi("1234");
    cr_assert_eq(res, 1234);
}

Test(test_suite, foo_test_one)
{
    int res = ft_atoi("1234");
    cr_assert_eq(res, 1234);
}
Test(test_suite, bar_test_one)
{
    int res = ft_atoi("1234");
    cr_assert_eq(res, 1234);
}
Test(test_two, foo_test_one)
{
    int res = ft_atoi("1234");
    cr_assert_eq(res, 1234);
}

Test(test_two, bar_test_one)
{
    int res = ft_atoi("1234");
    cr_assert_eq(res, 134);
}
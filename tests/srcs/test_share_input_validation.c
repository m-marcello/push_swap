/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_input_validation.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 17:10:41 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/16 18:58:41 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_input_validation, one_string_valid)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"0", &stack_a) == 1 , "one string input should be valid.");
	cr_assert(is_valid_input(1, &"0 -4 572 168 +19635", &stack_a) == 1 , "one string input should be valid.");
	cr_assert(is_valid_input(1, &"8462     -379 39480    379 1   0", &stack_a) == 1 , "one string input with extra spaces in the middle should be valid.");
	cr_assert(is_valid_input(1, &"9277893 -1728 1666 16 3 -808 0     ", &stack_a) == 1 , "one string input ending with extra spaces should be valid.");
	cr_assert(is_valid_input(1, &"+8462     -379 39480    47900 1   0", &stack_a) == 1 , "one string input with extra spaces in the middle should be valid.");
	cr_assert(is_valid_input(1, &"-3 6 2345 -0", &stack_a) == 1 , "one string input with extra spaces -0 should be valid.");
}

Test(sh_input_validation, one_string_empty)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"", &stack_a) == 1 , "one empty string input should be valid.");
}

Test(sh_input_validation, one_string_int_limits)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"2147483647", &stack_a) == 1 , "int_max input should be valid.");
	cr_assert(is_valid_input(1, &"-2147483648", &stack_a) == 1 , "int_min input should be valid.");
	cr_assert(is_valid_input(1, &"2147483648", &stack_a) == 1 , "input > int_max should be invalid.");
	cr_assert(is_valid_input(1, &"-2147483649", &stack_a) == 1 , "input < int_min should be invalid.");
	cr_assert(is_valid_input(1, &"2147483648973", &stack_a) == 1 , "input > int_max should be invalid.");
	cr_assert(is_valid_input(1, &"-978922147483649", &stack_a) == 1 , "input < int_min should be invalid.");
}

Test(sh_input_validation, one_string_dup)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"0 0 3792 2289", &stack_a) == 1 , "one string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(1, &"08179 0 3792 3792 2289", &stack_a) == 1 , "one string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(1, &"782791 3792 2289 2289", &stack_a) == 1 , "one string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(1, &"-8979 1234 797 1234 9 -1234 797", &stack_a) == 1 , "one string input containing duplicate arguments should be invalid.");
}

Test(sh_input_validation, one_string_non_num_char_beg)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"-hdk4", &stack_a) == 0 , "one string input beginning with non num charackter should be invalid.");
	cr_assert(is_valid_input(1, &"\n -332245 3 5 6 -3446 0", &stack_a) == 0 , "one string input beginning with non num charackter should be invalid.");
}

Test(sh_input_validation, one_string_non_num_char_mid)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"78 1107 h2 -107", &stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
	cr_assert(is_valid_input(1, &"2\t107", &stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
	cr_assert(is_valid_input(1, &"2-0792", &stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
}

Test(sh_input_validation, one_string_non_num_char_end)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(1, &"0 -1 2 -3 4 5fhd", &stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
	cr_assert(is_valid_input(1, &"97891-", &stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
	cr_assert(is_valid_input(1, &"-1\n", &stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
}

Test(sh_input_validation, multi_string_valid)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(2, "\"1\" \"-279\"", &stack_a) == 1 , "multi string input should be valid.");
	cr_assert(is_valid_input(4, "\"+9789\" \"000972\" \"-29797 797\" \"808\"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
	cr_assert(is_valid_input(4, "\"+9789  000972\" \"-29797\" \"797\" \"808\"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
	cr_assert(is_valid_input(3, "\"+9789\" \"000972\" \"-29797 797  808\"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
	cr_assert(is_valid_input(4, "\"9\" \"-8\" \"73 \" \"0\"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
	cr_assert(is_valid_input(2, "\"0\" \"  +79\"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
	cr_assert(is_valid_input(3, "\"0\" \"79\" \"-979268   \"", &stack_a) == 1 , "multi string input with extra spaces should be valid.");
}

Test(sh_input_validation, multi_string_empty)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(5, "\"\" \"\" \"\" \"\" \"\"", &stack_a) == 0 , "empty string input should be invalid");
	cr_assert(is_valid_input(2, "\" \" \"1\"", &stack_a) == 0 , "empty string input should be invalid");
	cr_assert(is_valid_input(5, "\"\" \"2974\" \"972\" \"1\" \"0\"", &stack_a) == 0 , "empty string input should be invalid");
	cr_assert(is_valid_input(5, "\"1866\" \"79\" \"\" \"0279\" \"270\"", &stack_a) == 0 , "empty string input should be invalid");
	cr_assert(is_valid_input(2, "\"0\" \"\"", &stack_a) == 0 , "empty string input should be invalid");
}

Test(sh_input_validation, multi_string_int_limits)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(3, "\"7839\" \"2147483647\" \"-97792\"", &stack_a) == 1 , "int_max input should be valid.");
	cr_assert(is_valid_input(3, "\"-2147483648\" \"080810870\" \"-89\"", &stack_a) == 1 , "int_min input should be valid.");
	cr_assert(is_valid_input(4, "\"8786\" \"2147483648\" \"-87879\" \"876278267\"", &stack_a) == 1 , "input > int_max should be invalid.");
	cr_assert(is_valid_input(3, "\"-2147483649\" \"762146\" \"0\"", &stack_a) == 1 , "input < int_min should be invalid.");
	cr_assert(is_valid_input(5, "\"9\" \"99\" \"71\" \"2147483648973\" \"90274\"", &stack_a) == 1 , "input > int_max should be invalid.");
	cr_assert(is_valid_input(3, "\"0\" \"8\" \"-978922147483649\"", &stack_a) == 1 , "input < int_min should be invalid.");
}

Test(sh_input_validation, multi_string_dup_beg)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(4, "\"0\" \"0\" \"3792\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(5, "\"3792\" \"08179\" \"0\" \"3792\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(4, "\"2289\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(7, "\"1234\" \"-8979\" \"797\" \"9\" \"-1234\" \"797\" \"1234\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
}

Test(sh_input_validation, multi_string_dup_mid)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(4, "\"3792\" \"0\" \"0\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(5, "\"08179\" \"3792\" \"0\" \"3792\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(7, "\"-8979\" \"1234\" \"797\" \"9\" \"-1234\" \"1234\" \"7957\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
}

Test(sh_input_validation, multi_string_dup_end)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(4, "\"0\" \"3792\" \"2289\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(5, "\"08179\" \"0\" \"3792\" \"2289\" \"3792\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(4, "\"782791\" \"3792\" \"2289\" \"2289\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
	cr_assert(is_valid_input(7, "\"-8979\" \"1234\" \"797\" \"1234\" \"9\" \"-1234\" \"797\"", &stack_a) == 1 , "multi string input containing duplicate arguments should be invalid.");
}

Test(sh_input_validation, multi_string_non_num_char_beg)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(7, "\"laj6\" \"792\" \"7892\" \"-72\" \"-729\" \"624\" \"12\"", &stack_a) == 0 , "multi string input beginning with non num charackter should be invalid.");
	cr_assert(is_valid_input(3, "\"\t\" \"9279\" \"280\"", &stack_a) == 0 , "multi string input beginning with non num charackter should be invalid.");
}

Test(sh_input_validation, multi_string_non_num_char_mid)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(3, "\"783\" \"-+24\" \"78\"", &stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
	cr_assert(is_valid_input(7, "\"0\" \"70179\" \"-1681\" \"287-979\" \"702\" \"72\" \"-7\"", &stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
	cr_assert(is_valid_input(5, "\"8920\" \"-\" \"20\" \"270\" \"203\"", &stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
}

Test(sh_input_validation, multi_string_non_num_char_end)
{
	t_stack	*stack_a;

	cr_assert(is_valid_input(5, "\"7892\" \"-2892\" \"2\" \"-5\" \"1w\"", &stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
	cr_assert(is_valid_input(3, "\"870\" \"220\" \"720|\"", &stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
	cr_assert(is_valid_input(5, "\"4\" \"-5\" \"6\" \"280\" \"80\n\"", &stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
}

Test(sh_check_duplicates, one_node)
{
	t_stack	*stack;

	append_to_stack(421, &stack);
	cr_assert(check_for_duplicates(&stack) == 1, "stack with one node should be valid");
	free_stack(&stack);
}

Test(sh_check_duplicates, two_nodes)
{
	t_stack	*stack;

	append_to_stack(421, &stack);
	append_to_stack(421, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, mulit_nodes_beg_beg)
{
	t_stack	*stack;

	append_to_stack(41, &stack);
	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	append_to_stack(421, &stack);
	append_to_stack(481, &stack);
	append_to_stack(-2573, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(48521, &stack);
	append_to_stack(491, &stack);
	append_to_stack(-2753, &stack);
	append_to_stack(289762, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, mulit_nodes_beg_mid)
{
	t_stack	*stack;

	append_to_stack(421, &stack);
	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	append_to_stack(421, &stack);
	append_to_stack(481, &stack);
	append_to_stack(-2573, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(48521, &stack);
	append_to_stack(491, &stack);
	append_to_stack(-2753, &stack);
	append_to_stack(289762, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, mulit_nodes_mid)
{
	t_stack	*stack;

	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	append_to_stack(421, &stack);
	append_to_stack(481, &stack);
	append_to_stack(-2573, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(48521, &stack);
	append_to_stack(491, &stack);
	append_to_stack(-2753, &stack);
	append_to_stack(289762, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, mulit_nodes_end_mid)
{
	t_stack	*stack;

	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	append_to_stack(421, &stack);
	append_to_stack(481, &stack);
	append_to_stack(-2573, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(48521, &stack);
	append_to_stack(491, &stack);
	append_to_stack(-2753, &stack);
	append_to_stack(289762, &stack);
	append_to_stack(289762, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, mulit_nodes_end_end)
{
	t_stack	*stack;

	append_to_stack(421, &stack);
	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	append_to_stack(421, &stack);
	append_to_stack(481, &stack);
	append_to_stack(-2573, &stack);
	append_to_stack(8979462, &stack);
	append_to_stack(48521, &stack);
	append_to_stack(491, &stack);
	append_to_stack(-2753, &stack);
	append_to_stack(289762, &stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_input_validation, multi_string_)
{
}

Test(sh_input_validation, multi_string_)
{
}

Test(sh_input_validation, multi_string_)
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

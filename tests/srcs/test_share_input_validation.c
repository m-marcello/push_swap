/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_input_validation.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 17:10:41 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 15:41:13 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "share.h"

static int	check_for_duplicates(t_stack **stack)
{
	t_clist	*walk_1;
	t_clist	*walk_2;

	walk_1 = (*stack)->head;
	while (walk_1->next != (*stack)->head)
	{
		walk_2 = walk_1->next;
		while (walk_2 != (*stack)->head)
		{
			if (walk_1->data == walk_2->data)
				return (0);
			walk_2 = walk_2->next;
		}
		walk_1 = walk_1->next;
	}
	return (1);
}

static int	create_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (*stack == 0)
		return (0);
	(*stack)->head = 0;
	(*stack)->trunk = 0;
	(*stack)->node_count = 0;
	return (1);
}

Test(sh_input_validation, one_string_valid1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "0";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_valid2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "0 -4 572 168 +19635";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_valid3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "8462     -379 39480    379 1   0";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_valid4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "9277893 -1728 1666 16 3 -808 0     ";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_valid5)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "+8462     -379 39480    47900 1   0";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_valid6)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-3 6 2345 -0";
	cr_expect(is_valid_input(1, &input, stack_a) == 1 , "one string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "2147483647";
	cr_assert(is_valid_input(1, &input, stack_a) == 1 , "int_max input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-2147483648";
	cr_assert(is_valid_input(1, &input, stack_a) == 1 , "int_min input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "2147483648";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "input > int_max should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-2147483649";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "input < int_min should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits5)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "2147483648973";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "input > int_max should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_int_limits6)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-978922147483649";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "input < int_min should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_dup1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "0 0 3792 2289";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_dup2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "08179 0 3792 3792 2289";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_dup3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "782791 3792 2289 2289";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_dup4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-8979 1234 797 1234 9 -1234 797";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_beg1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-hdk4";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input beginning with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_beg2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "\n -332245 3 5 6 -3446 0";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input beginning with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_mid1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "78 1107 - -107";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_mid2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "2\t107";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_mid3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "2-0792";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_end1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "0 -1 2 -3 4 5fhd";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_end2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "97891-";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, one_string_non_num_char_end3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	*input = "-1\n";
	cr_assert(is_valid_input(1, &input, stack_a) == 0 , "one string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 2);
	input[0] = "1";
	input[1] = "-279";
	cr_assert(is_valid_input(2, input, stack_a) == 1 , "multi string input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "+9789";
	input[1] = "000972";
	input[2] = "-29797 797";
	input[3] = "808";
	cr_assert(is_valid_input(4, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "+9789  000972";
	input[1] = "-29797";
	input[2] = "797";
	input[3] = "808";
	cr_assert(is_valid_input(4, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "+9789";
	input[1] = "000972";
	input[2] = "-29797 797  808";
	cr_assert(is_valid_input(3, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid5)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "9";
	input[1] = "-8";
	input[2] = "73 ";
	input[3] = "0";
	cr_assert(is_valid_input(4, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid6)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 2);
	input[0] = "0";
	input[1] = "  +79";
	cr_assert(is_valid_input(2, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_valid7)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "0";
	input[1] = "79";
	input[2] = "-979268   ";
	cr_assert(is_valid_input(3, input, stack_a) == 1 , "multi string input with extra spaces should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_empty1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "";
	input[1] = "";
	input[2] = "";
	input[3] = "";
	input[4] = "";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "empty string input should be invalid");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_empty2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 2);
	input[0] = " ";
	input[1] = "1";
	cr_assert(is_valid_input(2, input, stack_a) == 0 , "empty string input should be invalid");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_empty3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "";
	input[1] = "2974";
	input[2] = "972";
	input[3] = "1";
	input[4] = "0";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "empty string input should be invalid");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_empty4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "1866";
	input[1] = "79";
	input[2] = "";
	input[3] = "0279";
	input[4] = "270";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "empty string input should be invalid");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_empty5)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 2);
	input[0] = "0";
	input[1] = "";
	cr_assert(is_valid_input(2, input, stack_a) == 0 , "empty string input should be invalid");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "7839";
	input[1] = "2147483647";
	input[2] = "-97792";
	cr_assert(is_valid_input(3, input, stack_a) == 1 , "int_max input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "-2147483648";
	input[1] = "080810870";
	input[2] = "-89";
	cr_assert(is_valid_input(3, input, stack_a) == 1 , "int_min input should be valid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "8786";
	input[1] = "2147483648";
	input[2] = "-87879";
	input[3] = "876278267";
	cr_assert(is_valid_input(4, input, stack_a) == 0 , "input > int_max should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "-2147483649";
	input[1] = "762146";
	input[2] = "0";
	cr_assert(is_valid_input(3, input, stack_a) == 0 , "input < int_min should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits5)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "9";
	input[1] = "99";
	input[2] = "71";
	input[3] = "2147483648973";
	input[4] = "90274";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "input > int_max should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_int_limits6)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "0";
	input[1] = "8";
	input[2] = "-978922147483649";
	cr_assert(is_valid_input(3, input, stack_a) == 0 , "input < int_min should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_beg1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "0";
	input[1] = "0";
	input[2] = "3792";
	input[3] = "2289";
	cr_assert(is_valid_input(4, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_beg2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "3792";
	input[1] = "08179";
	input[2] = "0";
	input[3] = "3792";
	input[4] = "2289";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_beg3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 2);
	input[0] = "2289";
	input[1] = "2289";
	cr_assert(is_valid_input(2, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_beg4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 7);
	input[0] = "1234";
	input[1] = "-8979";
	input[2] = "797";
	input[3] = "9";
	input[4] = "-1234";
	input[5] = "797";
	input[6] = "1234";
	cr_assert(is_valid_input(7, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_mid1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "3792";
	input[1] = "0";
	input[2] = "0";
	input[3] = "2289";
	cr_assert(is_valid_input(4, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}
Test(sh_input_validation, multi_string_dup_mid2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "08179";
	input[1] = "3792";
	input[2] = "0";
	input[3] = "3792";
	input[4] = "2289";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}
Test(sh_input_validation, multi_string_dup_mid3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 7);
	input[0] = "-8979";
	input[1] = "1234";
	input[2] = "797";
	input[3] = "9";
	input[4] = "-1234";
	input[5] = "1234";
	input[6] = "7957";
	cr_assert(is_valid_input(7, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_end1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "0";
	input[1] = "3792";
	input[2] = "2289";
	input[3] = "2289";
	cr_assert(is_valid_input(4, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_end2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "08179";
	input[1] = "0";
	input[2] = "3792";
	input[3] = "2289";
	input[4] = "3792";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_end3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 4);
	input[0] = "782791";
	input[1] = "3792";
	input[2] = "2289";
	input[3] = "2289";
	cr_assert(is_valid_input(4, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_dup_end4)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 7);
	input[0] = "-8979";
	input[1] = "1234";
	input[2] = "797";
	input[3] = "1234";
	input[4] = "9";
	input[5] = "-1234";
	input[6] = "797";
	cr_assert(is_valid_input(7, input, stack_a) == 0 , "multi string input containing duplicate arguments should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_beg1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 7);
	input[0] = "laj6";
	input[1] = "792";
	input[2] = "7892";
	input[3] = "-72";
	input[4] = "-729";
	input[5] = "624";
	input[6] = "12";
	cr_assert(is_valid_input(7, input, stack_a) == 0 , "multi string input beginning with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_beg2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "\t";
	input[1] = "9279";
	input[2] = "280";
	cr_assert(is_valid_input(3, input, stack_a) == 0 , "multi string input beginning with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_mid1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "783";
	input[1] = "-+24";
	input[2] = "78";
	cr_assert(is_valid_input(3, input, stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_mid2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 7);
	input[0] = "0";
	input[1] = "70179";
	input[2] = "-1681";
	input[3] = "287-979";
	input[4] = "702";
	input[5] = "72";
	input[6] = "-7";
	cr_assert(is_valid_input(7, input, stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_mid3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "8920";
	input[1] = "-";
	input[2] = "20";
	input[3] = "270";
	input[4] = "203";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input with non num charackter in the middle should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_end1)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "7892";
	input[1] = "-2892";
	input[2] = "2";
	input[3] = "-5";
	input[4] = "1-";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_end2)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 3);
	input[0] = "870";
	input[1] = "220";
	input[2] = "720|";
	cr_assert(is_valid_input(3, input, stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_input_validation, multi_string_non_num_char_end3)
{
	t_stack	*stack_a;

	create_stack(&stack_a);
	char	**input = malloc(sizeof(char*) * 5);
	input[0] = "4";
	input[1] = "-5";
	input[2] = "6";
	input[3] = "280";
	input[4] = "80\n";
	cr_assert(is_valid_input(5, input, stack_a) == 0 , "multi string input ending with non num charackter should be invalid.");
	free_stack(&stack_a);
}

Test(sh_check_duplicates, one_node)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(421, stack);
	cr_assert(check_for_duplicates(&stack) == 1, "stack with one node should be valid");
	free_stack(&stack);
}

Test(sh_check_duplicates, two_nodes)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(421, stack);
	append_to_stack(421, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, multi_nodes_beg_beg)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(41, stack);
	append_to_stack(41, stack);
	append_to_stack(-273, stack);
	append_to_stack(28979462, stack);
	append_to_stack(421, stack);
	append_to_stack(481, stack);
	append_to_stack(-2573, stack);
	append_to_stack(8979462, stack);
	append_to_stack(48521, stack);
	append_to_stack(491, stack);
	append_to_stack(-2753, stack);
	append_to_stack(289762, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, multi_nodes_beg_mid)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(421, stack);
	append_to_stack(41, stack);
	append_to_stack(-273, stack);
	append_to_stack(28979462, stack);
	append_to_stack(421, stack);
	append_to_stack(481, stack);
	append_to_stack(-2573, stack);
	append_to_stack(8979462, stack);
	append_to_stack(48521, stack);
	append_to_stack(491, stack);
	append_to_stack(-2753, stack);
	append_to_stack(289762, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, multi_nodes_mid)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(41, stack);
	append_to_stack(-273, stack);
	append_to_stack(28979462, stack);
	append_to_stack(421, stack);
	append_to_stack(481, stack);
	append_to_stack(-2573, stack);
	append_to_stack(8979462, stack);
	append_to_stack(8979462, stack);
	append_to_stack(48521, stack);
	append_to_stack(491, stack);
	append_to_stack(-2753, stack);
	append_to_stack(289762, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, multi_nodes_end_mid)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(41, stack);
	append_to_stack(-273, stack);
	append_to_stack(28979462, stack);
	append_to_stack(421, stack);
	append_to_stack(481, stack);
	append_to_stack(-2573, stack);
	append_to_stack(8979462, stack);
	append_to_stack(48521, stack);
	append_to_stack(491, stack);
	append_to_stack(-2753, stack);
	append_to_stack(289762, stack);
	append_to_stack(289762, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

Test(sh_check_duplicates, multi_nodes_end_end)
{
	t_stack	*stack;

	create_stack(&stack);
	append_to_stack(421, stack);
	append_to_stack(41, stack);
	append_to_stack(-273, stack);
	append_to_stack(28979462, stack);
	append_to_stack(421, stack);
	append_to_stack(481, stack);
	append_to_stack(-2573, stack);
	append_to_stack(8979462, stack);
	append_to_stack(48521, stack);
	append_to_stack(491, stack);
	append_to_stack(-2753, stack);
	append_to_stack(289762, stack);
	cr_assert(check_for_duplicates(&stack) == 0, "stack with duplicates should be invalid");
	free_stack(&stack);
}

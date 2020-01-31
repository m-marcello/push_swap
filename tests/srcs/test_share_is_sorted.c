/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_is_sorted.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:36:24 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 18:07:20 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "share.h"

int		create_stack(t_stack **stack);

Test(sh_is_sorted, sorted_full_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(5, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(6, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(590, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(3356, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(33563, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(111743, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1117545, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(11176546, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_full_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-502432, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-49266, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4846, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-472, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-392, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-373, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-145, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-13, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_full_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-3, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-1, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(0, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(2, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_three)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-56, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(8309572, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_two)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(9, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_one)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-379, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, sorted_empty)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(is_sorted(stack), 1, "incorrect return of full stack");
}

Test(sh_is_sorted, unsorted_full_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(7, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(6, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(590, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(3356, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(33563, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(111743, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1117545, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(11176546, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return of full stack");
}

Test(sh_is_sorted, unsorted_full_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-502432, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-49266, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-484652, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-472, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-392, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-373, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-145, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-13, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return of full stack");
}

Test(sh_is_sorted, unsorted_full_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-3, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-1, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(2, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return of full stack");
}

Test(sh_is_sorted, unsorted_three)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-56, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-8309572, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return of full stack");
}

Test(sh_is_sorted, unsorted_two)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, &stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-9, &stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return of full stack");
}

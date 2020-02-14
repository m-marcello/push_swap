/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_sorting_helpers.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:36:24 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 15:35:05 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "share.h"

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

Test(sh_is_sorted, sorted_full_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(6, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(590, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(3356, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(33563, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(111743, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1117545, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(11176546, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_full_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-502432, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-49266, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4846, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-472, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-392, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-373, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-145, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-13, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_full_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-3, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-1, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(0, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(2, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_three)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-56, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(8309572, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_two)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(9, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_one)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-379, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, sorted_empty)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(is_sorted(stack), 1, "incorrect return sorted stack - first element on top");
	free_stack(&stack);
}

Test(sh_is_sorted, unsorted_full_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(7, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(6, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(590, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(336, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(33563, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1743, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1117545, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(546, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return unsorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, unsorted_full_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-502432, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-49266, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-484652, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-472, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-392, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-373, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-145, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-13, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return unsorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, unsorted_full_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-3, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-1, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-26, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(1, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(2, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return unsorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, unsorted_three)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-56, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-8, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 0, "incorrect return unsorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_full_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(50, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(90, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(10, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(20, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(30, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_full_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-9, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-5882332, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-932112, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-578909, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-94942, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-53789, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-9432, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-5679, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-943, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-564, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-97, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-50, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_full_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(1, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(2, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(3, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(4, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(6, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(7, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(8, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(9, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(10, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(11, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(12, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(13, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(14, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(15, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(16, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(17, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(18, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(19, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(20, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(21, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(22, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(23, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(24, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(25, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(26, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(27, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(28, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(29, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(30, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(31, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(0, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_three_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(9, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(4, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_three_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-54, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-99, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-55, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}
Test(sh_is_sorted, sorta_sorted_three_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-3, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-4, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_two_pos)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(4, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_two_neg)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(-5, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-9, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

Test(sh_is_sorted, sorta_sorted_two_mix)
{
	t_stack	*stack;

	create_stack(&stack);
	cr_assert_eq(append_to_stack(7205, stack), 1, "node should have been appended");
	cr_assert_eq(append_to_stack(-2, stack), 1, "node should have been appended");
	cr_assert_eq(is_sorted(stack), 2, "incorrect return sorta sorted stack");
	free_stack(&stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pu_sw_sorting_helpers.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 16:38:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 17:06:10 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "pu_sw.h"
#include "libft.h"

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

Test(ps_closer_to_median, first_closer)
{
	t_stack *stack;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-10, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, stack), 1, "new node should have been created");
	stack->head->index = 5;
	stack->head->next->index = 15;
	cr_expect_eq(closer_to_median(stack->head, stack->head->next, 16), 1, "first node should be closer to median");
	free_stack(&stack);
}

Test(ps_closer_to_median, second_closer)
{
	t_stack *stack;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-10, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, stack), 1, "new node should have been created");
	stack->head->index = 5;
	stack->head->next->index = 15;
	cr_expect_eq(closer_to_median(stack->head, stack->head->next, 21), 0, "second node should be closer to median");
	free_stack(&stack);
}

Test(ps_closer_to_median, tie)
{
	t_stack *stack;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-10, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, stack), 1, "new node should have been created");
	stack->head->index = 5;
	stack->head->next->index = 15;
	cr_expect_eq(closer_to_median(stack->head, stack->head->next, 20), 0, "function should return 0 when both nodes are in equal distance to median");
	free_stack(&stack);
}

Test(ps_fits_between, it_does_fit_pos)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(fits_between(node, smallest, highest), 1, "node should fit");
	free_stack(&stack);
}

Test(ps_fits_between, it_does_fit_neg)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-77892, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-7289764, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(fits_between(smallest, highest, node), 1, "node should fit");
	free_stack(&stack);
}

Test(ps_fits_between, it_does_fit_mix)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9782, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2443, stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(fits_between(highest, node, smallest), 1, "node should fit");
	free_stack(&stack);
}

Test(ps_fits_between, it_does_not_fit_pos)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(fits_between(node, smallest, highest), 1, "node should fit");
	free_stack(&stack);
}

Test(ps_fits_between, it_does_not_fit_neg)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-77892, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-7289764, stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(fits_between(node, highest, smallest), 0, "node should not fit");
	free_stack(&stack);
}

// unsigned long	get_index(int data, t_stack *stack)
// {
// 	t_clist	*walk;

// 	walk = stack->trunk;
// 	while (walk != 0 && data != walk->data)
// 	{
// 		if (data < walk->data)
// 			walk = walk->left;
// 		else if (data > walk->data)
// 			walk = walk->right;
// 	}
// 	if (walk == 0)
// 		return (0);
// 	return (walk->index);
// }

// Test(ps_fits_between, it_does_not_fit_mix)
// {
// 	t_stack	*stack;
// 	t_clist	*smallest;
// 	t_clist	*highest;
// 	t_clist	*node;

// 	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
// 	cr_assert_eq(append_to_stack(1, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-9782, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(2443, stack), 1, "new node should have been created");
// 	node = stack->head;
// 	smallest = stack->head->next;
// 	highest = stack->head->prev;
// 	cr_assert_eq(fits_between(node, highest, smallest), 0, "node should not fit");
// 	free_stack(&stack);
// }

// Test(ps_get_index, full_pos)
// {
// 	t_stack			*stack;
// 	unsigned long	index;

// 	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
// 	cr_assert_eq(append_to_stack(80, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(23, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(11, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(1, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(2, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(5, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(0, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(202, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(3, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(10, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(6, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(257, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(8, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(9, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(55, stack), 1, "new node should have been created");
// 	tree_sort(stack);

// 	index = get_index(0, stack);
// 	cr_expect_eq(index, 1, "index of 1st item incorrect, index is instead %lu", index);
// 	index = get_index(1, stack);
// 	cr_expect_eq(index, 2, "index of 2nd item incorrect, index is instead %lu", index);
// 	index = get_index(2, stack);
// 	cr_expect_eq(index, 3, "index of 3rd item incorrect, index is instead %lu", index);
// 	index = get_index(3, stack);
// 	cr_expect_eq(index, 4, "index of 4th item incorrect, index is instead %lu", index);
// 	index = get_index(5, stack);
// 	cr_expect_eq(index, 5, "index of 5th item incorrect, index is instead %lu", index);
// 	index = get_index(6, stack);
// 	cr_expect_eq(index, 6, "index of 6th item incorrect, index is instead %lu", index);
// 	index = get_index(8, stack);
// 	cr_expect_eq(index, 7, "index of 7th item incorrect, index is instead %lu", index);
// 	index = get_index(9, stack);
// 	cr_expect_eq(index, 8, "index of 8th item incorrect, index is instead %lu", index);
// 	index = get_index(10, stack);
// 	cr_expect_eq(index, 9, "index of 9th item incorrect, index is instead %lu", index);
// 	index = get_index(11, stack);
// 	cr_expect_eq(index, 10, "index of 10th item incorrect, index is instead %lu", index);
// 	index = get_index(23, stack);
// 	cr_expect_eq(index, 11, "index of 11th item incorrect, index is instead %lu", index);
// 	index = get_index(55, stack);
// 	cr_expect_eq(index, 12, "index of 12th item incorrect, index is instead %lu", index);
// 	index = get_index(80, stack);
// 	cr_expect_eq(index, 13, "index of 13th item incorrect, index is instead %lu", index);
// 	index = get_index(202, stack);
// 	cr_expect_eq(index, 14, "index of 14th item incorrect, index is instead %lu", index);
// 	index = get_index(257, stack);
// 	cr_expect_eq(index, 15, "index of 15th 15tem incorrect, index is instead %lu", index);
// 	free_stack(&stack);
// }

// Test(ps_get_index, full_neg)
// {
// 	t_stack			*stack;
// 	unsigned long	index;

// 	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
// 	cr_assert_eq(append_to_stack(-805267, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-23, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-1143, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-1, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-2, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-55, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-322, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-202, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-3, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-1032, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-6246782, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-257, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-84, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-93244, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-55332, stack), 1, "new node should have been created");
// 	tree_sort(stack);

// 	index = get_index(-6246782, stack);
// 	cr_expect_eq(index, 1, "index of 1st item incorrect, index is instead %lu", index);
// 	index = get_index(-805267, stack);
// 	cr_expect_eq(index, 2, "index of 2nd item incorrect, index is instead %lu", index);
// 	index = get_index(-93244, stack);
// 	cr_expect_eq(index, 3, "index of 3rd item incorrect, index is instead %lu", index);
// 	index = get_index(-55332, stack);
// 	cr_expect_eq(index, 4, "index of 4th item incorrect, index is instead %lu", index);
// 	index = get_index(-1143, stack);
// 	cr_expect_eq(index, 5, "index of 5th item incorrect, index is instead %lu", index);
// 	index = get_index(-1032, stack);
// 	cr_expect_eq(index, 6, "index of 6th item incorrect, index is instead %lu", index);
// 	index = get_index(-322, stack);
// 	cr_expect_eq(index, 7, "index of 7th item incorrect, index is instead %lu", index);
// 	index = get_index(-257, stack);
// 	cr_expect_eq(index, 8, "index of 8th item incorrect, index is instead %lu", index);
// 	index = get_index(-202, stack);
// 	cr_expect_eq(index, 9, "index of 9th item incorrect, index is instead %lu", index);
// 	index = get_index(-84, stack);
// 	cr_expect_eq(index, 10, "index of 10th item incorrect, index is instead %lu", index);
// 	index = get_index(-55, stack);
// 	cr_expect_eq(index, 11, "index of 11th item incorrect, index is instead %lu", index);
// 	index = get_index(-23, stack);
// 	cr_expect_eq(index, 12, "index of 12th item incorrect, index is instead %lu", index);
// 	index = get_index(-3, stack);
// 	cr_expect_eq(index, 13, "index of 13th item incorrect, index is instead %lu", index);
// 	index = get_index(-2, stack);
// 	cr_expect_eq(index, 14, "index of 14th item incorrect, index is instead %lu", index);
// 	index = get_index(-1, stack);
// 	cr_expect_eq(index, 15, "index of 15th 15tem incorrect, index is instead %lu", index);
// 	free_stack(&stack);
// }

// Test(ps_get_index, full_mix)
// {
// 	t_stack			*stack;
// 	unsigned long	index;

// 	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
// 	cr_assert_eq(append_to_stack(-805267, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(23, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(1143, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(0, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-2, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-55, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(322, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-202, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(3075326, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-1032, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-6246782, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(257890, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-84643240, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(93244, stack), 1, "new node should have been created");
// 	cr_assert_eq(append_to_stack(-55332, stack), 1, "new node should have been created");
// 	tree_sort(stack);

// 	index = get_index(-84643240, stack);
// 	cr_expect_eq(index, 1, "index of 1st item incorrect, index is instead %lu", index);
// 	index = get_index(-6246782, stack);
// 	cr_expect_eq(index, 2, "index of 2nd item incorrect, index is instead %lu", index);
// 	index = get_index(-805267, stack);
// 	cr_expect_eq(index, 3, "index of 3rd item incorrect, index is instead %lu", index);
// 	index = get_index(-55332, stack);
// 	cr_expect_eq(index, 4, "index of 4th item incorrect, index is instead %lu", index);
// 	index = get_index(-1032, stack);
// 	cr_expect_eq(index, 5, "index of 5th item incorrect, index is instead %lu", index);
// 	index = get_index(-202, stack);
// 	cr_expect_eq(index, 6, "index of 6th item incorrect, index is instead %lu", index);
// 	index = get_index(-55, stack);
// 	cr_expect_eq(index, 7, "index of 7th item incorrect, index is instead %lu", index);
// 	index = get_index(-2, stack);
// 	cr_expect_eq(index, 8, "index of 8th item incorrect, index is instead %lu", index);
// 	index = get_index(0, stack);
// 	cr_expect_eq(index, 9, "index of 9th item incorrect, index is instead %lu", index);
// 	index = get_index(23, stack);
// 	cr_expect_eq(index, 10, "index of 10th item incorrect, index is instead %lu", index);
// 	index = get_index(322, stack);
// 	cr_expect_eq(index, 11, "index of 11th item incorrect, index is instead %lu", index);
// 	index = get_index(1143, stack);
// 	cr_expect_eq(index, 12, "index of 12th item incorrect, index is instead %lu", index);
// 	index = get_index(93244, stack);
// 	cr_expect_eq(index, 13, "index of 13th item incorrect, index is instead %lu", index);
// 	index = get_index(257890, stack);
// 	cr_expect_eq(index, 14, "index of 14th item incorrect, index is instead %lu", index);
// 	index = get_index(3075326, stack);
// 	cr_expect_eq(index, 15, "index of 15th 15tem incorrect, index is instead %lu", index);
// 	free_stack(&stack);
// }

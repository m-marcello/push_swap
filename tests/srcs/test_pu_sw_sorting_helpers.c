/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pu_sw_sorting_helpers.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 16:38:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 17:07:49 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "pu_sw.h"

int		create_stack(t_stack **stack);

Test(pu_sw_does_it_fit, it_does_fit_pos)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(node, smallest, highest), 1, "node should fit");
}

Test(pu_sw_does_it_fit, it_does_fit_neg)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-77892, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-7289764, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(node, smallest, highest), 1, "node should fit");
}

Test(pu_sw_does_it_fit, it_does_fit_mix)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9782, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2443, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(node, smallest, highest), 1, "node should fit");
}

Test(pu_sw_does_it_fit, it_does_not_fit_pos)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(smallest, node, highest), 0, "node should not fit");
}

Test(pu_sw_does_it_fit, it_does_not_fit_neg)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-77892, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-7289764, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(highest, node, smallest), 0, "node should not fit");
}

Test(pu_sw_does_it_fit, it_does_not_fit_mix)
{
	t_stack	*stack;
	t_clist	*smallest;
	t_clist	*highest;
	t_clist	*node;

	cr_assert_eq(create_stack(&stack), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9782, &stack), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2443, &stack), 1, "new node should have been created");
	node = stack->head;
	smallest = stack->head->next;
	highest = stack->head->prev;
	cr_assert_eq(does_it_fit(node, highest, smallest), 0, "node should not fit");
}

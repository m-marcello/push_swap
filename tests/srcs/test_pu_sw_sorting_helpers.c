/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pu_sw_sorting_helpers.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 16:38:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 20:39:53 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "pu_sw.h"
#include "libft.h"

int		create_stack(t_stack **stack);

Test(ps_does_it_fit, it_does_fit_pos)
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

Test(ps_does_it_fit, it_does_fit_neg)
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

Test(ps_does_it_fit, it_does_fit_mix)
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

Test(ps_does_it_fit, it_does_not_fit_pos)
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

Test(ps_does_it_fit, it_does_not_fit_neg)
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

Test(ps_does_it_fit, it_does_not_fit_mix)
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

Test(ps_post_sort, full_sorted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(8, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_ra_pos)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(8, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	ft_putendl("2x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_rra_pos)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(8, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(20, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(30, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(40, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(50, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(60, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	ft_putendl("1x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_ra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-254, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-114, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-83, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-12344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2557, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	ft_putendl("4x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_rra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-254, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-114, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-83, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-12344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2557, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	ft_putendl("4x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_sorted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_ra_pos)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	ft_putendl("1x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_rra_pos)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(20, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	ft_putendl("1x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_ra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	ft_putendl("1x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_rra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-12344, &stack_a), 1, "new node should have been created");
	ft_putendl("2x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_sorted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_ra_mix)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	ft_putendl("1x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_rra_pos)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(20, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	ft_putendl("1x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_ra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	ft_putendl("1x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_rra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	ft_putendl("1x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_rra_neg)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	ft_putendl("1x ra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_rra_mix)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	ft_putendl("1x rra:");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_sorted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, one_sorted)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

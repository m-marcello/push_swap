/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pu_sw_sorting_helpers.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 16:38:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/03 18:58:40 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <criterion/redirect.h>
#include "pu_sw.h"
#include "libft.h"

int		create_stack(t_stack **stack);

void	redirect_all_stdout(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(ps_fits_between, it_does_fit_pos)
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
	cr_assert_eq(fits_between(node, smallest, highest), 1, "node should fit");
}

Test(ps_fits_between, it_does_fit_neg)
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
	cr_assert_eq(fits_between(node, smallest, highest), 1, "node should fit");
}

Test(ps_fits_between, it_does_fit_mix)
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
	cr_assert_eq(fits_between(node, smallest, highest), 1, "node should fit");
}

Test(ps_fits_between, it_does_not_fit_pos)
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
	cr_assert_eq(fits_between(smallest, node, highest), 0, "node should not fit");
}

Test(ps_fits_between, it_does_not_fit_neg)
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
	cr_assert_eq(fits_between(highest, node, smallest), 0, "node should not fit");
}

Test(ps_fits_between, it_does_not_fit_mix)
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
	cr_assert_eq(fits_between(node, highest, smallest), 0, "node should not fit");
}

Test(ps_post_sort, full_sorted, .init=redirect_all_stdout)
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
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_ra_pos, .init=redirect_all_stdout)
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
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\nra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_rra_pos, .init=redirect_all_stdout)
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
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_ra_neg, .init=redirect_all_stdout)
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
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\nra\nra\nra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, full_rra_neg, .init=redirect_all_stdout)
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
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\nrra\nrra\nrra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_sorted, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	// cr_expect_stdout_empty("");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_ra_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_rra_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(20, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_ra_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2533, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, four_rra_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-12344, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\nrra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_sorted, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_ra_mix, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_rra_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(20, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_ra_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, three_rra_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-14325, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_rra_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-99827, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_rra_mix, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, two_sorted, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

Test(ps_post_sort, one_sorted, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-38, &stack_a), 1, "new node should have been created");
	post_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted with the smallest item on top");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(ps_pre_sort, full_sorted_stage_1_pos/* , .init=redirect_all_stdout */)
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
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(11, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(12, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(14, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, full_sorted_stage_1_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-20739365, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2873962, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1873911, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-197390, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-187319, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-78763, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-6876, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-5587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-358, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, full_sorted_stage_1_mix/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-20739365, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2873962, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1873911, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-197390, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-187319, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-78763, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-6876, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-5587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-358, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(8, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(11, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(12, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(14, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, three_sorted_stage_1_pos/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, three_sorted_stage_1_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, three_sorted_stage_1_mix/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, two_sorted_stage_1_pos/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, two_sorted_stage_1_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

Test(ps_pre_sort, two_sorted_stage_1_mix/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should have remained sorted with the smallest item on top");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(ps_pre_sort, full_sorted_stage_2_pos/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(4, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(6, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(7, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(8, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(11, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(12, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(14, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, full_sorted_stage_2_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-20739365, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2873962, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1873911, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-197390, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-187319, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-78763, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-6876, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-5587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-358, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, full_sorted_stage_2_mix/* , .init=redirect_all_stdout */)
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
	cr_assert_eq(append_to_stack(10, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(11, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(12, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(14, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-20739365, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2873962, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1873911, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-197390, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-187319, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-78763, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-6876, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-5587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-4587, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-358, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, three_sorted_stage_2_pos/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, three_sorted_stage_2_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, three_sorted_stage_2_mix/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(0, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, two_sorted_stage_2_pos/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(13, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, two_sorted_stage_2_neg/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-88731, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18739344, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

Test(ps_pre_sort, two_sorted_stage_2_mix/* , .init=redirect_all_stdout */)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(15, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3973983, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	// cr_assert_stdout_eq_str("", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should have remained sorted in stage 2");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(ps_pre_sort, full_unsorted_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(501, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(500, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(18, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\npb\nrra\npb\nrra\npb\nrra\npb\nrra\npb\nrra\npb\nrra\npb\nsa\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, full_unsorted_mix, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(18, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-500, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(501, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("pb\npb\nra\npb\npb\npb\npb\nra\npb\nss\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, full_unsorted_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-18, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-25, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-500, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-50, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-19, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-3, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-501, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\npb\nsa\npb\nsa\npb\nss\npb\nss\npb\nrra\npb\nrra\npb\nrra\npb\nrra\npb\nss\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, four_unsorted_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(501, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(9, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("rra\npb\nsa\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, four_unsorted_mix, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(501, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\npb\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, four_unsorted_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-18, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-50, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-2, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("ra\npb\nsa\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, three_unsorted_pos, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(18, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(5, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(1, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("sa\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, three_unsorted_mix, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-35, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-500, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(2, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("sa\n", "");
	cr_assert_eq(is_sorted(stack_a), 1, "stack a should be sorted in stage 2");
}

Test(ps_pre_sort, three_unsorted_neg, .init=redirect_all_stdout)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	cr_assert_eq(create_both_stacks(&stack_a, &stack_b), 1, "stack should have been created");
	cr_assert_eq(append_to_stack(-19, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-50, &stack_a), 1, "new node should have been created");
	cr_assert_eq(append_to_stack(-501, &stack_a), 1, "new node should have been created");
	pre_sort(0, stack_a, stack_b);
	cr_assert_stdout_eq_str("sa\n", "");
	cr_assert_eq(is_sorted(stack_a), 2, "stack a should be sorted in stage 2");
}

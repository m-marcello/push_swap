/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_create_append_free.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:55:12 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/14 19:00:17 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_stack_create_append, create_first_node_valid_pos)
{
	t_clist	*stack_1;
	t_clist	*stack_2;

	cr_assert(append_to_stack(5, &stack_1) == 1, "first node should have been created");
	cr_assert(stack_1->next == stack_1, "first node incorrect");
	cr_assert(stack_1->prev == stack_1, "first node incorrect");
	cr_assert(stack_1->data == 5, "first node incorrect");
	cr_assert(append_to_stack(0, &stack_2) == 1, "first node should have been created");
	cr_assert(stack_2->next == stack_2, "first node incorrect");
	cr_assert(stack_2->prev == stack_2, "first node incorrect");
	cr_assert(stack_2->data == 0, "first node incorrect");
	free_stack(stack_1);
	free_stack(stack_2);
}

Test(sh_stack_create_append, create_first_node_valid_neg)
{
	t_clist	*stack_1;
	t_clist	*stack_2;

	cr_assert(append_to_stack(-9792, &stack_1) == 1, "first node should have been created");
	cr_assert(stack_1->next == stack_1, "first node incorrect");
	cr_assert(stack_1->prev == stack_1, "first node incorrect");
	cr_assert(stack_1->data == -9792, "first node incorrect");
	cr_assert(append_to_stack(-2147483648, &stack_2) == 1, "first node should have been created");
	cr_assert(stack_2->next == stack_2, "first node incorrect");
	cr_assert(stack_2->prev == stack_2, "first node incorrect");
	cr_assert(stack_2->data == -2147483648, "first node incorrect");
	free_stack(stack_1);
	free_stack(stack_2);
}

Test(sh_stack_create_append, append_second_node_valid_pos)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, append_second_node_valid_neg)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, append_valid)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_empty)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
}



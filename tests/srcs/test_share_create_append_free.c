/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_create_append_free.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:55:12 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/15 15:56:53 by mmarcell      ########   odam.nl         */
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
	t_clist	*head_1;
	t_clist	*head_2;

	cr_assert(append_to_stack(5, &head_1) == 1, "first node should have been created");
	cr_assert(head_1->next == head_1, "first node incorrect");
	cr_assert(head_1->prev == head_1, "first node incorrect");
	cr_assert(head_1->data == 5, "first node incorrect");
	cr_assert(append_to_stack(0, &head_2) == 1, "first node should have been created");
	cr_assert(head_2->next == head_2, "first node incorrect");
	cr_assert(head_2->prev == head_2, "first node incorrect");
	cr_assert(head_2->data == 0, "first node incorrect");
	free_stack(head_1);
	free_stack(head_2);
}

Test(sh_stack_create_append, create_1_node_valid_neg)
{
	t_clist	*head_1;
	t_clist	*head_2;

	cr_assert(append_to_stack(-9792, &head_1) == 1, "first node should have been created");
	cr_assert(head_1->next == head_1, "first node incorrect");
	cr_assert(head_1->prev == head_1, "first node incorrect");
	cr_assert(head_1->data == -9792, "first node incorrect");
	cr_assert(append_to_stack(-2147483648, &head_2) == 1, "first node should have been created");
	cr_assert(head_2->next == head_2, "first node incorrect");
	cr_assert(head_2->prev == head_2, "first node incorrect");
	cr_assert(head_2->data == -2147483648, "first node incorrect");
	free_stack(head_1);
	free_stack(head_2);
}

Test(sh_stack_create_append, append_2_node_valid)
{
	t_clist	*head;

	cr_assert(append_to_stack(0, &head) == 1,  "first node should have been created");
	cr_assert(append_to_stack(-16782, &head) == 1,  "second node should have been created");
	cr_assert(head->next->next == head, "second node incorrect");
	cr_assert(head->prev->prev == head, "second node incorrect");
	free_stack(head);
}

Test(sh_stack_create_append, append_3_node_valid)
{
	t_clist	*head;

	cr_assert(append_to_stack(4, &head) == 1,  "first node should have been created");
	cr_assert(append_to_stack(3, &head) == 1,  "second node should have been created");
	cr_assert(append_to_stack(2, &head) == 1,  "third node should have been created");
	cr_assert(head->next == head->prev->prev, "second node incorrect");
	cr_assert(head->next->data == head->prev->prev->data, "second node incorrect");
	cr_assert(head->next == head->prev->prev, "second node incorrect");
	cr_assert(head->next->data == head->prev->prev->data, "second node incorrect");
	cr_assert(head->prev->prev->prev == head, "linking nodes incorrect");
	free_stack(head);
}

Test(sh_stack_create_append, append_4_node_valid)
{
	t_clist	*head;

	cr_assert(append_to_stack(3792, &head) == 1,  "first node should have been created");
	cr_assert(append_to_stack(-36782, &head) == 1,  "second node should have been created");
	cr_assert(append_to_stack(2, &head) == 1,  "third node should have been created");
	cr_assert(append_to_stack(0, &head) == 1,  "fourth node should have been created");
	cr_assert(head->next->next == head->prev->prev, "second node incorrect");
	cr_assert(head->next->next->next == head->prev, "third node incorrect");
	cr_assert(head->next->next->next->next == head, "linking nodes incorrect");
	free_stack(head);
}

Test(sh_stack_free, append_valid)
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



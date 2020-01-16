/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_create_append_free.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:55:12 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/16 18:47:13 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_stack_free, free_1_node, .signal = SIGSEGV)
{
	t_clist	*head;
	t_stack	*stack;

	append_to_stack(0, &stack);
	head = stack->head;
	free_stack(&stack);
	head->data = 42;
}

Test(sh_stack_free, free_2_nodes, .signal = SIGSEGV)
{
	t_clist	*head;
	t_clist	*node_2;
	t_stack	*stack;

	append_to_stack(-1782, &stack);
	append_to_stack(3892, &stack);
	head = stack->head;
	node_2 = head->next;
	free_stack(&stack);
	head->prev = 42;
}

Test(sh_stack_free, free_3_nodes, .signal = SIGSEGV)
{
	t_clist	*head;
	t_clist	*node_3;
	t_stack	*stack;

	append_to_stack(0, &stack);
	append_to_stack(1, &stack);
	append_to_stack(2, &stack);
	head = stack->head;
	node_3 = head->next->next;
	free_stack(&stack);
	head->next->next->data = 42;
}

Test(sh_stack_free, free_4_nodes, .signal = SIGSEGV)
{
	t_clist	*head;
	t_stack	*stack;
	t_clist	*node_4;

	append_to_stack(421, &stack);
	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	head = stack->head;
	node_4 = head->prev;
	free_stack(&stack);
	head->next->next->next->next->data = 42;
}

Test(sh_stack_create_append, create_first_node_valid_pos)
{
	t_clist	*head_1;
	t_clist	*head_2;
	t_stack	*stack_1;
	t_stack	*stack_2;

	cr_assert(append_to_stack(5, &stack_1) == 1, "first node should have been created");
	head_1 = stack_1->head;
	cr_assert(head_1->next == head_1, "first node incorrect");
	cr_assert(head_1->prev == head_1, "first node incorrect");
	cr_assert(head_1->data == 5, "first node incorrect");
	cr_assert(append_to_stack(0, &stack_2) == 1, "first node should have been created");
	cr_assert(head_2->next == head_2, "first node incorrect");
	head_2 = stack_2->head;
	cr_assert(head_2->prev == head_2, "first node incorrect");
	cr_assert(head_2->data == 0, "first node incorrect");
	free_stack(&stack_1);
	free_stack(&stack_2);
}

Test(sh_stack_create_append, create_1_node_valid_neg)
{
	t_clist	*head_1;
	t_clist	*head_2;
	t_stack	*stack_1;
	t_stack	*stack_2;

	cr_assert(append_to_stack(-9792, &stack_1) == 1, "first node should have been created");
	head_1 = stack_1->head;
	cr_assert(head_1->next == head_1, "first node incorrect");
	cr_assert(head_1->prev == head_1, "first node incorrect");
	cr_assert(head_1->data == -9792, "first node incorrect");
	cr_assert(append_to_stack(-2147483648, &stack_2) == 1, "first node should have been created");
	head_2 = stack_2->head;
	cr_assert(head_2->next == head_2, "first node incorrect");
	cr_assert(head_2->prev == head_2, "first node incorrect");
	cr_assert(head_2->data == -2147483648, "first node incorrect");
	free_stack(&stack_1);
	free_stack(&stack_2);
}

Test(sh_stack_create_append, append_2_node_valid)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(0, &stack) == 1,  "first node should have been created");
	cr_assert(append_to_stack(-16782, &stack) == 1,  "second node should have been created");
	cr_assert(head->next->next == head, "second node incorrect");
	cr_assert(head->prev->prev == head, "second node incorrect");
	cr_assert(head->data == 0, "first node incorrect");
	cr_assert(head->next->data == -16782, "second node incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, append_3_node_valid)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(4, &stack) == 1,  "first node should have been created");
	head = stack->head;
	cr_assert(append_to_stack(3, &stack) == 1,  "second node should have been created");
	cr_assert(append_to_stack(2, &stack) == 1,  "third node should have been created");
	cr_assert(head->data == 4, "first node incorrect");
	cr_assert(head->next == head->prev->prev->prev, "second node incorrect");
	cr_assert(head->next->data == head->prev->prev->prev->data, "second node incorrect");
	cr_assert(head->next->data == 3, "second node incorrect");
	cr_assert(head->next->next == head->prev->prev, "third node incorrect");
	cr_assert(head->next->next->data == head->prev->prev->data, "third node incorrect");
	cr_assert(head->next->next->data == 2, "third node incorrect");
	cr_assert(head->prev->prev->prev == head, "linking nodes incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, append_4_node_valid)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(3792, &stack) == 1,  "first node should have been created");
	cr_assert(append_to_stack(-36782, &stack) == 1,  "second node should have been created");
	head = stack->head;
	cr_assert(append_to_stack(2, &stack) == 1,  "third node should have been created");
	cr_assert(append_to_stack(0, &stack) == 1,  "fourth node should have been created");
	cr_assert(head->next->next == head->prev->prev->prev, "second node incorrect");
	cr_assert(head->next->next->next == head->prev->prev, "third node incorrect");
	cr_assert(head->next->next->next->next == head, "linking nodes incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
	head = stack->head;
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
	head = stack->head;
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*head;
	t_stack	*stack;

	cr_assert(append_to_stack(0, &stack) == 1, "");
	head = stack->head;
}



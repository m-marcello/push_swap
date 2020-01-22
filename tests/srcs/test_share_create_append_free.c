/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_create_append_free.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:55:12 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/22 21:37:19 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_stack_free, free_node, .signal = SIGSEGV)
{
	t_stack	*stack = 0;

	create_stack(&stack);
	append_to_stack(0, &stack);
	free_stack(&stack);
	stack->head->data = 42;
}

Test(sh_stack_free, free_2_nodes, .signal = SIGSEGV)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	create_stack(&stack);
	append_to_stack(-1782, &stack);
	append_to_stack(3892, &stack);
	head = stack->head;
	free_stack(&stack);
	head->prev->data = 42;
}

Test(sh_stack_free, free_3_nodes, .signal = SIGSEGV)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	append_to_stack(0, &stack);
	append_to_stack(1, &stack);
	append_to_stack(2, &stack);
	head = stack->head;
	free_stack(&stack);
	head->next->next->data = 42;
}

Test(sh_stack_free, free_4_nodes, .signal = SIGSEGV)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	create_stack(&stack);
	append_to_stack(421, &stack);
	append_to_stack(41, &stack);
	append_to_stack(-273, &stack);
	append_to_stack(28979462, &stack);
	head = stack->head;
	free_stack(&stack);
	head->next->next->next->next->data = 42;
}

Test(sh_str_arr_free, free_arr_one_item1, .signal = SIGSEGV)
{
	char	**str_arr = ft_strsplit("1", ' ');
	free_str_arr(&str_arr);
	str_arr[0][0] = '4';
}

Test(sh_str_arr_free, free_arr_two_items, .signal = SIGSEGV)
{
	char	**str_arr = ft_strsplit("1 2", ' ');
	free_str_arr(&str_arr);
	str_arr[1][0] = '0';
}

Test(sh_stack_create_append, create_first_node_valid_pos)
{
	t_clist	*head;
	t_stack	*stack;

	create_stack(&stack);
	cr_assert(append_to_stack(5, &stack) == 1, "first node should have been created");
	head = stack->head;
	cr_assert(head->next == head, "first node incorrect");
	cr_assert(head->prev == head, "first node incorrect");
	cr_assert(head->data == 5, "first node incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, create_first_node_valid_zero)
{
	t_clist	*head;
	t_stack	*stack;

	create_stack(&stack);
	cr_assert(append_to_stack(0, &stack) == 1, "first node should have been created");
	head = stack->head;
	cr_assert(head->next == head, "first node incorrect");
	cr_assert(head->prev == head, "first node incorrect");
	cr_assert(head->data == 0, "first node incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, create_first_node_valid_neg)
{
	t_clist	*head;
	t_stack	*stack;

	create_stack(&stack);
	cr_assert(append_to_stack(-9792, &stack) == 1, "first node should have been created");
	head = stack->head;
	cr_assert(head->next == head, "first node incorrect");
	cr_assert(head->prev == head, "first node incorrect");
	cr_assert(head->data == -9792, "first node incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, append_2_node_valid)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	create_stack(&stack);
	cr_assert(append_to_stack(0, &stack) == 1,  "first node should have been created");
	head = stack->head;
	cr_assert(append_to_stack(-16782, &stack) == 1,  "second node should have been created");
	cr_assert(head->next->next == head, "second node incorrect");
	cr_assert(head->prev->prev == head, "second node incorrect");
	cr_assert(head->data == 0, "first node incorrect");
	cr_assert(head->next->data == -16782, "second node incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, append_3_node_valid)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	create_stack(&stack);
	cr_assert(append_to_stack(4, &stack) == 1,  "first node should have been created");
	head = stack->head;
	cr_assert(append_to_stack(3, &stack) == 1,  "second node should have been created");
	cr_assert(append_to_stack(2, &stack) == 1,  "third node should have been created");
	cr_assert(head->data == 4, "first node incorrect");
	cr_assert(head->next == head->prev->prev, "second node incorrect");
	cr_assert(head->next->data == head->prev->prev->data, "second node incorrect");
	cr_assert(head->next->data == 3, "second node incorrect");
	cr_assert(head->next->next == head->prev, "third node incorrect");
	cr_assert(head->next->next->data == head->prev->data, "third node incorrect");
	cr_assert(head->next->next->data == 2, "third node incorrect");
	cr_assert(head->next->next->next->data == 4, "circle not linked correctly");
	cr_assert(head->prev->prev->prev == head, "linking nodes incorrect");
	free_stack(&stack);
}

Test(sh_stack_create_append, append_4_node_valid)
{
	t_clist	*head = 0;
	t_stack	*stack = 0;

	create_stack(&stack);
	cr_assert(append_to_stack(3792, &stack) == 1,  "first node should have been created");
	cr_assert(append_to_stack(-36782, &stack) == 1,  "second node should have been created");
	cr_assert(append_to_stack(2, &stack) == 1,  "third node should have been created");
	cr_assert(append_to_stack(0, &stack) == 1,  "fourth node should have been created");
	head = stack->head;
	cr_assert(head->prev->data == 0, "fourth node incorrect");
	cr_assert(head->prev->prev->data == 2, "third node incorrect");
	cr_assert(head->prev->prev->prev->data == -36782, "second node incorrect");
	cr_assert(head->prev->prev->prev->prev->data == 3792, "circle not linked correctly");
	cr_assert(head->prev->prev->prev->prev->prev->data == 0, "fourth node incorrect");

	cr_assert(head->next->data == head->prev->prev->prev->data, "second node incorrect");
	cr_assert(head->next->next == head->prev->prev, "third node incorrect");
	cr_assert(head->next->next->next == head->prev, "fourth node incorrect");
	cr_assert(head->next->next->next->next == head, "linking nodes incorrect");
	free_stack(&stack);
}

// Test(sh_stack_create_append, multi_nodes_)
// {
// 	t_clist	*head = 0;
// 	t_stack	*stack = 0;

// 	create_stack(&stack);
// 	cr_assert(append_to_stack(0, &stack) == 1, "");
// 	head = stack->head;
// }

// Test(sh_stack_create_append, multi_nodes_)
// {
// 	t_clist	*head = 0;
// 	t_stack	*stack = 0;

// 	create_stack(&stack);
// 	cr_assert(append_to_stack(0, &stack) == 1, "");
// 	head = stack->head;
// }

// Test(sh_stack_create_append, multi_nodes_)
// {
// 	t_clist	*head = 0;
// 	t_stack	*stack = 0;

// 	create_stack(&stack);
// 	cr_assert(append_to_stack(0, &stack) == 1, "");
// 	head = stack->head;
// }



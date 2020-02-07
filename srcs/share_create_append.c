/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_create_append.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 14:25:06 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/07 15:45:24 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** creates and initializes the struct that holds the head of the stack and
** the numbers of nodes in the stack
**
** params
**	t_stack **stack	address of the struct
** return
**	1				when everything went fine
**	0				in case of error
*/
// make create_stack static again

int			create_stack(t_stack **stack)
{
	*stack = malloc(sizeof(t_stack));
	if (*stack == 0)
		return (0);
	(*stack)->head = 0;
	(*stack)->trunk = 0;
	(*stack)->node_count = 0;
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** function to create both stacks and catches potential errors in malloc
**
** params
**	t_stack **stack_a	address of the struct for stack a
**	t_stack **stack_b	address of the struct for stack b
** return
**	1				when everything went fine
**	0				in case of error
*/

int			create_both_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = 0;
	*stack_b = 0;
	create_stack(stack_a);
	if (*stack_a == 0)
		return (0);
	create_stack(stack_b);
	if (*stack_b == 0)
	{
		free_stack(stack_a);
		return (0);
	}
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** creates one node of t_clist and initializes it
**
** params
**	t_clist **node	addres to node that needs to be crated
**	int data		integer item of the stack for this node
** return
**	1				when everything went fine
**	0				in case of error
*/

static int	create_node(t_clist **node, int data)
{
	*node = malloc(sizeof(t_clist));
	if (*node == 0)
		return (0);
	(*node)->data = data;
	(*node)->next = (*node);
	(*node)->prev = (*node);
	(*node)->left = 0;
	(*node)->right = 0;
	(*node)->parent = 0;
	(*node)->index = 0;
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** appends the entries from an array of strings to the stack
** if there is no stack yet it will be created
**
** params
**	int data		data for the node to be appended to stack
**	t_stack **stack	pointer to struct representing stack
** return
**	1				when everthing went fine
**	0				in case of error
*/

int			append_to_stack(int data, t_stack **stack)
{
	t_clist	*new_node;

	if (create_node(&new_node, data) == 0)
		return (0);
	if ((*stack)->node_count == 0)
		(*stack)->head = new_node;
	else if ((*stack)->node_count == 1)
	{
		(*stack)->head->next = new_node;
		(*stack)->head->prev = new_node;
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->head;
	}
	else
	{
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->head->prev;
		(*stack)->head->prev->next = new_node;
		(*stack)->head->prev = new_node;
	}
	(*stack)->node_count++;
	return (1);
}

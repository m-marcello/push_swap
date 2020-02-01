/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_operations_push_swap.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:41:47 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 18:04:36 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** appendix of push function - had to split due to norm
**
** params
**	t_stack *dst		pointer to struct representing dst
**	t_clist *to_push	element to push to first postion of dst
*/

static void	operation_push_2nd(t_stack *dst, t_clist *to_push)
{
	if (dst->node_count == 0)
	{
		to_push->next = to_push;
		to_push->prev = to_push;
	}
	else
	{
		to_push->next = dst->head;
		to_push->prev = dst->head->prev;
		dst->head->prev->next = to_push;
		dst->head->prev = to_push;
	}
	dst->head = to_push;
	++(dst->node_count);
}

/*
** -------------------------------------------------------------------------- **
** pushes the first node of stack src to stack dst
**
** params
**	t_stack *dst	pointer to struct representing dst
**	t_stack *src	pointer to struct representing src
*/

void		operation_push(t_stack *dst, t_stack *src)
{
	t_clist	*to_push;

	if (src->node_count == 0)
		return ;
	to_push = src->head;
	if (src->node_count == 1)
		src->head = 0;
	else
	{
		src->head->next->prev = src->head->prev;
		src->head->prev->next = src->head->next;
		src->head = src->head->next;
	}
	--(src->node_count);
	operation_push_2nd(dst, to_push);
}

/*
** -------------------------------------------------------------------------- **
** swaps the first two elements of the stack
**
** params
**	t_stack *stack		pointer to struct representing stack
*/

void		operation_swap(t_stack *stack)
{
	t_clist	*new_head;

	if (stack->node_count == 1 || stack->node_count == 0)
		return ;
	new_head = stack->head->next;
	if (stack->node_count == 2)
	{
		stack->head = new_head;
		return ;
	}
	stack->head->next->next->prev = stack->head;
	stack->head->next = stack->head->next->next;
	new_head->prev = stack->head->prev;
	stack->head->prev->next = new_head;
	stack->head->prev = new_head;
	new_head->next = stack->head;
	stack->head = new_head;
}

/*
** -------------------------------------------------------------------------- **
** swaps the first two elements of both stacks
**
** params
**	t_stack *stack_1	pointer to struct representing one stack
**	t_stack *stack_2	pointer to struct representing the other stack
*/

void		operation_ss(t_stack *stack_1, t_stack *stack_2)
{
	operation_swap(stack_1);
	operation_swap(stack_2);
}

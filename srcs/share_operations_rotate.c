/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_operations_rotate.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:09:31 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/23 19:40:19 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** rotates stack by 1 element, first node becomes last
**
** params
**	t_stack **stack		pointer to struct representing stack
*/

void	operation_rotate(t_stack **stack)
{
	t_clist	*new_head;

	if ((*stack)->node_count == 1 || (*stack)->node_count == 0)
		return ;
	new_head = (*stack)->head->next;
	(*stack)->head = new_head;
}

/*
** -------------------------------------------------------------------------- **
** reverse rotates stack by 1 element, last node becomes first
**
** params
**	t_stack **stack		pointer to struct representing stack
*/

void	operation_rev_rotate(t_stack **stack)
{
	t_clist	*new_head;

	if ((*stack)->node_count == 1 || (*stack)->node_count == 0)
		return ;
	new_head = (*stack)->head->prev;
	(*stack)->head = new_head;
}

/*
** -------------------------------------------------------------------------- **
** rotates two stacks by 1 element, first node becomes last
**
** params
**	t_stack **stack_1	pointer to struct representing one stack
**	t_stack **stack_2	pointer to struct representing the other stack
*/

void	operation_rr(t_stack **stack_1, t_stack **stack_2)
{
	operation_rotate(stack_1);
	operation_rotate(stack_2);
}

/*
** -------------------------------------------------------------------------- **
** reverse rotates two stacks by 1 element, last node becomes first
**
** params
**	t_stack **stack_1	pointer to struct representing one stack
**	t_stack **stack_2	pointer to struct representing the other stack
*/

void	operation_rrr(t_stack **stack_1, t_stack **stack_2)
{
	operation_rev_rotate(stack_1);
	operation_rev_rotate(stack_2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_operations_push_swap.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 19:41:47 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/23 19:49:00 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** pushes the first node of stack src to stack dst
**
** params
**	t_stack **dst	pointer to struct representing dst
**	t_stack **src	pointer to struct representing src
*/

void	operation_push(t_stack **dst, t_stack **src)
{
	if ((*src)->node_count == 0)
		return ;
}

/*
** -------------------------------------------------------------------------- **
** swaps the first two elements of the stack
**
** params
**	t_stack **stack		pointer to struct representing stack
*/

void	operation_swap(t_stack **stack)
{
	if ((*stack)->node_count == 1 || (*stack)->node_count == 0)
		return ;
}

/*
** -------------------------------------------------------------------------- **
** swaps the first two elements of both stacks
**
** params
**	t_stack **stack_1	pointer to struct representing one stack
**	t_stack **stack_2	pointer to struct representing the other stack
*/

void	operation_ss(t_stack **stack_1, t_stack **stack_2)
{
	operation_swap(stack_1);
	operation_swap(stack_2);
}


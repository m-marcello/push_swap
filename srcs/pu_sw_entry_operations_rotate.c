/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_entry_operations_rotate.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 14:59:31 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 15:03:18 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** function to rotate stack a up, first element becomes last
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	ra(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rotate(stack_a);
	visualizer(p_info, "ra", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to rotate stack b up, first element becomes last
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	rb(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rotate(stack_b);
	visualizer(p_info, "rb", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to rotate both stacks up, first elements become last
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	rr(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rr(stack_a, stack_b);
	visualizer(p_info, "rr", stack_a, stack_b);
}

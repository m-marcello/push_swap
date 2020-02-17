/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_entry_operations_rev_rotate.c                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 15:04:04 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 13:04:09 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** function to rotate stack a down, last element becomes first
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
** return
**	VOID
*/

void	rra(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rev_rotate(stack_a);
	visualizer(p_info, "rra", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to rotate stack b down, last element becomes first
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
** return
**	VOID
*/

void	rrb(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rev_rotate(stack_b);
	visualizer(p_info, "rrb", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to rotate both stacks down, last elements becomes first
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
** return
**	VOID
*/

void	rrr(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_rrr(stack_a, stack_b);
	visualizer(p_info, "rrr", stack_a, stack_b);
}

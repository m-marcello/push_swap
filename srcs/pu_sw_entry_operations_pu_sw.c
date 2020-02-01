/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_entry_operations_pu_sw.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/01 14:45:45 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 14:57:45 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** function to push first item of stack b to stack a
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	pa(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_push(stack_a, stack_b);
	visualizer(p_info, "pa", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to push first item of stack a to stack b
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	pb(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_push(stack_b, stack_a);
	visualizer(p_info, "pb", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to swap first two elemants of stack a
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	sa(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_swap(stack_a);
	visualizer(p_info, "sa", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to swap first two elemants of stack b
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	sb(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_swap(stack_b);
	visualizer(p_info, "sb", stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** function to swap first two elements of both stack a and stack b
**
** params
**	t_print	*p_info		pointer to printing information
**	t_stack *stack_a	pointer to struct for stack a
**	t_stack *stack_b	pointer to struct for stack b
*/

void	ss(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	operation_ss(stack_a, stack_b);
	visualizer(p_info, "ss", stack_a, stack_b);
}

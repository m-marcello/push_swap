/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_handler.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 17:24:03 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/27 14:58:34 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "libft.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** calls the stack operation for the specified instruction
**
** params
**	char *inst			the instruction to be applied to the stacks
**	t_stack **stack_a	pointer to struct representing stack a
**	t_stack **stack_b	pointer to struct representing stack b
** return
**	1					when instruction exists
**	0					when it doesn't
*/

static int	apply_instruction(char *inst, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strequ(inst, "sa"))
		operation_swap(stack_a);
	else if (ft_strequ(inst, "sb"))
		operation_swap(stack_b);
	else if (ft_strequ(inst, "ss"))
		operation_ss(stack_a, stack_b);
	else if (ft_strequ(inst, "pa"))
		operation_push(stack_a, stack_b);
	else if (ft_strequ(inst, "pb"))
		operation_push(stack_b, stack_a);
	else if (ft_strequ(inst, "ra"))
		operation_rotate(stack_a);
	else if (ft_strequ(inst, "rb"))
		operation_rotate(stack_b);
	else if (ft_strequ(inst, "rr"))
		operation_rr(stack_a, stack_b);
	else if (ft_strequ(inst, "rra"))
		operation_rev_rotate(stack_a);
	else if (ft_strequ(inst, "rrb"))
		operation_rev_rotate(stack_b);
	else if (ft_strequ(inst, "rrr"))
		operation_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** calls the instructions from the standard input line by line
** passes them to apply_instruction() which checks if the instruction is valid
** and calls the respective operation
**
** params
**	t_stack **stack_a	pointer to struct representing stack a
**	t_stack **stack_b	pointer to struct representing stack b
** return
**	1					when all instructions exists
**	0					when a line makes no sense
*/

int		instruction_handler(t_stack **stack_a, t_stack **stack_b)
{
	char	*inst;
	int		ret;

	ret = get_next_line(0, &inst);
	if (ret == -1)
		return (0);
	while (ret == 1)
	{
		if (ret == -1)
			return (0);
		if (apply_instruction(inst, stack_a, stack_b) == 0)
		{
			free(inst);
			return (0);
		}
		free(inst);
		ret = get_next_line(0, &inst);
	}
	return (1);
}

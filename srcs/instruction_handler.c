/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_handler.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/25 17:24:03 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/25 19:12:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** calls the stack opperation for the specified instruction
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
		opperation_swap(stack_a);
	else if (ft_strequ(inst, "sb"))
		opperation_swap(stack_b);
	else if (ft_strequ(inst, "ss"))
		opperation_ss(stack_a, stack_b);
	else if (ft_strequ(inst, "pa"))
		opperation_push(stack_a, stack_b);
	else if (ft_strequ(inst, "pb"))
		opperation_push(stack_b, stack_a);
	else if (ft_strequ(inst, "ra"))
		opperation_rotate(stack_a);
	else if (ft_strequ(inst, "rb"))
		opperation_rotate(stack_b);
	else if (ft_strequ(inst, "rr"))
		opperation_rr(stack_a, stack_b);
	else if (ft_strequ(inst, "rra"))
		opperation_rev_rotate(stack_a);
	else if (ft_strequ(inst, "rrb"))
		opperation_rev_rotate(stack_b);
	else if (ft_strequ(inst, "rrr"))
		opperation_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** calls the instructions from the standard input line by line
** passes them to apply_instruction() which checks if the instruction is valid
** and calls the respective opperation
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

	while (get_next_line(0, &inst))
	{
		if (apply_instruction(inst, stack_a, stack_b) == 0)
			return (0);
	}
	return (1);
}

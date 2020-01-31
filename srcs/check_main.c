/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:57:53 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 16:50:47 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include <unistd.h>

/*
** -------------------------------------------------------------------------- **
** checks if the stack is sorted
** first item smaller than second, second smaller than third, ... last item
** being smallest
**
** params
**	t_stack **stack	pointer to struct representing stack
** return
**	1				when stack is sorted
**	0				when it isn't
*/

static int	is_sorted(t_stack *stack)
{
	unsigned int	i;
	t_clist			*walk;

	i = 1;
	walk = stack->head;
	while (i < stack->node_count)
	{
		if (walk->data >= walk->next->data)
			return (0);
		walk = walk->next;
		++i;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack			*stack_a;
	t_stack			*stack_b;

	if (argc == 1)
		return (0);
	if (create_both_stacks(&stack_a, &stack_b) == 0)
		return (0);
	if (is_valid_input(argc - 1, &argv[1], &stack_a) == 0
		|| instruction_handler(stack_a, stack_b) == 0)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	if (is_sorted(stack_a) && stack_b->head == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

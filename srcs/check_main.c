/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:57:53 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 12:57:23 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"
#include <unistd.h>

int		main(int argc, char **argv)
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

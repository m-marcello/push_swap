/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/09 14:57:53 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/13 18:14:03 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include "check.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	t_clist	*stack_a;
	t_clist	*stack_b;
	char	**inst;

	if (argc == 1)
		return (0);
	stack_a = 0;
	if (!is_valid_input(argc - 1, argv[1], &stack_a) || !is_valid_inst(&inst))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	apply_inst(inst, &stack_a, &stack_b);
	if (is_sorted(stack_a) && is_empty(stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}

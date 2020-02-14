/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:58:37 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 15:36:56 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"
#include <unistd.h>

/*
** -------------------------------------------------------------------------- **
** checks the input arguments for verbose or color option and saves it in the
** options variable:
** 0 for no options
** 1 for verbose
** 2 for color
**
** params
**	char **argv		address to first argument of main
**	int *options	pointer to save the options
** return
**	arg_off			number of option arguments
*/

static int	get_options(char **argv, int *options)
{
	if ((ft_strequ(argv[0], "-c") && ft_strequ(argv[1], "-v"))
		|| (ft_strequ(argv[0], "-v") && ft_strequ(argv[1], "-c")))
	{
		*options = 2;
		return (2);
	}
	if (ft_strequ(argv[0], "-vc") || ft_strequ(argv[0], "-cv")
		|| ft_strequ(argv[0], "-c"))
	{
		*options = 2;
		return (1);
	}
	if (ft_strequ(argv[0], "-c"))
	{
		*options = 2;
		return (1);
	}
	if (ft_strequ(argv[0], "-v"))
	{
		*options = 1;
		return (1);
	}
	else
		*options = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	int		arg_off;
	int		options;
	t_stack	*stack_a;
	t_stack *stack_b;

	if (argc == 1 ||
		(argc == 2 && (ft_strequ(argv[1], "-v") || ft_strequ(argv[1], "-c") ||
		ft_strequ(argv[1], "-vc") || ft_strequ(argv[1], "-cv"))))
		return (0);
	arg_off = get_options(&argv[1], &options);
	if (create_both_stacks(&stack_a, &stack_b) == 0)
		return (0);
	if (is_valid_input(argc - 1 - arg_off, &argv[1 + arg_off],
			stack_a) == 0)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	tree_sort(stack_a);
	start_sort(options, stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

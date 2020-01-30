/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_main.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/28 16:58:37 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/30 22:13:07 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** 
**
** params
**	char ***argv	address to first argument of main
** return
**	arg_off			number of option arguments
**	-1				in case of error
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
		(argc == 2 && (ft_strequ(argv[1], "-v") || ft_strequ(argv[1], "-c"))))
		return (0);
	arg_off = get_options(argv[1], &options);
	if (create_both_stacks(&stack_a, &stack_b) == 0)
		return (0);
	if (is_valid_input(argc - 1 - arg_off, &argv[1 + arg_off],
			&stack_a) == 0)
	{
		write(2, "Error\n", 6);
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (0);
	}
	sort_stack(options, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

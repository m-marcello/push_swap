/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_input_validation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 16:05:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/13 18:02:52 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** splits the input strings at ' ' and generates a circular list representing
** stack a
**
** params
**	t_clist **stack_a	pointer to first element of stack a
**	char **argv			address of first argument of main
** return
**	1					when everthing went fine
**	0					in case of error
*/

static int	generate_stack_a(t_clist **stack_a, char **argv)
{
	return (0);
}

/*
** -------------------------------------------------------------------------- **
** validates the input and creates stack a as linked circle if input is valid
**
** accepts only spaces as seperator within a string,
** multiple spaces are supported
**
** params
**	int argc			number of strings of argv
**	char **argv			address of first argument of main
**	t_clist **stack_a	pointer to first element of stack a
** return
**	1					in case of valid input
**	0					in case of invalid input
*/

int		is_valid_input(int argc, char **argv, t_clist **stack_a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!ft_is_num(argv[i][j]) || !(argv[i][j] != ' '))
				return (0);
			j++;
		}
		i++;
	}
	if (!generate_stack_a(stack_a, argv))
		return (0);
	return (1);
}

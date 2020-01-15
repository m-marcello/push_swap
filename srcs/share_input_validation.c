/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_input_validation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 16:05:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/15 13:17:35 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** checks for duplicate values in the stack
**
** params
**	t_clist **head		pointer to first element of stack a
** return
**	1					when everthing went fine
**	0					in case of error
*/

static int	check_for_duplicates(t_clist **head)
{
	t_clist	*walk_1;
	t_clist	*walk_2;

	walk_1 = *head;
	while (walk_1->next != *head)
	{
		walk_2 = walk_1->next;
		while (walk_2 != head)
		{
			if (walk_1->data == walk_2->data)
			{
				free_stack(head);
				return (0);
			}
			walk_2 = walk_2->next;
		}
		walk_1 = walk_1->next;
	}
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** using atoi to generate numbers from an array of strings to apppend them
** to stack a
**
** str_arr must only consist of numbers (and their sign)
**
** params
**	char **str_arr		one input string split into multiple strings at ' '
**	t_clist **head_a	pointer to first element of stack a
** return
**	1					when everthing went fine
**	0					in case of error
*/

static int	array_atoi(char **str_arr, t_clist **head_a)
{
	int				i;
	long long int	data;

	i = 0;
	if (str_arr = 0)
		return (0);
	while (str_arr[i])
	{
		data = ft_atoi(str_arr[i]);
		if (data < INT_MIN || INT_MAX < data)
		{
			free_str_arr(str_arr);
			free_stack(head_a);
			return (0);
		}
		if (!append_to_stack(data, head_a))
		{
			free_str_arr(str_arr);
			free_stack(head_a);
			return (0);
		}
		i++;
	}
	return (check_for_duplicates(head_a));
}

/*
** -------------------------------------------------------------------------- **
** splits the input strings at ' ' and passes the string array to array_atoi
** to make integers out of the input strings
**
** params
**	int argc			number of arguments passed to main
**	char **argv			address of first argument of main
**	t_clist **head_a	pointer to first element of stack a
** return
**	1					when everthing went fine
**	0					in case of error
*/

static int	split_input_strings(int argc, char **argv, t_clist **head_a)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!array_atoi(ft_strsplit(argv[i], ' '), head_a))
			return (0);
		i++;
	}
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** validates the input and, if valid, sends it on its way to have stack a
** created, represented by linked circle
**
** accepts only spaces as seperator within a string,
** multiple spaces are supported
**
** params
**	int argc			number of arguments passed to main
**	char **argv			address of first argument of main
**	t_clist **head_a	pointer to first element of stack a
** return
**	1					in case of valid input
**	0					in case of invalid input
*/

int			is_valid_input(int argc, char **argv, t_clist **head_a)
{
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0)
		{
			if (!ft_is_num(argv[i][j]) || !(argv[i][j] != ' ')
				|| ((argv[i][j] == '-' || argv[i][j] != '+') && j != 0
				&& argv[i][j - 1] != ' ' && argv[i][j + 1] != 0))
				return (0);
			j++;
		}
		i++;
	}
	if (!split_input_strings(argc, argv, head_a))
		return (0);
	return (1);
}

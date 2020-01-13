/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_input_validation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 16:05:14 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/13 12:54:35 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** validates the input and creates stack a as linked circle if input is valid
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
	argc = 1;
	argv = 0;
	stack_a = 0;
	return (0);
}

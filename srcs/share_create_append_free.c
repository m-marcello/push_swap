/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_create_append_free.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 14:25:06 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/16 20:02:39 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** frees each node of the stack an the struct in which it is saved
**
** params
**	t_stack **stack	pointer to struct representing stack
*/

void	free_stack(t_stack **stack)
{
	t_stack	*walk;

	walk = (*stack)->head;
}

/*
** -------------------------------------------------------------------------- **
** frees an array of strings
**
** params
**	char	***arr	address of the string array
*/

void	free_str_array(char ***str_arr)
{
	;
}

/*
** -------------------------------------------------------------------------- **
** appends the entries from an array of strings to the stack
** if there is no stack yet it will be created
**
** params
**	int data		data for the node to be appended to stack
**	t_stack **stack	pointer to struct representing stack
** return
**	1				when everthing went fine
**	0				in case of error
*/

void	append_to_stack(int data, t_stack **stack)
{
	;
}

/*
** -------------------------------------------------------------------------- **
**
*/

/*
** -------------------------------------------------------------------------- **
**
*/

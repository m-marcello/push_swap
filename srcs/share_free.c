/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 22:18:26 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/20 22:19:13 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** sets the values of one node of the stack to 0 and frees its pointer
**
** params
**	t_stack **node	pointer to the node
*/

static void	free_node(t_clist **node)
{
	(*node)->next = 0;
	(*node)->prev = 0;
	(*node)->data = 0;
	free(*node);
	*node = 0;
}

/*
** -------------------------------------------------------------------------- **
** walks through the stack to save each node
**
** params
**	t_stack **stack	pointer to struct representing stack
*/

void		free_stack(t_stack **stack)
{
	t_clist	*walk;

	if (*stack == 0)
		return ;
	walk = (*stack)->head->next;
	(*stack)->head->prev->next = 0;
	free_node(&((*stack)->head));
	while (walk)
	{
		walk = walk->next;
		free_node(&(walk->prev));
	}
	(*stack)->head = 0;
	(*stack)->node_count = 0;
	free(*stack);
	*stack = 0;
}

/*
** -------------------------------------------------------------------------- **
** frees an array of strings and sets everything to 0
**
** params
**	char	***arr	address of the string array
*/

void		free_str_arr(char ***str_arr)
{
	int		i;
	int		j;

	i = 0;
	while ((*str_arr)[i])
	{
		j = 0;
		while ((*str_arr)[i][j])
		{
			(*str_arr)[i][j] = 0;
			j++;
		}
		free((*str_arr)[i]);
		(*str_arr)[i] = 0;
		i++;
	}
	free(**str_arr);
	**str_arr = 0;
}

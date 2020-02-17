/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_free.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 22:18:26 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 15:21:18 by mmarcell      ########   odam.nl         */
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
** return
**	VOID
*/

static void	free_node(t_clist **node)
{
	(*node)->next = 0;
	(*node)->prev = 0;
	(*node)->data = 0;
	(*node)->left = 0;
	(*node)->right = 0;
	(*node)->parent = 0;
	(*node)->index = 0;
	free(*node);
	*node = 0;
}

/*
** -------------------------------------------------------------------------- **
** walks through the stack to free each node
**
** params
**	t_stack **stack	pointer to struct representing stack
** return
**	VOID
*/

void		free_stack(t_stack **stack)
{
	t_clist	*walk;
	t_clist	*to_free;

	if (*stack == 0)
		return ;
	walk = (*stack)->head;
	while ((*stack)->node_count > 0)
	{
		to_free = walk;
		walk = walk->next;
		free_node(&to_free);
		(*stack)->node_count--;
	}
	(*stack)->head = 0;
	free(*stack);
	*stack = 0;
}

/*
** -------------------------------------------------------------------------- **
** frees an array of strings and sets everything to 0
**
** params
**	char	***arr	address of the string array
** return
**	VOID
*/

void		free_str_arr(char ***str_arr)
{
	int		i;
	int		j;
	char	**to_free;

	if (**str_arr == 0)
		return ;
	to_free = *str_arr;
	i = 0;
	while (to_free[i])
	{
		j = 0;
		while (to_free[i][j])
		{
			to_free[i][j] = 0;
			j++;
		}
		free(to_free[i]);
		to_free[i] = 0;
		i++;
	}
	free(to_free);
	to_free = 0;
}

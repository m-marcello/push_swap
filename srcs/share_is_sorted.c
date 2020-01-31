/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_is_sorted.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 17:57:42 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 17:57:52 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** checks if the stack is sorted in ascending order
**
** params
**	t_stack *stack	pointer to struct representing stack
** return
**	0				when stack is not sorted
**	1				when it is sorted and the first item is the smallest
**	2				when it is sorted and the smallest item is not the first
*/

int		is_sorted(t_stack *stack)
{
	unsigned int	node_count;
	unsigned int	break_count;
	t_clist			*walk;

	node_count = 1;
	break_count = 0;
	walk = stack->head;
	while (node_count < stack->node_count)
	{
		if (walk->data >= walk->next->data)
			++break_count;
		if (break_count > 1)
			return (0);
		walk = walk->next;
		++node_count;
	}
	return (break_count);
}


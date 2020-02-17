/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 17:57:42 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 15:48:43 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** checks if the stack is sorted in ascending order
** note:
**	the smallest item does not necessarily need to be the first in order for
**	this algorithm to return true
**	I'll refer to a stack being sorted in stage 1 if the smallest item is also
**	the first item
**	and sorted in stage 2 if the smallest item is not the first
**	but by rotating the stack, it would get there
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
		if (walk->data > walk->next->data)
			++break_count;
		if (break_count > 1)
			return (0);
		walk = walk->next;
		++node_count;
	}
	if (break_count == 1 && stack->head->data < stack->head->prev->data)
		return (0);
	return (break_count + 1);
}

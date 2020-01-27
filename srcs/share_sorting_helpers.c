/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:22:33 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/27 16:50:32 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"

/*
** -------------------------------------------------------------------------- **
** checks if the stack is sorted
** first item smaller than second, second smaller than third, ... last item
** being smallest
**
** params
**	t_stack **stack	pointer to struct representing stack
** return
**	1				when stack is sorted
**	0				when it isn't
*/

int			is_sorted(t_stack *stack)
{
	unsigned int	i;
	t_clist			*walk;

	i = 1;
	walk = stack->head;
	while (i < stack->node_count)
	{
		if (walk->data >= walk->next->data)
			return (0);
		walk = walk->next;
		++i;
	}
	return (1);
}

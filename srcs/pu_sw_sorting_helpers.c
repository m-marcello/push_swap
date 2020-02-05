/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:22:33 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/05 13:17:55 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** checks if the data of one node is in between two other nodes
**	prev->data < node->data < head->data
** smaller than both
**	node->data < head->data < prev->data
** or bigger then both
**	head->data < prev->data < node->data
**
** params
**	t_clist *node	pointer to node that wants to be placed between
**	t_clist *prev	pointer to prev node
**	t_clist *head	pointer to head node
** return
**	1				if node fits between
**	0				if it doesn't
*/

int		fits_between(t_clist *node, t_clist *prev, t_clist *head)
{
	return ((prev->data < node->data && node->data < head->data)
		|| (node->data < head->data && head->data < prev->data)
		|| (node->data > prev->data && prev->data > head->data));
}

/*
** -------------------------------------------------------------------------- **
** counts if the it better to rotate or reverse rotate stack a to fit a given
** node
**
** params
**	t_clist *node	pointer to node that wants to be placed in stack a
**	t_stack *st_a	pointer to struct representing stack a - sorted, stage 2
** return
**	1				if ra is more efficient
**	0				if rra is more efficient
*/

int		optimal_rotation(t_clist *node, t_stack *stack_a)
{
	unsigned int	count;
	t_clist			*walk;

	if (stack_a->head == 0)
		return (-1);
	count = 1;
	walk = stack_a->head;
	while (fits_between(node, walk->prev, walk))
	{
		++count;
		walk = walk->next;
	}
	if (2 * count < stack_a->node_count)
		return (1);
	return (0);
}

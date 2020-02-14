/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:22:33 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 13:11:07 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** function to check if the last element is closer to the median than the first
**
** params
**	t_stack *stack				pointer to the stack to check for
**	unsigned long total_nodes	the amount of all nodes
** return
**	1							if the last element is closer to the median
**	0							if the first element is closer to the median
*/

int				closer_to_median(t_stack *stack, unsigned long total_nodes)
{
	unsigned long	median;
	unsigned long	distance_head;
	unsigned long	distance_prev;

	median = total_nodes / 2;
	distance_head = (stack->head->index < median) ?
		median - stack->head->index : stack->head->index - median;
	distance_prev = (stack->head->prev->index < median) ?
		median - stack->head->prev->index : stack->head->prev->index - median;
	return (distance_prev < distance_head);
}

/*
** -------------------------------------------------------------------------- **
** checks if the data of one node is in between two other nodes
**	prev->data < node->data < head->data
** smaller than both
**	node->data < head->data < prev->data
** or bigger then both
**	head->data < prev->data < node->data
** note:
**	will return 0 when prev->data = head->data
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
** counts if it is better to rotate or reverse rotate stack a to push a given
** node
**
** params
**	t_clist *node		pointer to node that wants to be placed in stack a
**	t_stack *stack_a	pointer to struct representing stack a - sorted, stage 2
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
	while (fits_between(node, walk->prev, walk) == 0)
	{
		++count;
		walk = walk->next;
	}
	if (2 * count < stack_a->node_count)
		return (1);
	return (0);
}

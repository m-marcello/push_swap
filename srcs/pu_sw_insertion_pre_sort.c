/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_insertion_pre_sort.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 19:39:20 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 17:09:12 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** checks if the index of a given node is within an epsilon range around the
** start and end of the stack
**
** params
**	t_clist *node				the node of which the index is checked
**	unsigned long eps			the given epsilon
**	unsigned long total_nodes	the total amount of nodes in stack a and b
** return
**	1							if the index is within the epsilon range
**	0							if it isn't
*/

static int	index_in_eps(t_clist *node, unsigned long eps,
			unsigned long total_nodes)
{
	return (node->index <= eps || node->index + eps >= total_nodes);
}

/*
** -------------------------------------------------------------------------- **
** pushes elements from stack a to stack b until either there are only 3
** elements remaining in stack a or stack a is sorted (smallest element does
** not necessarily need to be the first)
** after applying this function stack a will be sorted - stage 2
** stack b might still contain elements
**
** params
**	t_print *p_info		struct with all the relevant info regarding printing
**	t_stack *stack_a	pointer to struct representing stack a
**	t_stack *stack_b	pointer to struct representing stack b
** return
**	VOID
*/

void		pre_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	unsigned long	eps;
	unsigned long	total_nodes;

	total_nodes = stack_a->node_count;
	eps = (total_nodes > 150) ? total_nodes / 15 : 10;
	while (is_sorted(stack_a) == 0 && stack_a->node_count > 3)
	{
		if (index_in_eps(stack_a->head, eps, total_nodes))
			pb(p_info, stack_a, stack_b);
		else if (index_in_eps(stack_a->head->prev, eps, total_nodes) &&
			index_in_eps(stack_a->head->next, eps, total_nodes))
			sa(p_info, stack_a, stack_b);
		else if (index_in_eps(stack_a->head->prev, eps, total_nodes))
			rra(p_info, stack_a, stack_b);
		else
			ra(p_info, stack_a, stack_b);
		if (stack_b->head != 0 && stack_b->head->index * 2 < total_nodes &&
			stack_b->head->next->index * 2 > total_nodes)
			rb(p_info, stack_a, stack_b);
		if (stack_b->node_count == 2 * eps - 1)
			eps = (total_nodes > 150) ? eps + total_nodes / 15 : eps + 10;
	}
	if (is_sorted(stack_a) == 0 && stack_a->node_count == 3)
		sa(p_info, stack_a, stack_b);
}

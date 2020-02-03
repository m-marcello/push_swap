/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:22:33 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/03 19:39:37 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** checks if the data of one node is in between two other nodes
** prev->data < node->data < next->data
**
** params
**	t_clist *node	pointer to node that wants to be placed between
**	t_clist *prev	pointer to prev node
**	t_clist *next	pointer to next node
** return
**	1				if node fits between
**	0				if it doesn't
*/

int		fits_between(t_clist *node, t_clist *prev, t_clist *next)
{
	return ((prev->data < node->data && node->data < next->data)
		|| (node->data < prev->data && node->data < next->data)
		|| (node->data > prev->data && node->data > next->data));
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

void	pre_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	while (is_sorted(stack_a) == 0 && stack_a->node_count > 3)
	{
		if (stack_a->head->prev->data < stack_a->head->data &&
			stack_a->head->prev->data < stack_a->head->next->data)
			rra(p_info, stack_a, stack_b);
		else if (stack_a->head->next->data < stack_a->head->data &&
			stack_a->head->data < stack_a->head->prev->data)
			ra(p_info, stack_a, stack_b);
		else if (stack_a->head->next->data < stack_a->head->prev->data &&
			stack_a->head->prev->data < stack_a->head->data)
			sa(p_info, stack_a, stack_b);
		pb(p_info, stack_a, stack_b);
	}
	if (is_sorted(stack_a) == 0 && stack_a->node_count == 3)
		sa(p_info, stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** checks in which direction to rotate the stack most efficient and
** rotates stack a so that the smallest item becomes first item
**
** params
**	t_print *p_info		struct with all the relevant info regarding printing
**	t_stack *stack_a	pointer to struct representing stack a - sorted stage 2
**	t_stack *stack_b	pointer to struct representing stack b
** return
**	VOID
*/

void	post_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	count;
	t_clist			*walk;

	if (is_sorted(stack_a) == 1 || is_sorted(stack_a) == 0 ||
		stack_a->head == 0)
		return ;
	count = 1;
	walk = stack_a->head;
	while (walk->data < walk->next->data)
	{
		++count;
		walk = walk->next;
	}
	if (2 * count < stack_a->node_count)
	{
		while (is_sorted(stack_a) == 2)
			ra(p_info, stack_a, stack_b);
	}
	else
	{
		while (is_sorted(stack_a) == 2)
			rra(p_info, stack_a, stack_b);
	}
}

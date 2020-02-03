/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 22:08:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/03 19:36:50 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"
#include <stdlib.h>


/*
** -------------------------------------------------------------------------- **
**
**
** params
**	t_clist *node	pointer to node that wants to be placed in stack a
**	t_stack *st_a	pointer to struct representing stack a - sorted, stage 2
** return
**	1				if ra is more efficient
**	0				if rra is more efficient
*/

static int	rotate_up(t_clist *node, t_stack *stack_a)
{
	unsigned int	count;
	t_clist			*walk;

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

/*
** -------------------------------------------------------------------------- **
**
**
** params
**	t_print *p_info	struct with all the relevant info regarding printing
**	t_stack *st_a	pointer to struct representing stack a - sorted, stage 2
**	t_stack *st_b	pointer to struct representing stack b
** return
**	VOID
*/

static void	insert_sort(t_print *p_info, t_stack *st_a, t_stack *st_b)
{
	if (st_a->head == 0 || st_b->head == 0)
		return ;
	if (fits_between(st_b->head, st_a->head->prev, st_a->head))
		pb(p_info, st_a, st_b);
	else if (fits_between(st_b->head, st_a->head, st_a->head->next))
		ra(p_info, st_a, st_b);
	else if (fits_between(st_b->head, st_a->head->prev->prev, st_a->head->prev))
		rra(p_info, st_a, st_b);
	else if (fits_between(st_b->head->prev, st_a->head->prev, st_a->head))
		rrb(p_info, st_a, st_b);
	else if (fits_between(st_b->head->next, st_a->head->prev, st_a->head))
		rb(p_info, st_a, st_b);
	else if (fits_between(st_b->head->prev,
		st_a->head->prev->prev, st_a->head->prev))
		rrr(p_info, st_a, st_b);
	else if (fits_between(st_b->head->next,
		st_a->head->prev->prev, st_a->head->prev))
		rr(p_info, st_a, st_b);
	else
	{
		if (rotate_up(st_b->head, st_a))
			ra(p_info, st_a, st_b);
		else
			rra(p_info, st_a, st_b);
	}
}

/*
** -------------------------------------------------------------------------- **
**
**
** params
**	int options			if 0 -> only print instructions
**						if 1 -> print state of stacks after each instruction
**						if 2 -> print in color
**	t_stack *stack_a	pointer to struct representing stack a
**	t_stack *stack_b	pointer to struct representing stack b
** return
**	VOID
*/

void		start_sort(int options, t_stack *stack_a, t_stack *stack_b)
{
	t_print *p_info;

	p_info = 0;
	if (options > 0)
	{
		p_info = (t_print*)malloc(sizeof(t_print));
		if (p_info == 0)
			return ;
		ft_bzero(p_info, sizeof(p_info));
		p_info->color = options - 1;
		visualizer(p_info, "start", stack_a, stack_b);
	}
	pre_sort(p_info, stack_a, stack_b);
	insert_sort(p_info, stack_a, stack_b);
	post_sort(p_info, stack_a, stack_b);
	ft_bzero(p_info, sizeof(p_info));
	free(p_info);
	p_info = 0;
}

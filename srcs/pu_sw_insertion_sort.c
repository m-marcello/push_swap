/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_insertion_sort.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 22:08:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 17:09:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** rotates stack a so that the smallest item becomes first item
**
** params
**	t_print *p_info		struct with all the relevant info regarding printing
**	t_stack *stack_a	pointer to struct representing stack a - sorted stage 2
**	t_stack *stack_b	pointer to struct representing stack b - empty
** return
**	VOID
*/

void		post_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
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

/*
** -------------------------------------------------------------------------- **
** sorts stack b into stack a one operation at a time
** note:
**	stack a and stack b must not be empty
**	stack a remains sorted in stage 2 through this entire process
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
	if (fits_between(st_b->head, st_a->head->prev, st_a->head))
		pa(p_info, st_a, st_b);
	else if (fits_between(st_b->head, st_a->head, st_a->head->next))
		ra(p_info, st_a, st_b);
	else if (fits_between(st_b->head, st_a->head->prev->prev, st_a->head->prev))
		rra(p_info, st_a, st_b);
	else if (fits_between(st_b->head->prev, st_a->head->prev, st_a->head))
		rrb(p_info, st_a, st_b);
	else if (fits_between(st_b->head->next, st_a->head->prev, st_a->head))
		sb(p_info, st_a, st_b);
	else if (fits_between(st_b->head->prev,
		st_a->head->prev->prev, st_a->head->prev))
		rrr(p_info, st_a, st_b);
	else if (fits_between(st_b->head->next, st_a->head, st_a->head->next))
		rr(p_info, st_a, st_b);
	else if (closer_to_median(st_b->head->prev, st_b->head,
		st_a->node_count + st_b->node_count))
		rrb(p_info, st_a, st_b);
	else
	{
		if (optimal_rotation(st_b->head, st_a) == 1)
			ra(p_info, st_a, st_b);
		else
			rra(p_info, st_a, st_b);
	}
}

/*
** -------------------------------------------------------------------------- **
** loops over insert_sort() so stack b gets sorted into stack a
**
** params
**	t_print *p_info		struct with all the relevant info regarding printing
**	t_stack *stack_a	pointer to struct representing stack a - sorted, stage 2
**	t_stack *stack_b	pointer to struct representing stack b
** return
**	VOID
*/

static void	sort_loop(t_print *p_info, t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->head != 0 && stack_b->head != 0)
		insert_sort(p_info, stack_a, stack_b);
}

/*
** -------------------------------------------------------------------------- **
** entry point for the insertion sort algorithm
** generates struct for holding the printing information (if any)
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
	sort_loop(p_info, stack_a, stack_b);
	post_sort(p_info, stack_a, stack_b);
	if (p_info == 0)
		return ;
	ft_bzero(p_info, sizeof(p_info));
	free(p_info);
	p_info = 0;
}

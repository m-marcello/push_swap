/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_visualizer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 19:20:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 17:23:12 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** saves necessary information for visualization with color
**
** params
**	t_print *p_info	struct with all the relevant info regarding printing
** return
**	VOID
*/

static void	set_color_info(t_print *p_info)
{
	p_info->col_a = (ft_strequ(p_info->inst, "pa")
		|| ft_strequ(p_info->inst, "sa") || ft_strequ(p_info->inst, "ss")
		|| ft_strequ(p_info->inst, "ra") || ft_strequ(p_info->inst, "rr")
		|| ft_strequ(p_info->inst, "rra") || ft_strequ(p_info->inst, "rrr"));
	p_info->col_b = (ft_strequ(p_info->inst, "pb")
		|| ft_strequ(p_info->inst, "sb") || ft_strequ(p_info->inst, "ss")
		|| ft_strequ(p_info->inst, "rb") || ft_strequ(p_info->inst, "rr")
		|| ft_strequ(p_info->inst, "rrb") || ft_strequ(p_info->inst, "rrr"));
	p_info->col_first = (ft_strequ(p_info->inst, "pa")
		|| ft_strequ(p_info->inst, "pb") || ft_strequ(p_info->inst, "sa")
		|| ft_strequ(p_info->inst, "sb") || ft_strequ(p_info->inst, "ss")
		|| ft_strequ(p_info->inst, "rra") || ft_strequ(p_info->inst, "rrb")
		|| ft_strequ(p_info->inst, "rrr"));
	p_info->col_second = (ft_strequ(p_info->inst, "sa")
		|| ft_strequ(p_info->inst, "sb") || ft_strequ(p_info->inst, "ss"));
	p_info->col_last = (ft_strequ(p_info->inst, "ra")
		|| ft_strequ(p_info->inst, "rb") || ft_strequ(p_info->inst, "rr"));
}

/*
** -------------------------------------------------------------------------- **
** prints the current state of both stacks
**	- with or without highlighting the last moved items, depending on the
**	color variable in p_info
**
** params
**	t_clist *walk_a	first item of stack a
**	t_clist *walk_b	first item of stack b
** return
**	VOID
*/

static void	print_stacks(t_print *p_info, t_clist *walk_a, t_clist *walk_b)
{
	int		count;
	char	*col_a;
	char	*col_b;

	count = 1;
	while (count < p_info->count_a || count < p_info->count_b)
	{
		col_a = (p_info->color && p_info->col_a && ((p_info->col_last &&
			count == p_info->count_a) || (p_info->col_second && count == 2) ||
			(p_info->col_first && count == 1))) ? COLOR : RESET;
		col_b = (p_info->color && p_info->col_b && ((p_info->col_last &&
			count == p_info->count_b) || (p_info->col_second && count == 2) ||
			(p_info->col_first && count == 1))) ? COLOR : RESET;
		if (count <= p_info->count_a && count <= p_info->count_b)
			ft_printf("|%s%25d%s  |%s%25d%s  |\n", col_a, walk_a->data, RESET,
			col_b, walk_b->data, RESET);
		else if (count <= p_info->count_a && count > p_info->count_b)
			ft_printf("|%s%25d%s  |%25c  |\n", col_a, walk_a->data, RESET, '-');
		else if (count > p_info->count_a && count <= p_info->count_b)
			ft_printf("|%25c  |%s%25d%s  |\n", '-', col_b, walk_b->data,
				RESET);
		++count;
		walk_a = (walk_a != 0) ? walk_a->next : 0;
		walk_b = (walk_b != 0) ? walk_b->next : 0;
	}
}

/*
** -------------------------------------------------------------------------- **
** entry point for an optional visualization of the current state of the
** two stacks
**	- with or without highlighting the last moved items, depending on the
**	color variable in p_info
**
** params
**	t_print *p_info	struct with all the relevant info regarding printing
**	char *inst		the applied instruction
**	t_stack **stack_a	pointer to struct for stack a
**	t_stack **stack_b	pointer to struct for stack b
** return
**	VOID
*/

void		visualizer(t_print *p_info, char *inst,
			t_stack *stack_a, t_stack *stack_b)
{
	if (p_info == 0)
		return ;
	p_info->inst = inst;
	p_info->count_a = stack_a->node_count;
	p_info->count_b = stack_b->node_count;
	if (p_info->color)
		set_color_info(p_info);
	ft_printf("\n|  %-25s|  %-25s|\n|%25c  |%25c  |\n",
			p_info->inst, p_info->inst, 'A', 'B');
	ft_printf("  =========================   ========================  \n");
	if ((stack_a->node_count || stack_b->node_count))
		print_stacks(p_info, stack_a->head, stack_b->head);
	else
		ft_printf("|%25c  |%25c  |\n", '-', '-');
	ft_printf("  =========================   ========================  \n");
}

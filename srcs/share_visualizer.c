/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_visualizer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 19:20:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/30 15:07:24 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"

static void	set_color_info(t_print *p_info)
{
	if (ft_strequ(inst, "sa") || ft_strequ(inst, "pa")
		|| ft_strequ(inst, "ra") || ft_strequ(inst, "rra"))
	{
		p_info->col_a = 1;
		p_info->col_b = 0;
	}
	if (ft_strequ(inst, "sa") || ft_strequ(inst, "pa")
		|| ft_strequ(inst, "ra") || ft_strequ(inst, "rra"))
	{
		p_info->col_a = 1;
		p_info->col_b = 0;
	}
	if (ft_strequ(inst, "ss")|| ft_strequ(inst, "rr") || ft_strequ(inst, "rrr"))
	{
		p_info->col_a = 1;
		p_info->col_b = 1;
	}
	
}

static void	print_stacks(t_print *p_info, t_clist *walk_a, t_clist *walk_b)
{
	while (p_info->count_a > 0 || p_info->count_b > 0)
	{
		if (p_info->count_a && p_info->count_b && p_info->color == 0)
		{
			ft_printf("|%25d  |%25d  |\n", walk_a->data, walk_b->data);
			walk_a = walk_a->next;
			walk_b = walk_b->next;
			--p_info->count_a;
			--p_info->count_b;
		}
		else if (p_info->count_a > 0 && !(p_info->count_b > 0)
			&& p_info->color == 0)
		{
			ft_printf("|%25d  |%25c  |\n", walk_a->data, '-');
			walk_a = walk_a->next;
			--p_info->count_a;
		}
		else if (!(p_info->count_a > 0) && p_info->count_b > 0
			&& p_info->color == 0)
		{
			ft_printf("|%25c  |%25d  |\n", '-', walk_b->data);
			walk_b = walk_b->next;
			--p_info->count_b;
		}
	}
}

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
}

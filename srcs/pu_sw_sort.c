/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 22:08:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 14:45:35 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"
#include "libft.h"
#include <stdlib.h>

void	start_sort(int options, t_stack *stack_a, t_stack *stack_b)
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
	is_sorted(stack_a);

	// operation_push(stack_b, stack_a);
	// visualizer(p_info, "pb", stack_a, stack_b);
	// operation_ss(stack_b, stack_a);
	// visualizer(p_info, "ss", stack_a, stack_b);
	// operation_push(stack_b, stack_a);
	// visualizer(p_info, "pb", stack_a, stack_b);
	// operation_rev_rotate(stack_b);
	// visualizer(p_info, "rrb", stack_a, stack_b);
}

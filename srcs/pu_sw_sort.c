/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 22:08:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 19:57:24 by mmarcell      ########   odam.nl         */
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
**	int options			if 0 -> only print instructions
**						if 1 -> print state of stacks after each instruction
**						if 2 -> print in color
**	t_stack *stack_a	pointer to struct representing stack a
**	t_stack *stack_b	pointer to struct representing stack b
** return
**	VOID
*/

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
	// if (pre_sort(p_info, stack_a, stack_b) == 1)
	// 	sort_stack(p_info, stack_a, stack_b);
	post_sort(p_info, stack_a, stack_b);
	ft_bzero(p_info, sizeof(p_info));
	free(p_info);
	p_info = 0;
}

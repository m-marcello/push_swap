/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:25:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/30 14:40:42 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PU_SW_H
# define PU_SW_H

# include "share.h"

typedef struct	s_print
{
	int		color;
	char	*inst;
	int		count_a;
	int		count_b;
	int		col_a;
	int		col_b;
	int		col_first;
	int		col_second;
	int		col_last;
}				t_print;


void	visualizer(int color, char *inst, t_stack *stack_a, t_stack *stack_b);

#endif

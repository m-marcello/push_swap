/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:25:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/31 15:35:08 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PU_SW_H
# define PU_SW_H

# include "share.h"

# define COLOR "\033[38;5;40m"
# define RESET "\033[0;00m"

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

void			visualizer(t_print *p_info, char *inst, t_stack *stack_a,
				t_stack *stack_b);
void			sort_stack(int options, t_stack *stack_a, t_stack *stack_b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:25:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/05 13:15:01 by mmarcell      ########   odam.nl         */
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
	int		count_a;
	int		count_b;
	int		col_a;
	int		col_b;
	int		col_first;
	int		col_second;
	int		col_last;
}				t_print;

void			start_sort(int options, t_stack *stack_a, t_stack *stack_b);
void			visualizer(t_print *p_info, char *inst, t_stack *stack_a,
				t_stack *stack_b);
int				fits_between(t_clist *node, t_clist *prev, t_clist *next);
int				optimal_rotation(t_clist *node, t_stack *stack_a);
void			pre_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			post_sort(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			pa(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			pb(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			sa(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			sb(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			ss(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			ra(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			rb(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			rr(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			rra(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			rrb(t_print *p_info, t_stack *stack_a, t_stack *stack_b);
void			rrr(t_print *p_info, t_stack *stack_a, t_stack *stack_b);

#endif

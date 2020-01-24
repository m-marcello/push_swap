/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:15:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/24 19:20:12 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef	struct	s_clist
{
	struct s_clist	*next;
	struct s_clist	*prev;
	int				data;
}				t_clist;

typedef struct	s_stack
{
	t_clist			*head;
	unsigned int	node_count;
}				t_stack;

int				create_both_stacks(t_stack **stack_a, t_stack **stack_b);
int				is_valid_input(int argc, char **argv, t_stack **stack);
int				is_sorted(t_stack *stack);
int				is_empty(t_stack *stack);
void			free_stack(t_stack **stack);
void			free_str_arr(char ***str_arr);
int				is_valid_input(int argc, char **argv, t_stack **stack);
int				append_to_stack(int data, t_stack **stack);
void			operation_push(t_stack **dst, t_stack **src);
void			operation_swap(t_stack **stack);
void			operation_ss(t_stack **stack_1, t_stack **stack_2);
void			operation_rotate(t_stack **stack);
void			operation_rr(t_stack **stack_1, t_stack **stack_2);
void			operation_rev_rotate(t_stack **stack);
void			operation_rrr(t_stack **stack_1, t_stack **stack_2);
void			visualizer(t_stack *stack_a, t_stack *stack_b);

#endif

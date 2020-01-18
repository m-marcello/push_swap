/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:15:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/18 16:43:01 by mmarcell      ########   odam.nl         */
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

int				is_valid_input(int argc, char **argv, t_stack **stack);
int				is_sorted(t_stack *stack);
int				is_empty(t_stack *stack);
void			free_stack(t_stack **stack);
void			free_str_arr(char ***str_arr);
int				is_valid_input(int argc, char **argv, t_stack **stack);
int				append_to_stack(int data, t_stack **stack);

#endif

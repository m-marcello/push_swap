/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:15:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/13 16:16:49 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

# define INT_MAX = 2147483647
# define INT_MIN = -2147483648

typedef	struct	s_clist
{
	struct s_clist	*next;
	struct s_clist	*prev;
	int				data;
}				t_clist;

int				is_valid_input(int argc, char **argv, t_clist **stack_a);
int				is_sorted(t_clist *stack);
int				is_empty(t_clist *stack);

#endif

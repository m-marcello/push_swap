/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:15:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/12 16:00:41 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARE_H
# define SHARE_H

typedef	struct	s_clist
{
	struct s_clist	*next;
	int				data;
}				t_clist;

int				validate_input(int argc, char **argv, t_clist **stack_a);
int				is_sorted(t_clist *stack);
int				is_empty(t_clist *stack);

#endif

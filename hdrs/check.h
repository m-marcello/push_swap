/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 15:15:39 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/21 00:42:30 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

int		is_valid_inst(char ***inst);
int		create_both_stacks(t_stack **stack_a, t_stack **stack_b);
int		create_stack(t_stack **stack);			// here for testing, make static again
int		check_for_duplicates(t_stack **stack);			// here for testing, make static again

#endif

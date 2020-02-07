/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_pu_sw_tree_sort.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:35:00 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/07 15:41:34 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "pu_sw.h"
#include "libft.h"

int		create_stack(t_stack **stack);
int		append_to_stack(int data, t_stack **stack);


/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_create_free.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 16:55:12 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/14 17:29:16 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_stack_create_append, create_first_node_valid)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, create_first_node_empty)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, append_valid)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_empty)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}

Test(sh_stack_create_append, multi_nodes_)
{
	t_clist	*stack;

	cr_assert(append_to_stack(ft_strsplit("", ' '), &stack) == 1, "");
}



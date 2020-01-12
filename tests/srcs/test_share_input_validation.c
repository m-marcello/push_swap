/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_input_validation.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 17:10:41 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/12 17:39:34 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"
#include "share.h"
#include "check.h"
#include "pu_sw.h"

Test(sh_input_validation, one_string_non_num_char_beg)
{
	t_clist	*stack_a;
	char	**argv;

	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
}

Test(sh_input_validation, one_string_non_num_char_end)
{
	t_clist	*stack_a;
	char	**argv;

	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
}

Test(sh_input_validation, one_string_non_num_char_middle)
{
	t_clist	*stack_a;
	char	**argv;

	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
	cr_assert(validate_input(1, &"", &stack_a) ==  , "");
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, one_string_)
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

Test(sh_input_validation, )
{
}

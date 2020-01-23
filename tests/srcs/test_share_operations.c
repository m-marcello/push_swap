/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_share_operations.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:29:32 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/23 14:53:02 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "share.h"

Test(sh_operations_push, push_full_full)
{
	t_stack	*dst;
	t_stack	*src;
	t_clist	*first_src;
	t_clist	*second_src;
	t_clist	*last_src;
	t_clist	*first_dst;
	t_clist	*last_dst;

	cr_assert(create_both_stacks(&dst, &src) == 1, "Error when creating the stacks");
	cr_assert(append_to_stack(5, &dst) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(-43, &dst) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(6, &dst) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(87, &dst) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(2, &src) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(-5863, &src) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(0, &src) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(24, &src) == 1, "Error when appending nodes");
	cr_assert(append_to_stack(42, &src) == 1, "Error when appending nodes");
	first_src = src->head;
	second_src = src->head->next;
	first_dst = dst->head;
	operation_push(&dst, &src);
	cr_expect(dst->node_count == 5, "dst node count incorrect");
	cr_expect(src->node_count == 4, "src node count incorrect");
	cr_expect(first_src->data == dst->head->data, "data of pushed element incorrect");
	cr_expect(first_src == dst->head, "push linking incorrect");
	cr_expect(first_src == dst->head->prev->next, "push linking incorrect");
	cr_expect(first_src == dst->head->next->prev, "push linking incorrect");
	cr_expect(second_src == src->head, "push linking incorrect");
	cr_expect(last_src == src->head->prev, "push linking incorrect");
	cr_expect(first_dst == dst->head->next, "push linking incorrect");
	cr_expect(last_dst == dst->head->prev, "push linking incorrect");
	cr_expect(first_src == dst->head->next->next->next->next, "push linking incorrect");
	cr_expect(first_src == dst->head->prev->prev->prev->prev, "push linking incorrect");
	cr_expect(first_dst == dst->head->next->next->next->next->next, "push linking incorrect");
	cr_expect(first_dst == dst->head->prev->prev->prev->prev->prev, "push linking incorrect");
	free_stack(&dst);
	free_stack(&src);
}

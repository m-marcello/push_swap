/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_visualizer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 19:20:21 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/27 15:04:29 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include "libft.h"

// static void	print_stacks(int printing_a, int printing_b, t_stack *stack_a,
// 			t_stack *stack_b)
// {
	// while (printing_a || printing_b)
	// {
	// 	if (printing_a && printing_b)
	// 	{
	// 		ft_printf("\n|%25d  |%25d  |\n", walk_a->data, walk_b->data);
	// 		walk_a = walk_a->next;
	// 		walk_b = walk_b->next;
	// 		printing_a = walk_a == stack_a->head ? 0 : 1;
	// 		printing_b = walk_b == stack_b->head ? 0 : 1;
	// 	}
	// 	else if (printing_a && !printing_b)
	// 	{
	// 		ft_printf("\n|%25d  |%25c  |\n", walk_a->data, '-');
	// 		walk_a = walk_a->next;
	// 		printing_a = walk_a == stack_a->head ? 0 : 1;
	// 	}
	// 	else if (!printing_a && printing_b)
	// 	{
	// 		ft_printf("\n|%25c  |%25d  |\n", '-', walk_b->data);
	// 		walk_b = walk_b->next;
	// 		printing_b = walk_b == stack_b->head ? 0 : 1;
	// 	}
	// }
// }

void		visualizer(t_stack *stack_a, t_stack *stack_b)
{
	t_clist	*walk_a;
	t_clist	*walk_b;
	int		printing_a;
	int		printing_b;

	walk_a = stack_a->head;
	walk_b = stack_b->head;
	printing_a = stack_a->head == 0 ? 0 : 1;
	printing_b = stack_b->head == 0 ? 0 : 1;
	ft_printf("\n|%25c  |%25c  |\n", 'A', 'B');
	ft_printf("  =========================   ========================  \n");
	// if (printing_a || printing_b)
	// 	print_stacks(printing_a, printing_b, stack_a, stack_b);
	while (printing_a || printing_b)
	{
		if (printing_a && printing_b)
		{
			ft_printf("|%25d  |%25d  |\n", walk_a->data, walk_b->data);
			walk_a = walk_a->next;
			walk_b = walk_b->next;
			printing_a = walk_a == stack_a->head ? 0 : 1;
			printing_b = walk_b == stack_b->head ? 0 : 1;
		}
		else if (printing_a && !printing_b)
		{
			ft_printf("|%25d  |%25c  |\n", walk_a->data, '-');
			walk_a = walk_a->next;
			printing_a = walk_a == stack_a->head ? 0 : 1;
		}
		else if (!printing_a && printing_b)
		{
			ft_printf("|%25c  |%25d  |\n", '-', walk_b->data);
			walk_b = walk_b->next;
			printing_b = walk_b == stack_b->head ? 0 : 1;
		}
	}
}

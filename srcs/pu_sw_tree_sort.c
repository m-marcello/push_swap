/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_tree_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:01:42 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/07 15:32:28 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

static void	apppend_leaf(t_clist *branch, t_clist *leaf)
{
	leaf->parent = branch;
	if (leaf->data > branch->data)
	{
		branch->right = leaf;
		leaf->index = branch->index + 1;
	}
	else if (leaf->data < branch->data)
	{
		branch->left = leaf;
		leaf->index = (branch->index)++;
	}
}

void	tree_sort(t_stack *stack, t_clist *node)
{
	t_clist	*walk;

	if (stack->trunk = 0)
	{
		stack->trunk = node;
		node->index = 1;
		return ;
	}
	walk = stack->head;
	while ((node->data < walk->data && walk->left != 0) ||
		(node->data > walk->data && walk->right != 0))
	{
		if (node->data > walk->data)
			walk = walk->right;
		else
		{
			++(walk->index);
			walk = walk->left;
		}
	}
	append_leaf(walk, node);
}

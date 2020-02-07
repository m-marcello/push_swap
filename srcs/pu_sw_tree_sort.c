/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_tree_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:01:42 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/07 20:53:38 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

static void		update_indices(int data, t_clist *branch)
{
	if (branch->data > data)
		branch->index++;
	if (branch->left != 0 && branch->left->data > data)
		update_indices(data, branch->left);
	if (branch->right != 0)
		update_indices(data, branch->right);
}

static void		append_leaf(t_clist *branch, t_clist *leaf)
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
		leaf->index = branch->index;
	}
}

static void		grow_tree(t_stack *stack, t_clist *node)
{
	t_clist	*walk;

	if (stack->trunk == 0)
	{
		stack->trunk = node;
		node->index = 1;
		return ;
	}
	walk = stack->trunk;
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
	update_indices(node->data, stack->trunk);
}

void			tree_sort(t_stack *stack)
{
	t_clist			*node;
	unsigned int	count;

	if (stack->head == 0)
		return ;
	node = stack->head;
	count = stack->node_count;
	while (count > 0)
	{
		grow_tree(stack, node);
		node = node->next;
		--count;
	}
}

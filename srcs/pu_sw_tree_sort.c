/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_tree_sort.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:01:42 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/14 13:14:28 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** given the data of the last leaf that had been added, this function
** recursively updates the indices of all elements in the tree containing higher
** data
**
** params
**	int data		data of the last added node
**	t_clist	*branch	pointer to current element of the tree
** return
**	VOID
*/

static void		update_indices(int data, t_clist *branch)
{
	if (branch->data > data)
		branch->index++;
	if (branch->left != 0)
		update_indices(data, branch->left);
	if (branch->right != 0)
		update_indices(data, branch->right);
}

/*
** -------------------------------------------------------------------------- **
** appends the next node (leaf) to the tree branch
**
** params
**	t_clist *branch	pointer to branch to which the node needs to be added
**	t_clist	*leaf	pointer to node to be added to tree
** return
**	VOID
*/

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

/*
** -------------------------------------------------------------------------- **
** walks through the binary tree to find the position for the given next node
**
** params
**	t_stack *stack	pointer to struct representing stack
**	t_clist	*node	pointer to node to be added to tree
** return
**	VOID
*/

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
		else if (node->data < walk->data)
			walk = walk->left;
	}
	append_leaf(walk, node);
	update_indices(node->data, stack->trunk);
}

/*
** -------------------------------------------------------------------------- **
** sorts the stack in a binary tree and saves the index of the position of each
** node in the sorted stack
**
** params
**	t_stack *stack	pointer to struct representing stack
** return
**	VOID
*/

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

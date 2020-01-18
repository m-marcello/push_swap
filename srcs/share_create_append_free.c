/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   share_create_append_free.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 14:25:06 by mmarcell       #+#    #+#                */
/*   Updated: 2020/01/18 16:52:41 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "share.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** sets the values of one node of the stack to 0 and frees its pointer
**
** params
**	t_stack **node	pointer to the node
*/

static void	free_node(t_clist **node)
{
	(*node)->next = 0;
	(*node)->prev = 0;
	(*node)->data = 0;
	free(*node);
	*node = 0;
}

/*
** -------------------------------------------------------------------------- **
** walks through the stack to save each node
**
** params
**	t_stack **stack	pointer to struct representing stack
*/

void		free_stack(t_stack **stack)
{
	t_clist	*walk;

	if (*stack == 0)
		return ;
	walk = (*stack)->head->next;
	(*stack)->head->prev->next = 0;
	free_node(&((*stack)->head));
	while (walk)
	{
		walk = walk->next;
		free_node(&(walk->prev));
	}
	(*stack)->head = 0;
	(*stack)->node_count = 0;
	free(*stack);
	*stack = 0;
}

/*
** -------------------------------------------------------------------------- **
** frees an array of strings and sets everything to 0
**
** params
**	char	***arr	address of the string array
*/

void		free_str_arr(char ***str_arr)
{
	int		i;
	int		j;

	i = 0;
	while ((*str_arr)[i])
	{
		j = 0;
		while ((*str_arr)[i][j])
		{
			(*str_arr)[i][j] = 0;
			j++;
		}
		free((*str_arr)[i]);
		(*str_arr)[i] = 0;
		i++;
	}
	free(**str_arr);
	**str_arr = 0;
}

/*
** -------------------------------------------------------------------------- **
** creates one node of t_clist and initializes it
**
** params
**	t_clist **node	addres to node that needs to be crated
**	int data		integer item of the stack for this node
** return
**	1				when everything went fine
**	0				in case of error
*/

static int	create_node(t_clist **node, int data)
{
	*node = malloc(sizeof(t_clist));
	if (*node == 0)
		return (0);
	(*node)->data = data;
	(*node)->next = (*node);
	(*node)->prev = (*node);
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** appends the entries from an array of strings to the stack
** if there is no stack yet it will be created
**
** params
**	int data		data for the node to be appended to stack
**	t_stack **stack	pointer to struct representing stack
** return
**	1				when everthing went fine
**	0				in case of error
*/

int			append_to_stack(int data, t_stack **stack)
{
	t_clist	*new_node;

	if (create_node(&new_node, data) == 0)
		return (0);
	if ((*stack)->head == 0)
		(*stack)->head = new_node;
	else if ((*stack)->head->next == (*stack)->head->prev)
	{
		(*stack)->head->next = new_node;
		(*stack)->head->prev = new_node;
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->head;
	}
	else
	{
		new_node->next = (*stack)->head;
		new_node->prev = (*stack)->head->prev;
		(*stack)->head->prev = new_node;
	}
	return (1);
}

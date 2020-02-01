/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pu_sw_sorting_helpers.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:22:33 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/01 16:51:02 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pu_sw.h"

/*
** -------------------------------------------------------------------------- **
** checks if the data of one node is in between two other nodes
** prev->data < node->data < next->data
**
** params
**	t_clist *node	pointer to node that wants to be placed between
**	t_clist *prev	pointer to prev node
**	t_clist *next	pointer to next node
** return
**	1				if node fits between
**	0				if it doesn't
*/

int		does_it_fit(t_clist *node, t_clist *prev, t_clist *next)
{
	return (prev->data < node->data && node->data < next->data);
}

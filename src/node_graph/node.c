/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:34:28 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 19:34:29 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>
#include <stdlib.h>
#include <string.h>

t_node		*new_node(char *name)
{
	t_node	*node;

	if (!(node = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	node->name = name;
	node->links = NULL;
	node->path = 0;
	return (node);
}

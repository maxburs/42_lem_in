/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 18:52:02 by mburson           #+#    #+#             */
/*   Updated: 2017/03/04 18:52:04 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lem_in.h>
#include <string.h>
#include <ft_printf.h>
#include <stdbool.h>

/*
** finds the first node with the specified property
*/

t_node			*node_with_property(t_node *graph, char const *property)
{
	while (graph->name)
	{
		if (graph->property && ft_strcmp(graph->property, (char*)property) == 0)
			return (graph);
		graph++;
	}
	if (g_flags & FLAG_VERBOSE)
		ft_printf("could not find node with property: %s\n", property);
	return (NULL);
}

/*
** finds the end of the line
*/

char const		*line_end(char const *line)
{
	while (*line != '\n' && *line != '\0')
		line++;
	return (line);
}

static char const	*g_valid_props[] = {
	"start",
	"end",
	NULL
};

_Bool			is_prop_valid(char const *property)
{
	size_t	i;

	i = 0;
	while (g_valid_props[i])
	{
		if (ft_strcmp((char*)g_valid_props[i], (char*)property) == 0)
			return (true);
		i++;
	}
	if (g_flags & FLAG_VERBOSE)
		ft_printf("property %s is invalid\n\n", property);
	return (false);
}

int				duplicate_props(struct s_node *graph)
{
	char			*prop;
	struct s_node	*graph2;

	while (graph->name)
	{
		if (graph->property)
		{
			prop = graph->property;
			graph2 = graph + 1;
			while (graph2->name)
			{
				if (graph2->property
						&& ft_strcmp(graph2->property, prop) == 0)
				{
					if (g_flags & FLAG_VERBOSE)
						ft_printf("duplicate property: %s\n", prop);
					return (-1);
				}
				graph2++;
			}
		}
		graph++;
	}
	return (0);
}

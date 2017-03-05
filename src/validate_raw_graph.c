/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:31:34 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 19:31:35 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>
#include <lem_in.h>

static void			error_on_line(char const *graph_raw, char const *ptr)
{
	size_t			line_number;
	char const		*line;

	line_number = 1;
	while (graph_raw < ptr)
	{
		if (*graph_raw == '\n')
		{
			line_number++;
			line = graph_raw + 1;
		}
		graph_raw++;
	}
	if (g_flags & FLAG_VERBOSE)
		ft_printf("farm validation error on line %zu\n", line_number);
	print_line("line:", line);
}

static _Bool		validate_ant_count(char const **ptr)
{
	while (ft_isdigit(**ptr))
		*ptr = *ptr + 1;
	if (**ptr != '\n')
	{
		return (1);
	}
	*ptr = *ptr + 1;
	return (0);
}

static _Bool		validate_room(char const *ptr)
{
	print_line("validating room: ", ptr);
	if (*ptr == '#')
	{
		ptr = ft_strchr(ptr, '\n') + 1;
		return (0);
	}
	while (!ft_strchr(ROOM_NAME_EXCLUDES, *ptr))
		ptr = ptr + 1;
	if (*ptr != ' ')
		return (1);
	ptr = ptr + 1;
	while (ft_isdigit(*ptr))
		ptr = ptr + 1;
	if (*ptr != ' ')
		return (1);
	ptr = ptr + 1;
	while (ft_isdigit(*ptr))
		ptr = ptr + 1;
	if (*ptr != '\0' && *ptr != '\n')
		return (1);
	return (0);
}

static _Bool		validate_link(char const *ptr)
{
	print_line("validating link: ", ptr);
	if (*ptr == '#')
	{
		ptr = ft_strchr(ptr, '\n') + 1;
		return (0);
	}
	while (!ft_strchr(ROOM_NAME_EXCLUDES, *ptr))
		ptr = ptr + 1;
	if (*ptr != '-')
		return (1);
	ptr = ptr + 1;
	while (!ft_strchr(ROOM_NAME_EXCLUDES, *ptr))
		ptr = ptr + 1;
	if (*ptr != '\0' && *ptr != '\n')
		return (1);
	return (0);
}

int					validate_raw_graph(char *graph_raw)
{
	char const		*ptr;

	ptr = graph_raw;
	validate_ant_count(&ptr);
	while (validate_room(ptr) == 0)
	{
		ptr = ft_strchr(ptr, '\n');
		if (ptr)
			ptr++;
		else
			return (0);
	}
	while (validate_link(ptr) == 0)
	{
		ptr = ft_strchr(ptr, '\n');
		if (ptr)
			ptr++;
		else
			return (0);
	}
	error_on_line(graph_raw, ptr);
	return (1);
}

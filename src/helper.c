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
#include <stdbool.h>
#include <lem_in.h>
#include <string.h>
#include <ft_printf.h>

void			print_line(char const *title, char const *line)
{
	if ((g_flags & FLAG_VVERBOSE) == false)
		return ;
	ft_putstr(title);
	while (*line != '\n' && *line != '\0')
	{
		ft_putchar(*line);
		line++;
	}
	ft_putchar('\n');
}

char const		*line_end(char const *line)
{
	while (*line != '\n' && *line != '\0')
		line++;
	return (line);
}

void			print_graph(t_node *node)
{
	while (node->name)
	{
		ft_printf("%16s: ", node->name);
		//connections will be printed here
		if (node->property)
			ft_printf("(%s)", node->property);
		ft_putchar('\n');
		node++;
	}
}

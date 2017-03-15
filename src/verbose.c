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

#include <ft_printf.h>
#include <lem_in.h>
#include <libft.h>

void	print_line(char const *title, char const *line)
{
	if (!(g_flags & FLAG_VERBOSE))
		return ;
	ft_putstr(title);
	while (*line != '\n' && *line != '\0')
	{
		ft_putchar(*line);
		line++;
	}
	ft_putchar('\n');
}

void	print_graph(t_node *node)
{
	t_listm		*link;

	if (!(g_flags & FLAG_VERBOSE))
		return ;
	ft_putstr("\e[33;1mbuilt graph:\e[0m\n\n");
	while (node->name)
	{
		if (node->property)
			ft_printf("   %0s##%s\n", "", node->property);
		ft_printf("   %-8s ", node->name);
		link = node->links;
		while (link)
		{
			ft_putstr(((t_node*)(link->content))->name);
			link = link->next;
			if (link)
				ft_putchar(',');
			ft_putchar(' ');
		}
		ft_printf(" (%d)", node->distance);
		ft_putchar('\n');
		node++;
	}
	ft_putchar('\n');
}

void	putverbose(char const *str)
{
	if (!(g_flags & FLAG_VERBOSE))
		return ;
	ft_putstr(str);
}

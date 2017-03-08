/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 20:43:10 by mburson           #+#    #+#             */
/*   Updated: 2017/02/23 20:43:12 by mburson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <stdbool.h>
#include <lem_in.h>

char	*get_raw_graph(void)
{
	t_lstr	*graph;
	int		ret;
	char	buff[BUFF_SIZE + 1];

	graph = NULL;
	while ((ret = read(0, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		ft_lstr_add(&graph, ft_strdup(buff), false);
	}
	return (ft_lstr_finish(&graph));
}

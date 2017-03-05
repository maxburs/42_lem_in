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

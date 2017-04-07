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

_Bool		is_node(const char *spot)
{
	int		space_count;

	if (*spot == '#')
		return (false);
	space_count = 0;
	while (*spot++ != '\n' && *spot != '\0')
	{
		if (*spot == ' ')
			space_count++;
	}
	if (space_count != 2)
		return (false);
	return (true);
}

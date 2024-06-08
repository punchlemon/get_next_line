/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:23:47 by retanaka          #+#    #+#             */
/*   Updated: 2024/06/06 18:23:48 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_mem	*create_mem(int fd)
{
	t_mem	*new;

	new = (t_mem *)malloc(sizeof(t_mem));
	if (new != NULL)
	{
		new->fd = fd;
		new->str = NULL;
		new->len = 0;
		new->nl_point = 0;
		new->nl_flag = 0;
		new->next_eol = 0;
		new->still_eol = 0;
		new->read_error = 0;
		new->prev = new;
		new->next = new;
	}
	return (new);
}

t_mem	*add_mem(t_mems *mems, int fd)
{
	t_mem	*sep;
	t_mem	*prev;
	t_mem	*new;

	sep = mems->sep;
	prev = sep->prev;
	new = create_mem(fd);
	if (new != NULL)
	{
		prev->next = new;
		sep->prev = new;
		new->prev = prev;
		new->next = sep;
	}
	return (new);
}

t_mem	*find_mem(t_mems *mems, int fd)
{
	t_mem	*sep;
	t_mem	*mem;

	sep = mems->sep;
	mem = sep->next;
	while (mem != sep)
	{
		if (mem->fd == fd)
			break ;
		mem = mem->next;
	}
	return (mem);
}

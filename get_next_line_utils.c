/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:20:09 by retanaka          #+#    #+#             */
/*   Updated: 2024/06/05 15:20:12 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		*(char *)(dst + i) = *(char *)(src + i);
	return (dst);
}

void	*clear_str(char *str, size_t len)
{
	size_t	i;

	if (str != NULL)
	{
		i = 0;
		while (i < len)
		{
			str[i] = 0;
			i++;
		}
		free(str);
	}
	return (NULL);
}

size_t	end_mem(t_mem *mem)
{
	mem->nl_flag = 0;
	mem->nl_point = 0;
	mem->next_eol = 0;
	mem->still_eol = 0;
	mem->read_error = 0;
	if (mem->str != NULL)
		free(mem->str);
	mem->str = NULL;
	mem->len = 0;
	return (1);
}

size_t	check_nl(t_mem *mem)
{
	size_t	i;

	mem->nl_flag = 0;
	i = 0;
	while (i < mem->len)
	{
		if (mem->str[i++] == '\n')
		{
			mem->nl_flag = 1;
			break ;
		}
	}
	mem->nl_point = i;
	return (mem->nl_flag);
}

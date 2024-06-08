/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:04:12 by retanaka          #+#    #+#             */
/*   Updated: 2024/06/05 15:19:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_mem	mem;
	char			*result;

	mem.fd = fd;
	if (read_mem(&mem))
		return (NULL);
	result = NULL;
	if (split_nl(&mem, &result))
		return (NULL);
	return (result);
}

size_t	read_mem(t_mem *mem)
{
	char		buff[BUFFER_SIZE];
	ssize_t		len;

	if (mem->read_error || mem->still_eol)
		return (0);
	while (!(check_nl(mem)) && !mem->still_eol
		&& !mem->next_eol)
	{
		len = read(mem->fd, buff, BUFFER_SIZE);
		mem->read_error = (len == -1);
		mem->still_eol = (len == 0);
		if (mem->read_error || mem->still_eol)
			return (0);
		mem->next_eol = ((len > 0) && (len < BUFFER_SIZE));
		if (cat_mem(mem, buff, len))
			return (end_mem(mem));
	}
	return (0);
}

size_t	cat_mem(t_mem *mem, char *src, size_t src_len)
{
	char	*new;
	size_t	str_len;
	size_t	result_len;

	str_len = mem->len;
	result_len = str_len + src_len;
	if (result_len < str_len || result_len < src_len)
		return (end_mem(mem));
	if (result_len > 0)
	{
		new = (char *)malloc(result_len + 1);
		if (new == NULL)
			return (end_mem(mem));
		ft_memcpy(new, mem->str, str_len);
		ft_memcpy(new + str_len, src, src_len);
		free(mem->str);
		new[result_len] = '\0';
		mem->str = new;
		mem->len = result_len;
		return (0);
	}
	else
		return (end_mem(mem));
}

size_t	split_nl(t_mem *mem, char **result)
{
	char	*remain;
	size_t	remain_len;

	if (mem->read_error && !check_nl(mem))
		return (end_mem(mem));
	remain_len = mem->len - mem->nl_point;
	if (set_str(mem, result, mem->str, mem->nl_point))
		return (1);
	if (set_str(mem, &remain, mem->str + mem->nl_point, remain_len))
	{
		free(*result);
		*result = NULL;
		return (1);
	}
	free(mem->str);
	mem->str = remain;
	mem->len = remain_len;
	if ((mem->next_eol || mem->still_eol) && mem->len == 0)
	{
		if (!mem->still_eol)
			read(mem->fd, *result, BUFFER_SIZE);
		end_mem(mem);
	}
	return (0);
}

size_t	set_str(t_mem *mem, char **dst, char *src, size_t len)
{
	char	*result;

	if (len == 0)
	{
		*dst = NULL;
		return (0);
	}
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (end_mem(mem));
	ft_memcpy(result, src, len);
	result[len] = '\0';
	*dst = result;
	return (0);
}

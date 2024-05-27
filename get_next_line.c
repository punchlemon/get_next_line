/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/27 19:16:45 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	check_nl(char *s, int *nl_flag)
{
	int	i;

	*nl_flag = 0;
	if (s == NULL || *s == '\0')
		return (0);
	i = 0;
	while (*nl_flag != 1 && s[i])
	{
		if (s[i++] == '\n')
			*nl_flag = 1;
	}
	return (i);
}

t_string	split_by_nl(t_string *src, int *end_split)
{
	t_string	new;
	t_string	result;
	ssize_t		nl;
	int			nl_flag;

	if (*end_split)
	{
		clear_t_string(src);
		return (*src);
	}
	nl = check_nl(src->str, &nl_flag);
	if (nl_flag == 0)
		*end_split = 1;
	create_t_string(&result, nl);
	copy_t_string(result, src->str, 0, 0);
	create_t_string(&new, src->len - result.len);
	copy_t_string(new, src->str + result.len, 0, 0);
	clear_t_string(src);
	*src = new;
	return (result);
}

void	read_buffer(int fd, t_string *src, int *end_read, int end_split)
{
	char		buff[BUFFER_SIZE];
	t_string	buffer;
	int			nl_flag;

	if (end_split || *end_read)
		return ;
	while (!*end_read)
	{
		create_t_string(&buffer, read(fd, buff, BUFFER_SIZE));
		copy_t_string(buffer, buff, 0, 0);
		if (buffer.len < BUFFER_SIZE)
			*end_read = 1;
		if (buffer.len < 0)
			return ;
		append_t_string(src, buffer);
		clear_t_string(&buffer);
		if (src->str == NULL)
			return ;
		check_nl(src->str, &nl_flag);
		if (nl_flag == 1)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static t_string	src;
	static int		end_read;
	static int		end_split;
	t_string		result;

	read_buffer(fd, &src, &end_read, end_split);
	result = split_by_nl(&src, &end_split);
	return (result.str);
}

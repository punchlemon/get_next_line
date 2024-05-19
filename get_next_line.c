/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/19 21:54:11 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

ssize_t	check_nl(char *s)
{
	int	i;

	if (s == NULL)
		return (-1);
	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			if (s[i++] == '\n')
				return (i);
		}
	}
	return (0);
}

char	*split_by_nl(char **str, int end_out_flag)
{
	char	*result;
	char	*new_str;
	ssize_t	result_len;
	ssize_t	new_str_len;

	if (end_out_flag)
		return (*str);
	result_len = check_nl(*str) + 1;
	new_str_len = ft_strlen(*str) - result_len;
	if (result_len != 0)
	{
		result = (char *)malloc((result_len + 1) * sizeof(char));
		ft_memcpy(result, *str, result_len);
		result[result_len] = '\0';
	}
	else
		result = NULL;
	if (new_str_len != 0)
	{
		new_str = (char *)malloc((new_str_len + 1) * sizeof(char));
		ft_memcpy(new_str, *str + result_len, new_str_len);
		new_str[new_str_len] = '\0';
	}
	else
		new_str = NULL;
	if (*str != NULL)
		free(*str);
	*str = new_str;
	return (result);
}

char	*get_next_line(int fd)
{
	ssize_t		str_len;
	static int	end_read_flag;
	static int	end_out_flag;
	static char	*str;

	if (end_out_flag)
		return (NULL);
	while (!end_read_flag && check_nl(str) <= 0)
	{
		str_len = read_buffer(fd, &str);
		if (str_len < 0)
			return (NULL);
		if (str_len < BUFFER_SIZE)
			end_read_flag = 1;
	}
	if (end_read_flag == 1 && check_nl(str) <= 0)
		end_out_flag = 1;
	return (split_by_nl(&str, end_out_flag));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/14 16:53:30 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*null_terminate(char *str, int str_len)
{
	char	*result;
	int		i;

	result = (char *)malloc((str_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	ssize_t		str_len;
	static int	end_flag;
	static int	count;

	str_len = read_buffer(fd);
	if (str_len < 0)
		return (NULL);
	return (NULL);
	// if (BUFFER_SIZE < 0 || (count == 0 && end_flag == 1))
	// 	return (NULL);
	// count++;
	// while (check_nl(str, str_len) == -1 && end_flag == 0)
	// 	str_len = read_buffer(fd, &str, str_len, &end_flag);
	// if (end_flag == 1)
	// 	return (null_terminate(str, str_len));
	// return (split_by_nl(&str, &str_len));
}

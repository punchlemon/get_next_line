/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/12 05:08:08 by retanaka         ###   ########.fr       */
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
	static char	*str;
	static int	str_len;
	static int	end_flag;

	if (BUFFER_SIZE < 0 || end_flag == 1 || fd == -1)
		return (NULL);
	while (check_nl(str, str_len) == -1 && end_flag == 0)
		str_len = read_buffer(fd, &str, str_len, &end_flag);
	if (end_flag == 1)
		return (null_terminate(str, str_len));
	return (split_by_nl(&str, &str_len));
}

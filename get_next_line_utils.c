/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:56:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/17 21:19:31y retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *s)
{
	ssize_t	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_memcpy(char *dst, char *src, ssize_t n)
{
	if (src == NULL || dst == NULL)
		return (NULL);
	while (--n >= 0)
		dst[n] = src[n];
	return (dst);
}

char	*append_str(char *str, char *buffer, int buffer_len)
{
	ssize_t	str_len;
	char	*result;

	if (buffer_len == 0)
		return (str);
	str_len = ft_strlen(str);
	result = (char *)malloc((str_len + buffer_len + 1) * sizeof(char));
	if (result != NULL)
	{
		ft_memcpy(result, str, str_len);
		ft_memcpy(result + str_len, buffer, buffer_len);
		result[str_len + buffer_len] = '\0';
	}
	if (str != NULL)
		free(str);
	return (result);
}

ssize_t	read_buffer(int fd, char **str, int *end_read_flag)
{
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;

	if (*end_read_flag == 1)
		return (-1);
	// if (end_out_flag == 1)
	// 	return (-2);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (-3);
	if (bytes_read < BUFFER_SIZE)
		*end_read_flag = 1;
	*str = append_str(*str, buffer, bytes_read);
	if (*str == NULL)
		return (-4);
	return (bytes_read);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:56:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/27 09:08:47 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	string_len(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*string_concatenate(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	size_t	i;
	size_t	j;

	s1_len = string_len(s1);
	s2_len = string_len(s2);
	if (s1_len == 0 && s2_len == 0)
		return (NULL);
	if (s2_len == 0)
		return (s1);
	result = (char *)malloc(s1_len + s2_len + 1);
	if (result == NULL)
		return (s1);
	i = 0;
	j = 0;
	while (i < s1_len)
		result[i++] = s1[j++];
	j = 0;
	while (i < s2_len)
		result[i++] = s2[j++];
	result[i] = '\0';
	if (s1 != NULL)
		free(s1);
	return (result);
}

int	check_nl(char *s, int bytes)
{
	int	i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (i < bytes)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*split_by_nl(char **str, int *str_len)
{
	char	*result;
	char	*new_str;
	int		result_len;
	int		new_str_len;
	int		i;
	int		j;

	result_len = check_nl(*str, *str_len) + 1;
	new_str_len = *str_len - result_len;
	result = (char *)malloc((result_len + 1) * sizeof(char));
	new_str = (char *)malloc(new_str_len * sizeof(char));
	if (result == NULL || new_str == NULL)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		result[i] = (*str)[i];
		i++;
	}
	result[i] = '\0';
	j = 0;
	while (j < new_str_len)
	{
		new_str[j] = (*str)[i + j];
		j++;
	}
	*str = new_str;
	*str_len = new_str_len;
	return (result);
}

char	*str_str_concatenate(char *s1, char *s2, int s1_len, int s2_len)
{
	int		i;
	int		j;
	char	*result;

	result = (char *)malloc((s1_len + s2_len) * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		result[i + j] = s2[j];
		j++;
	}
	free(s1);
	return (result);
}

int	read_buffer(int fd, char **str, int str_len, int *end_flag)
{
	char		buffer[BUFFER_SIZE];
	int			bytes_read;

	if (*end_flag == 1)
		return (0);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < BUFFER_SIZE)
		*end_flag = 1;
	if (bytes_read == -1 || bytes_read == 0)
		return (0);
	*str = str_str_concatenate(*str, buffer, str_len, bytes_read);
	return (bytes_read + str_len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/17 21:46:49 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

// char	*null_terminate(char *str, int str_len)
// {
// 	char	*result;
// 	int		i;

// 	result = (char *)malloc((str_len + 1) * sizeof(char));
// 	if (result != NULL)
// 	{
// 		i = 0;
// 		while (i < str_len)
// 		{
// 			result[i] = str[i];
// 			i++;
// 		}
// 		result[i] = '\0';
// 	}
// 	if (str != NULL)
// 		free(str);
// 	return (result);
// }

ssize_t	check_nl(char *s)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			if (s[i] == '\n')
				return (i);
			i++;
		}
	}
	return (-1);
}

char	*split_by_nl(char **str, ssize_t *str_len)
{
	char	*result;
	char	*new_str;
	ssize_t	result_len;
	ssize_t	new_str_len;

	result_len = check_nl(*str) + 1;
	new_str_len = *str_len - result_len;
	result = (char *)malloc((result_len + 1) * sizeof(char));
	new_str = (char *)malloc((new_str_len + 1) * sizeof(char));
	ft_memcpy(result, *str, result_len);
	result[result_len] = '\0';
	ft_memcpy(new_str, *str + result_len, new_str_len);
	new_str[new_str_len] = '\0';
	if (*str != NULL)
		free(*str);
	*str = new_str;
	return (result);
}

char	*get_next_line(int fd)
{
	ssize_t		str_len;
	static int	end_read_flag;
	// static int	end_out_flag;
	static char	*str;

	if (BUFFER_SIZE < 0)
		return (NULL);
	str_len = read_buffer(fd, &str, &end_read_flag);
	if (str_len < -1)
		return (NULL);
	while (check_nl(str) == -1 && str_len >= 0)
		str_len = read_buffer(fd, &str, &end_read_flag);
	if (str_len < 0)
		return (NULL);
	return (split_by_nl(&str, &str_len));
}

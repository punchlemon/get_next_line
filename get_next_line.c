/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:31:16 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/07 13:18:24 by retanaka         ###   ########.fr       */
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

// #include <stdio.h>
// #include <fcntl.h>
// int	main(void)
// {
// 	int		fd;
// 	char	*s;
// 
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1) {
// 		write(1, "fail\n", 5);
// 		return 1;
// 	}
// 	s = NULL;
// 	while (1)
// 	{
// 		s = get_next_line(fd);
// 		if (s == NULL)
// 			return (0);
// 		printf("%s", s);
// 		free(s);
// 	}
// 	close(fd);
// }

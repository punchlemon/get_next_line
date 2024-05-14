/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:49:30 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/14 16:45:19 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		write(1, "fail\n", 5);
		return (1);
	}
	s = NULL;
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			return (0);
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 04:52:58 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/12 04:52:59 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	int		fd;
	char	*s;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1) {
		write(1, "fail\n", 5);
		return 1;
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
}

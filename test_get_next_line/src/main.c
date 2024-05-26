/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:49:30 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/27 05:18:18 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("files/test1.txt", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break;
		printf("%s", s);
	}
	close(fd);
	return (0);
}

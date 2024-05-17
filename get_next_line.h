/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:37:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/17 21:47:42 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

ssize_t	ft_strlen(char *s);
char	*ft_memcpy(char *dst, char *src, ssize_t n);
char	*append_str(char *str, char *buffer, int buffer_len);
ssize_t	read_buffer(int fd, char **str, int *end_read_flag);
ssize_t	check_nl(char *s);
char	*split_by_nl(char **str, ssize_t *str_len);
char	*get_next_line(int fd);

#endif

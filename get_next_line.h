/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:37:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/31 20:32:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE >= 8000000 || BUFFER_SIZE <= 0
#  error "The BUFFER_SIZE must be a value between 1 and 8000000."
# endif

typedef struct s_string
{
	char	*str;
	ssize_t	len;
}	t_string;

void		copy_t_string(t_string dst, char *src, ssize_t start, ssize_t end);
void		split_t_string(t_string *new, t_string *src, ssize_t len);
void		append_t_string(t_string *dst, t_string buffer);
void		create_t_string(t_string *dst, ssize_t len);
void		clear_t_string(t_string *src);
ssize_t		check_nl(char *s, int *nl_flag);
t_string	split_by_nl(t_string *src, int *end_split);
void		read_buffer(int fd, t_string *str, int *end_read, int end_split);
char		*get_next_line(int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:37:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/04/27 09:08:52 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int		string_len(char *s);
char	*string_concatenate(char *s1, char *s2);
int		check_nl(char *s, int bytes);
char	*split_by_nl(char **str, int *str_len);
char	*str_str_concatenate(char *s1, char *s2, int s1_len, int s2_len);
int		read_buffer(int fd, char **str, int str_len, int *end_flag);
char	*get_next_line(int fd);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:37:46 by retanaka          #+#    #+#             */
/*   Updated: 2024/06/07 22:55:44 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H
# include "get_next_line.h"

typedef struct s_mems
{
	t_mem	*sep;
}	t_mems;

t_mem	*create_mem(int fd);
t_mem	*add_mem(t_mems *mems, int fd);
t_mem	*find_mem(t_mems *mems, int fd);

#endif

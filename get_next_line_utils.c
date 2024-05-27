/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: retanaka <retanaka@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:56:18 by retanaka          #+#    #+#             */
/*   Updated: 2024/05/27 19:16:10 by retanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_t_string(t_string dst, char *src, ssize_t start, ssize_t end)
{
	ssize_t	i;

	if (start >= 0 && dst.len - end > start && dst.str != NULL && src != NULL)
	{
		i = -1;
		while (++i + start < dst.len - end)
			dst.str[i + start] = src[i];
		dst.str[dst.len] = '\0';
	}
}

void	split_t_string(t_string *new, t_string *src, ssize_t len)
{
	t_string	tmp;

	if (len < 1 || src->len < len)
		return ;
	create_t_string(new, len);
	if (new->str != NULL && src->str != NULL)
	{
		copy_t_string(*new, src->str, 0, 0);
		create_t_string(&tmp, src->len - new->len);
		copy_t_string(tmp, src->str + new->len, 0, 0);
		clear_t_string(src);
		*src = tmp;
	}
}

void	append_t_string(t_string *dst, t_string buffer)
{
	t_string	result;

	if (buffer.len <= 0)
		return ;
	create_t_string(&result, dst->len + buffer.len);
	if (result.str != NULL)
	{
		copy_t_string(result, dst->str, 0, buffer.len);
		copy_t_string(result, buffer.str, dst->len, 0);
	}
	clear_t_string(dst);
	*dst = result;
}

void	create_t_string(t_string *dst, ssize_t len)
{
	if (len > 0)
	{
		dst->str = (char *)malloc((len + 1) * sizeof(char));
		if (dst->str == NULL)
			dst->len = 0;
		else
			dst->len = len;
	}
	else
	{
		dst->str = NULL;
		dst->len = 0;
	}
}

void	clear_t_string(t_string *src)
{
	if (src->str != NULL)
		free(src->str);
	src->str = NULL;
	src->len = 0;
}

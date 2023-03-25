/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:42:39 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 11:00:48 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			res;
	void			*p;

	res = count * size;
	if (!(p = malloc(res)))
		return (NULL);
	ft_bzero(p, res);
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 23:49:03 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 11:39:02 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char			*ft_strdup1(const char *s1)
{
	int			i;
	char		*s;
	char		*p_s1;
	int			len;

	i = 0;
	len = 0;
	p_s1 = (char*)s1;
	while (p_s1[len])
		len++;
	if (!p_s1 || !(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (p_s1[i])
	{
		s[i] = p_s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

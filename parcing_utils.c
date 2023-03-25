/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:25:59 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 18:28:37 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_color(int color_code)
{
	if (color_code >= 0 && color_code <= 255)
		return (1);
	else
		return (0);
}

void	color_init(t_rgb *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

int		vrf_arg_dg(char *tab, char *set)
{
	int		i;
	int		j;
	int		drapo;

	j = 0;
	i = 0;
	if (!tab || !*tab || !set)
		return (0);
	while (tab[i])
	{
		drapo = 0;
		j = 0;
		while (set[j])
		{
			if (tab[i] == set[j])
				drapo = 1;
			j++;
		}
		if (drapo == 0)
			return (0);
		i++;
	}
	return (1);
}

void	trait_space(t_var *v, char *line)
{
	char	*trim_line;

	trim_line = ft_strtrim(line, " ");
	if (trim_line && *trim_line != '1')
	{
		free(line);
		free(trim_line);
		free_cub_exit(v, MAP_ERROR);
	}
	free(trim_line);
}

int		directions(char x)
{
	if (x == 'N' || x == 'E' || x == 'S' || x == 'W')
		return (1);
	return (0);
}

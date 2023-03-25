/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vrf_res_flr_cl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:18:49 by moharras          #+#    #+#             */
/*   Updated: 2020/11/25 10:16:23 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					vrf_color_flr_ceil(char **tab)
{
	int				i;
	char			*tab_trim;

	i = 0;
	if (!tab || tab_len(tab) != 3)
		return (0);
	while (i < 3)
	{
		tab_trim = ft_strtrim(tab[i], " ");
		if (!vrf_arg_dg(tab_trim, "0123456987"))
		{
			free(tab_trim);
			return (0);
		}
		free(tab_trim);
		i++;
	}
	return (1);
}

void				val_flr_ceil_color(t_var *v, char c, t_rgb color)
{
	if (!is_color(color.r) || !is_color(color.g) || !is_color(color.b))
		free_cub_exit(v, ERROR_COLOR);
	if (c == 'F')
	{
		if (v->flr.r != -1 || v->flr.g != -1 || v->flr.b != -1)
			free_cub_exit(v, ERROR_DUPL);
		v->flr = color;
	}
	else if (c == 'C')
	{
		if (v->cl.r != -1 || v->cl.g != -1 || v->cl.b != -1)
			free_cub_exit(v, ERROR_DUPL);
		v->cl = color;
	}
}

void				flr_cel_color(char *line, t_var *v)
{
	char			**tab;
	char			*str;
	int				count;
	t_rgb			color;

	str = line;
	count = 0;
	if (str)
		while (*str)
			if (*str++ == ',')
				count++;
	if (count != 2)
		free_cub_exit(v, MAP_ERROR);
	tab = ft_split(line + 1, ',');
	if (!vrf_color_flr_ceil(tab))
	{
		free_tab2d(tab, tab_len(tab));
		free_cub_exit(v, ERROR_COLOR);
	}
	color.r = ft_atoi(tab[0]);
	color.g = ft_atoi(tab[1]);
	color.b = ft_atoi(tab[2]);
	free_tab2d(tab, 3);
	val_flr_ceil_color(v, *line, color);
}

void				check_res_card(char *line, t_var *v)
{
	if (*line == 'R')
	{
		v->check = 1;
		if (ft_strncmp(line, "R ", 2))
		{
			free(line);
			free_cub_exit(v, ERROR_RESOL);
		}
		else
			resolution(line, v);
	}
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
			!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
	{
		v->check = 1;
		cardinal_dir_path(line, v);
	}
	else if (*line == 'S')
	{
		v->check = 1;
		sprite_path(line, v);
	}
}

void				check_stuc_flr_cl(char *line, t_var *v)
{
	if (*line == 'F')
	{
		v->check = 1;
		if (ft_strncmp(line, "F ", 2))
		{
			free(line);
			free_cub_exit(v, ERROR_FLOOR);
		}
		else
			flr_cel_color(line, v);
	}
	else if (*line == 'C')
	{
		v->check = 1;
		if (ft_strncmp(line, "C ", 2))
		{
			free(line);
			free_cub_exit(v, ERROR_CEIL);
		}
		else
			flr_cel_color(line, v);
	}
}

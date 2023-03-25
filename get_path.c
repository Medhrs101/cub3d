/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:21:47 by moharras          #+#    #+#             */
/*   Updated: 2020/11/30 10:09:50 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	resolution(char *data, t_var *v)
{
	char	**tab;
	char	*s;

	s = "0625487913";
	if (v->rs_w != -1 || v->rs_h != -1)
		free_cub_exit(v, ERROR_DUPL);
	tab = ft_split(data, ' ');
	if (!tab || tab_len(tab) != 3 || !vrf_arg_dg(tab[1], s)
		|| !vrf_arg_dg(tab[2], s))
	{
		free_tab2d(tab, tab_len(tab));
		free_cub_exit(v, ERROR_RESOL);
	}
	v->rs_w = ft_atoi(tab[1]);
	v->rs_h = ft_atoi(tab[2]);
	if (v->rs_w <= 0 || v->rs_w <= 0)
	{
		free_tab2d(tab, tab_len(tab));
		free_cub_exit(v, ERROR_RESOL);
	}
	free_tab2d(tab, 3);
	if (v->rs_w > 2560)
		v->rs_w = 2560;
	if (v->rs_h > 1440)
		v->rs_h = 1440;
}

void	cardinal_dir_path(char *line, t_var *v)
{
	char	*path;

	v->check1 = 0;
	path = NULL;
	if (!(path = ft_strtrim(line + 2, " ")))
		free_cub_exit(v, EXEC_ERROR);
	if ((open(path, O_RDONLY)) == -1 || trait_ext(path, ".xpm") == 0)
	{
		free(path);
		free_cub_exit(v, ERROR_FILE);
	}
	get_path_no_so(line, v, path);
	get_path_we_ea(line, v, path);
	if (*line == 'S' && v->check1 == 0)
	{
		if (ft_strncmp(line, "S ", 2))
			free_cub_exit(v, ERROR_SPRITE);
		else if (v->p_sp != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_sp = path;
	}
}

void	get_path_no_so(char *line, t_var *v, char *path)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		v->check1 = 1;
		if (ft_strncmp(line, "NO ", 3))
			free_cub_exit(v, ERROR_NORTH);
		else if (v->p_no != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_no = path;
	}
	else if (!ft_strncmp(line, "SO", 2) && v->check1 == 0)
	{
		v->check1 = 1;
		if (ft_strncmp(line, "SO ", 3))
			free_cub_exit(v, ERROR_SOUTH);
		else if (v->p_so != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_so = path;
	}
}

void	get_path_we_ea(char *line, t_var *v, char *path)
{
	if (!ft_strncmp(line, "WE", 2) && v->check1 == 0)
	{
		v->check1 = 1;
		if (ft_strncmp(line, "WE ", 3))
			free_cub_exit(v, ERROR_WEST);
		else if (v->p_we != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_we = path;
	}
	else if (!ft_strncmp(line, "EA", 2) && v->check1 == 0)
	{
		v->check1 = 1;
		if (ft_strncmp(line, "EA ", 3))
			free_cub_exit(v, ERROR_EAST);
		else if (v->p_ea != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_ea = path;
	}
}

void	sprite_path(char *line, t_var *v)
{
	char *path;

	if (!(path = ft_strtrim(line + 1, " ")))
		free_cub_exit(v, EXEC_ERROR);
	if ((open(path, O_RDONLY)) == -1 || trait_ext(path, ".xpm") == 0)
	{
		free(path);
		free_cub_exit(v, ERROR_FILE);
	}
	if (*line == 'S')
	{
		if (ft_strncmp(line, "S ", 2))
			free_cub_exit(v, ERROR_SPRITE);
		else if (v->p_sp != NULL)
			free_cub_exit(v, ERROR_DUPL);
		else
			v->p_sp = path;
	}
}

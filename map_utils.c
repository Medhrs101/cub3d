/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:54:22 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 17:07:25 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					trait_ext(char *file_name, char *extension)
{
	int				lf;
	int				le;

	lf = ft_strlen(file_name);
	le = ft_strlen(extension);
	while (le--)
		if (file_name[--lf] != extension[le])
			return (0);
	return (1);
}

int					mx_hl(char **tab)
{
	int				i;
	int				mx;
	int				val;

	i = 0;
	mx = 0;
	while (tab[i])
	{
		if ((val = ft_strlen(tab[i])) > mx)
			mx = val;
		i++;
	}
	return (mx);
}

int					vrf_map(t_var *v)
{
	int				idx;

	idx = 1;
	if (!(v->mp.tb = ft_split(v->mp.tmp_mp, '\n')))
	{
		free(v->mp.tmp_mp);
		return (1);
	}
	free(v->mp.tmp_mp);
	if ((v->mp.axe.x = tab_len(v->mp.tb)) < 3 ||
		(v->mp.axe.y = mx_hl(v->mp.tb)) < 3 || !vrf_arg_dg(v->mp.tb[0], "1 ")
		|| !vrf_arg_dg(v->mp.tb[v->mp.axe.x - 1], " 1"))
		return (1);
	v->mp.flag = 0;
	while (idx < v->mp.axe.x - 1)
	{
		if (vrf_line_map(v, v->mp.tb[idx], idx))
			return (1);
		if (v->mp.val_dir == 1 && !v->mp.pos.x)
			v->mp.pos.x = (double)idx;
		idx++;
	}
	if (transposed(v))
		return (1);
	return (v->mp.val_dir != 1);
}

void				stock_map(int fd, char *line, t_var *v)
{
	int				r;
	char			*tmp;

	r = 1;
	v->mp.tmp_mp = line;
	while (r > 0)
	{
		if ((r = get_next_line(fd, &line)) == -1 && !close(fd))
		{
			free(line);
			free_cub_exit(v, ERROR_GNL);
		}
		if (line && (!*line || vrf_arg_dg(line, " ")) &&
				eof_vrf(fd, line, v) && !close(fd))
			break ;
		tmp = ft_strjoin(v->mp.tmp_mp, "\n");
		free(v->mp.tmp_mp);
		v->mp.tmp_mp = ft_strjoin(tmp, line);
		free(tmp);
		free(line);
	}
	if (vrf_map(v))
		free_cub_exit(v, MAP_ERROR);
}

int					eof_vrf(int fd, char *line, t_var *v)
{
	int				r;
	double			i;

	i = v->dir_x;
	i--;
	if (vrf_arg_dg(line, " ") && !close(fd))
	{
		free(line);
		free_cub_exit(v, MAP_ERROR);
	}
	r = 1;
	while (r > 0)
	{
		if ((r = get_next_line(fd, &line)) == -1 && !close(fd))
			free_cub_exit(v, MAP_ERROR);
		if (line && *line)
		{
			free(line);
			free_cub_exit(v, MAP_ERROR);
		}
		free(line);
	}
	return (r != 0 ? 1 : 0);
}

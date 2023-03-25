/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:17:12 by moharras          #+#    #+#             */
/*   Updated: 2020/11/24 18:19:24 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		dir_coord_sp(t_var *v, char *line, int idx)
{
	int	i;

	i = ft_strlen(line);
	while (i--)
	{
		if (directions(line[i]))
		{
			v->mp.card_dir = line[i];
			v->mp.pos.y = (double)i;
			v->mp.val_dir++;
		}
		else if (line[i] == '2')
		{
			v->sprite.coord[v->sprite.count].x = idx;
			v->sprite.coord[v->sprite.count].y = i;
			v->sprite.count++;
		}
	}
	return (v->mp.val_dir > 1);
}

int		vrf_line_map(t_var *v, char *line, int idx)
{
	int		j;
	char	**tab;

	j = 0;
	if (!v->mp.flag && !vrf_arg_dg(line, "NSWE 012"))
		return (1);
	tab = ft_split(line, ' ');
	while (tab[j])
	{
		if (tab[j][0] != '1' || tab[j][ft_strlen(tab[j]) - 1] != '1')
		{
			free_tab2d(tab, tab_len(tab));
			return (1);
		}
		j++;
	}
	free_tab2d(tab, tab_len(tab));
	return (v->mp.flag == 1 ? 0 : dir_coord_sp(v, line, idx));
}

void	vrf_cub(t_var *v)
{
	int	i;

	i = 1;
	if (v->cl.b == -1 || v->cl.b == -1)
		i = 0;
	if (!v->p_ea || !v->p_no || !v->p_so || !v->p_we)
		i = 0;
	if (!v->p_sp || !v->mp.tb || v->rs_w == -1 || v->rs_h == -1)
		i = 0;
	if (i == 0)
		free_cub_exit(v, MAP_ERROR);
}

int		check_line(t_var *v, char *line, int fd)
{
	v->check = 0;
	check_res_card(line, v);
	check_stuc_flr_cl(line, v);
	if (v->check == 0 && (*line == '1' || *line == ' '))
	{
		trait_space(v, line);
		stock_map(fd, line, v);
		return (1);
	}
	else if (v->check == 0 && !*line)
		return (0);
	else if (v->check == 0)
	{
		free(line);
		free_cub_exit(v, MAP_ERROR);
	}
	return (0);
}

void	check_file_map(t_var *v, char *file_map)
{
	int		r;
	int		fd;
	char	*line;

	r = 1;
	if ((fd = open(file_map, O_RDONLY)) == -1)
		trait_error(ERROR_FILE);
	if (trait_ext(file_map, ".cub") == 0)
		trait_error(EXT_ERROR);
	line = NULL;
	while (r > 0)
	{
		if ((r = get_next_line(fd, &line)) == -1 && !close(fd))
		{
			free(line);
			free_cub_exit(v, ERROR_GNL);
		}
		if (check_line(v, line, fd) == 1)
			break ;
		free(line);
	}
	vrf_cub(v);
	close(fd);
}

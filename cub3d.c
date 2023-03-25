/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:14:01 by moharras          #+#    #+#             */
/*   Updated: 2020/11/27 12:16:26 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	raycast_1(t_var *v)
{
	init_raycast(v);
	step_init_dist(v);
	dda(v);
	start_draw_end(v);
	draw_line_ceilling(v);
	draw_line_floor(v);
	coord_tex(v);
	v->sprit.z_buffer[v->x] = v->pw_dst;
}

int		draw_walls(t_var *v)
{
	v->x = 0;
	if (v->save == 0)
		mlx_clear_window(v->mlx_ptr, v->win_ptr);
	v->texture = (int *)mlx_get_data_addr(v->mlx_img,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	v->data_fl_cl = (int *)mlx_get_data_addr(v->mlx_img,
			&v->bits_per_pixel, &v->size_line, &v->endian);
	trait_key(v);
	while (v->x < v->rs_w)
	{
		raycast_1(v);
		v->x++;
	}
	sprite_1(v);
	if (v->save == 0)
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->mlx_img, 0, 0);
	else
		draw_in_file(v);
	return (0);
}

int		main(int argc, char **av)
{
	t_var	v;

	if (argc == 1)
		trait_error(ARG_NOT_FOUND);
	v.save = 0;
	if (argc == 3 && !ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		v.save = 1;
	if (argc == 3 && ft_strncmp(av[2], "--save", ft_strlen(av[2])))
		trait_error(ERROR_ARG);
	if (argc > 4)
		trait_error(ERROR_ARG);
	cub_initial(&v);
	check_file_map(&v, av[1]);
	rc_initial(&v);
	start_game(&v);
	return (0);
}

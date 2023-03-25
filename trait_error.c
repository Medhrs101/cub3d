/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moharras <moharras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:43:23 by moharras          #+#    #+#             */
/*   Updated: 2020/11/25 10:05:28 by moharras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cont_trai_err(int ops)
{
	if (ops == ERROR_WEST)
		ft_putstr_fd("ERROR WEST\n", 1);
	else if (ops == ERROR_EAST)
		ft_putstr_fd("ERROR EAST\n", 1);
	else if (ops == ERROR_SPRITE)
		ft_putstr_fd("ERROR SPRITE\n", 1);
	else if (ops == EXT_ERROR)
		ft_putstr_fd("FILE EXTENTION IS NOT '.cub' !\n", 1);
	else if (ops == ERROR_SAVE)
		ft_putstr_fd("COULD NOT SAVE FIRST FRAME !\n", 1);
	else if (ops == MAP_ERROR)
		ft_putstr_fd("MAP_ERROR\n", 1);
	else if (ops == ERROR_DUPL)
		ft_putstr_fd("REPITITION", 1);
	else if (ops == ERROR_COLOR)
		ft_putstr_fd("ERROR COLOR", 1);
	else if (ops == ERROR_ARG)
		ft_putstr_fd("ERROR ARGUMENT\n", 1);
	exit(ops);
}

void	trait_error(int ops)
{
	ops ? ft_putstr_fd("ERROR\n", 1) : 0;
	if (ops == ARG_NOT_FOUND)
	{
		ft_putstr_fd("USE : ./cub3d mapfile.cub \n", 1);
		exit(ARG_NOT_FOUND);
	}
	else if (ops == ERROR_FILE)
		ft_putstr_fd("FILE NOT FOUND OR PERMISSION DENIED !\n", 1);
	else if (ops == ERROR_RESOL)
		ft_putstr_fd("ERROR RESOLUTION", 1);
	else if (ops == ERROR_FLOOR)
		ft_putstr_fd("ERROR FLOOR\n", 1);
	else if (ops == ERROR_CEIL)
		ft_putstr_fd("ERROR CEILLING\n", 1);
	else if (ops == ERROR_NORTH)
		ft_putstr_fd("ERROR NORTH\n", 1);
	else if (ops == ERROR_SOUTH)
		ft_putstr_fd("ERROR SOUTH\n", 1);
	cont_trai_err(ops);
}

int		tab_len(char **tab)
{
	int	cpt;

	cpt = 0;
	if (tab)
		while (tab[cpt])
			cpt++;
	return (cpt);
}

char	**free_tab2d(char **tab, int size)
{
	if (!tab)
		return (NULL);
	while (size--)
		free(tab[size]);
	free(tab);
	return (NULL);
}

char	*free_cub_exit(t_var *v, int ops)
{
	free_tab2d(v->mp.tb, v->mp.axe.x);
	free(v->p_no);
	free(v->p_so);
	free(v->p_ea);
	free(v->p_we);
	free(v->p_sp);
	free(v->sprit.z_buffer);
	trait_error(ops);
	return ((char *)0);
}

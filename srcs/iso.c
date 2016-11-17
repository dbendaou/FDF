/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:05:33 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/15 17:34:48 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Calcul les points selon la projection iso
*/

void	isometric(t_map *map)
{
	t_map	*tmp;
	int		size;

	size = get_echelle(map);
	tmp = map;
	while (tmp)
	{
		tmp->x3 = 1000 + size * (CTE_1 * tmp->x - CTE_2 * tmp->line);
		tmp->y3 = 450 + size * \
		(tmp->value + CTE_1 / 2 * tmp->x + CTE_2 / 2 * tmp->line);
		tmp = tmp->next;
	}
}

/*
** Definit le zoom
*/

int		get_echelle(t_map *map)
{
	int len;
	int amp;

	amp = get_max_size(map);
	len = list_len(map);
	if (len < 1000 && amp < 50)
		return (50);
	if (len < 10000 && amp < 100)
		return (25);
	if (len < 25000 && amp < 200)
		return (10);
	else
		return (2);
}

/*
**	Permet de definir l'echelle
*/

int		get_max_size(t_map *map)
{
	t_map	*tmp;
	int		max;
	int		min;
	int		amplitude;

	tmp = map;
	max = 0;
	min = 0;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	amplitude = max - min;
	free(tmp);
	return (amplitude);
}

/*
**	Calcul la longueur de la liste t_map
*/

int		list_len(t_map *map)
{
	t_map	*tmp;
	int		i;

	tmp = map;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	free(tmp);
	return (i);
}

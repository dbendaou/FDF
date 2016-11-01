/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 20:05:33 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/01 20:31:12 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Calcul les points selon la projection iso
*/

void	isometric(t_map	*map)
{
	t_map	*tmp;
	int		size;

	size = get_echelle(map);
	tmp = begin;
	while (tmp)
	{
		tmp->x3 = 1000 + size * (CTE_1 * tmp->x - CTE_2 * tmp->line);
		printf("X3=====%d\n", x3);
		y3 = 450 + size * \
		(tmp->value + CTE_1 / 2 * tmp->x + CTE_2 / 2 * tmp->line);
		tmp = tmp->next;
	}

}

/*
** Definit l'echelle
*/

int		get_echelle(t_map *map)
{
	int len;
	int amp;

	amp = get_max_size(map);
	len = list_len(begin);
	if (len < 1000 && alt < 50)
		return (50);
	if (len < 10000 && alt < 100)
		return (25);
	if (len < 25000 && alt < 200)
		return (10);
	else
		return (2);
}

/*
**	Permet de definir l'echelle
*/

int		get_max_size(t_map *map)
{
	t_map 	*tmp;
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
	return (amplitude);
}

/*
**	Calcul la longueur de la liste t_map
*/

int		list_len(t_map *map)
{
	t_map 	*tmp;
	int		i;

	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
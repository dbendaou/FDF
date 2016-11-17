/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 19:49:10 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/17 17:13:54 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Fonction qui appelle la fonction de tracer
*/

void	trace(t_map *begin)
{
	t_map	*map1;
	t_map	*map2;

	map1 = begin;
	while (map1)
	{
		map2 = begin;
		while (map2)
		{
			if (map2 != map1)
			{
				if ((map1->x == map2->x && ((map1->line == map2->line + 1) ||
					(map1->line == map2->line - 1))))
					myseg_trace(map1->x3, map2->x3, map1->y3, map2->y3);
				else if (map1->line == map2->line)
				{
					if ((map1->x == map2->x + 1) || (map1->x == map2->x - 1))
						myseg_trace(map1->x3, map2->x3, map1->y3, map2->y3);
				}
			}
			map2 = map2->next;
		}
		map1 = map1->next;
	}
}

/*
**	Appelle les fonctions de trace en fonctions du sens du trait
*/

void	myseg_trace(int x0, int x1, int y0, int y1)
{
	t_tmp *tmp;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	if (y0 > y1)
	{
		int_swap(&x0, &x1);
		int_swap(&y0, &y1);
	}
	DX = (x1 >= x0) ? x1 - x0 : x0 - x1;
	DY = y1 - y0;
	if (x1 >= x0)
	{
		if (DX >= DY)
			ft_cas1(x0, x1, y0, tmp);
		else
			ft_cas2(x0, y0, y1, tmp);
	}
	else
	{
		if (DX >= DY)
			ft_cas3(x0, x1, y0, tmp);
		else
			ft_cas4(x0, x1, y0, tmp);
	}
	free(tmp);
}

/*
**	Swap deux int entre eux
*/

void	int_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

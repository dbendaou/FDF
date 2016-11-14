/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seg_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:38:06 by vdanain           #+#    #+#             */
/*   Updated: 2016/11/14 05:31:10 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void            relier(t_map *tmp, t_map *begin, t_env *ptr)
{
	t_map *tmp2;

	while (tmp && (tmp2 = begin))
	{
		while (tmp2)
		{
			if (tmp != tmp2)
			{
				if (tmp->x == tmp2->x)
				{
					if ((tmp->line == tmp2->line + 1) || (tmp->line == tmp2->line - 1))
						myseg_trace(tmp, tmp2, ptr);
				}
				else if (tmp->line == tmp2->line)
				{
					if ((tmp->x == tmp2->x + 1) || (tmp->x == tmp2->x - 1))
						myseg_trace(tmp, tmp2, ptr);
				}
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	ft_init(t_map *map1, t_map *map2, t_tmp *tmp)
{
	if (Y0 > Y1)
	{
		TP = X0;
		X0 = X1;
		X1 = TP;
		TP = Y0;
		Y0 = Y1;
		Y1 = TP;
	}
	DX = (X1 >= X0) ? X1 - X0 : X0 - X1;
	DY = Y1 - Y0;
}

/*
void		seg_trace(t_map *a, t_map *b, t_env *e)
{
	if (a->x3 <= b->x3)
	{
		if (a->x3 - b->x3 >= abs(b->y3 - a->y3))
			seg_trace1(b, a, e);
		else
			seg_trace2(b, a, e);
		if (b->x3 - a->x3 >= abs(b->y3 - a->y3))
			seg_trace1(a, b, e);
		else
			seg_trace2(a, b, e);
	}
	else
	{
		if (b->x3 - a->x3 >= abs(b->y3 - a->y3))
			seg_trace1(a, b, e);
		else
			seg_trace2(a, b, e);
	}
}

void		seg_trace1(t_map *a, t_map *b, t_env *e)
{
	int		x;
	int		y;
	int		nb;

	x = a->x3;
	while (x < b->x3)
	{
		y = a->y3 + ((b->y3 - a->y3) * (x - a->x3)) / (b->x3 - a->x3);
		nb = x * (e->bits_per_pixel / 8) + y * e->size_line;
		e->addr[nb] = 0xff;
		e->addr[nb + 1] = 0xff;
		e->addr[nb + 2] = 0xff;
		x++;
	}
}

void		seg_trace2(t_map *a, t_map *b, t_env *e)
{
	int		x;
	int		y;
	int		nb;

	y = a->y3;
	while (y < b->y3)
	{
		x = a->x3 + ((y - a->y3) * (b->x3 - a->x3)) / (b->y3 - a->y3);
		nb = x * (e->bits_per_pixel / 8) + y * e->size_line;
		e->addr[nb] = 0xff;
		e->addr[nb + 1] = 0xff;
		e->addr[nb + 2] = 0xff;
		y++;
	}
}

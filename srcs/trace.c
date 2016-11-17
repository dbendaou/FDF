/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:58:43 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/17 17:05:32 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	int_swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	myseg_trace(int x0, int x1, int y0, int y1)
{
	t_tmp *tmp;

	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	if (y0 > y1)
	{
		int_swap(&x0, &x1);
		int_swap(&y0, &y1);
		// TP = x0;
		// x0 = x1;
		// x1 = TP;
		// TP = y0;
		// y0 = y1;
		// y1 = TP;
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

void	ft_cas1(int x0, int x1, int y0, t_tmp *tmp)
{
	DP = 2 * DY - DX;
	DELTAE = 2 * DY;
	DELTANE = 2 * (DY - DX);
	X = x0;
	Y = y0;
	mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	while (X < x1)
	{
		if (DP <= 0)
		{
			DP = DP + DELTAE;
			X++;
		}
		else
		{
			DP = DP + DELTANE;
			X++;
			Y++;
		}
		mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	}
}

void	ft_cas2(int x0, int y0, int y1, t_tmp *tmp)
{
	DP = 2 * DX - DY;
	DELTAE = 2 * DX;
	DELTANE = 2 * (DX - DY);
	X = x0;
	Y = y0;
	mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	while (Y < y1)
	{
		if (DP <= 0)
		{
			DP = DP + DELTAE;
			Y++;
		}
		else
		{
			DP = DP + DELTANE;
			X++;
			Y++;
		}
		mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	}
}

void	ft_cas3(int x0, int x1, int y0, t_tmp *tmp)
{
	DP = 2 * DY - DX;
	DELTAE = 2 * DY;
	DELTANE = 2 * (DY - DX);
	X = x0;
	Y = y0;
	mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	while (X > x1)
	{
		if (DP <= 0)
		{
			DP = DP + DELTAE;
			X--;
		}
		else
		{
			DP = DP + DELTANE;
			X--;
			Y++;
		}
		mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	}
}

void	ft_cas4(int x0, int x1, int y0, t_tmp *tmp)
{
	DP = 2 * DX - DY;
	DELTAE = 2 * DX;
	DELTANE = 2 * (DX - DY);
	X = x0;
	Y = y0;
	mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	while (X > x1)
	{
		if (DP <= 0)
		{
			DP = DP + DELTAE;
			Y++;
		}
		else
		{
			DP = DP + DELTANE;
			X--;
			Y++;
		}
		mlx_pixel_put(ENV(mlx), ENV(win), X, Y, WHITE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:58:43 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/17 17:13:55 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

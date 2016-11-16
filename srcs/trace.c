/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:58:43 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/16 20:32:18 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	myseg_trace(int X0, int X1, int Y0, int Y1, t_env *env)
{
	t_tmp *tmp;
	
	tmp = (t_tmp *)malloc(sizeof(t_tmp));
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
	if (X1 >= X0)
	{
		if (DX >= DY)
			ft_cas1(X0, X1, Y0, tmp, env);
		else
			ft_cas2(X0, Y0, Y1, tmp, env);
	}
	else
	{
		if (DX >= DY)
			ft_cas3(X0, X1, Y0, tmp, env);
		else
			ft_cas4(X0, X1, Y0, tmp, env);
	}
	free(tmp);
}

void 	ft_cas1(int X0, int X1, int Y0, t_tmp *tmp, t_env *env)
{
	DP = 2 * DY - DX;
	DELTAE = 2 * DY;
	DELTANE = 2 * (DY - DX);
	X = X0;
	Y = Y0;
	mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	while (X < X1)
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
		mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	}
}

void	ft_cas2(int X0, int Y0, int Y1, t_tmp *tmp, t_env *env)
{
	DP = 2 * DX - DY;
	DELTAE = 2 * DX;
	DELTANE = 2 * (DX - DY);
	X = X0;
	Y = Y0;
	mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	while (Y < Y1)
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
		mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	}
}

void 	ft_cas3(int X0, int X1, int Y0, t_tmp *tmp, t_env *env)
{
	DP = 2 * DY - DX;
	DELTAE = 2 * DY;
	DELTANE = 2 * (DY - DX);
	X = X0;
	Y = Y0;
	mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	while (X > X1)
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
		mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	}
}

void	ft_cas4(int X0, int X1, int Y0, t_tmp *tmp, t_env *env)
{
	DP = 2 * DX - DY;
	DELTAE = 2 * DX;
	DELTANE = 2 * (DX - DY);
	X = X0;
	Y = Y0;
	mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	while (X > X1)
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
		mlx_pixel_put(env->mlx, env->win, X, Y, WHITE);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:58:43 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/16 20:09:25 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
void	myseg_trace(t_map *map1, t_map *map2, t_env *env)
{
	t_tmp *tmp;
	
	tmp = (t_tmp *)malloc(sizeof(t_tmp));
	ft_init(map1, map2, tmp);
	if (X1 >= X0)
	{
		printf("--trace.c_map->x3=%d\n", map1->x3);
		if (DX >= DY)
			ft_cas1(map1, map2, tmp, env);
		else
			ft_cas2(map1, map2, tmp, env);
	}
	else
	{
		if (DX >= DY)
			ft_cas3(map1, map2, tmp, env);
		else
			ft_cas4(map1, map2, tmp, env);
	}
	free(tmp);
}

void 	ft_cas1(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env)
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
			printf("---cas1_map1->x3=%d\n", map1->x3);
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

void	ft_cas2(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env)
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

void 	ft_cas3(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env)
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

void	ft_cas4(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env)
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
*/
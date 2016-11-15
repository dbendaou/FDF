#include "fdf.h"

void	myseg_trace1(int X0, int X1, int Y0, int Y1, t_env *env)
{
	t_tmp	*tmp;
	
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
		{
			//cas1
			DP = 2 * DY - DX;
			DELTAE = 2 * DY;
			DELTANE = 2 * (DY - DX);
			X = X0;
			Y = Y0;
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
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
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
			}
		}
		else
		{
			//cas2
			DP = 2 * DX - DY;
			DELTAE = 2 * DX;
			DELTANE = 2 * (DX - DY);
			X = X0;
			Y = Y0;
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
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
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
			}
		}
	}
	else
	{
		if (DX >= DY)
		{
			//cas3
			DP = 2 * DY - DX;
			DELTAE = 2 * DY;
			DELTANE = 2 * (DY - DX);
			X = X0;
			Y = Y0;
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
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
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
			}
		}
		else
		{
			//cas4
			DP = 2 * DX - DY;
			DELTAE = 2 * DX;
			DELTANE = 2 * (DX - DY);
			X = X0;
			Y = Y0;
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
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
			mlx_pixel_put(env->mlx, env->win, X, Y, 0X00FFFFFF);
			}
		}
	}
}

void	int_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

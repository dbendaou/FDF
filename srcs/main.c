/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:49:36 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/11 19:25:50 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_mouse_funct(int button, int x, int y, void *mlx)
{
	return (0);
}

int		ft_key_funct(int keycode, void *mlx)
{

	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		printf("Weshbolosse\n");
		exit (1);
	}
	return (1);
}


int		main(int ac, char **av)
{
	t_env	env;
	int		x;
	int		y;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, 420, 420, "42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(env.mlx, env.win, x, y, BLUE);
			x++;
		}
		y++;
	}
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
	return (0);

}

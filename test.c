/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:49:36 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/06 20:00:21 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <mlx.h>
#include "test.h"

int		ft_key_funct(int keycode, void *mlx)
{
	t_env	_env;
	printf("key event %d\n", keycode);
	if (keycode == 53)
		printf("Weshbolosse\n");
	//mlx_pixel_put(_env.mlx, _env.win, 300, 300, 0xFF00FF);
	return (1);
}

int		main(int ac, char **av)
{
	t_env	_env;
	int		x;
	int		y;

	_env.mlx = mlx_init();
	_env.win = mlx_new_window(_env.mlx, 420, 420, "42");
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(_env.mlx, _env.win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(_env.win, ft_key_funct, _env.mlx);
	mlx_loop(_env.mlx);
	return (0);

}

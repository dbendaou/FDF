/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/07 16:13:58 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_key_funct(int keycode)
{
	t_env	env;
	if (keycode == 53)
	{
		ft_putstr("Trying to exit.....\n");
		exit (0);
	}
}

int 	ft_mouse_funct()
{
	ft_putstr("CLICK\n");
}

int 	ft_create()
{
	t_env	env;

	env.height = 420;
	env.width = 420;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Titre");
	if (env.mlx == NULL)
	{
		ft_putstr(E_mlx_init);
		return (1);
	}
	if (env.win == NULL)
	{
		ft_putstr(E_mlx_win);
		return (1);
	}
	else
		return (0);
}

void	ft_pixel_put()
{
	t_env	env;
	int x;
	int y;

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

}

void	ft_loop()
{
	t_env	env;

	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_loop(env.mlx);
}

int		main(int ac, char **av)
{

	t_env	env;
	if (ft_create() == 1)
		return (1);
	ft_putstr("wesh loop\n");
	ft_pixel_put();
	ft_putstr("ouais bof\n");
	ft_loop();
	ft_putstr("seg loop none"); 
	
	return (0);
}
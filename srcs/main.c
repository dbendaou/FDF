/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/11 19:09:11 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_key_funct(int keycode)
{
	t_env	env;
	ft_putnbr(keycode);
	if (keycode == 53)
	{
		ft_putstr("Trying to exit.....\n");
		exit (0);
	}
	return (0);
}

int 	ft_mouse_funct()
{
	ft_putstr("CLICK\n");
	return (0);
}

void 	*ft_create(void *mlx, void *win)
{
	t_env	env;

	env.height = 420;
	env.width = 420;
	mlx = mlx_init();
	win = mlx_new_window(mlx, env.width, env.height, "Titre");
	printf(" mlx = %s\n win = %s\n",mlx, win);
/*	if (env.mlx == NULL)
	{
		ft_putstr(E_mlx_init);
		return (1);
	}
	if (env.win == NULL)
	{
		ft_putstr(E_mlx_win);
		return (1);
	}
	else*/
	env.win = win;
		return (mlx);
}

void	ft_pixel_put()
{
	t_env	env;
	int x;
	int y;
	void *tmp;
	void *tmpwin;
	tmpwin = env.win;
	tmp = env.mlx;
	printf("2mlx = %s\n win = %s\n",env.mlx, env.win);
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(tmp, tmpwin, x, y, BLUE);
			x++;
		}
		printf("rien\n");
		y++;
	}

}

int		main(int ac, char **av)
{

	t_env	env;
	void	*tmpwin;
	void	*tmpmlx;


	printf("mlx = %s\nwin = %s\n",env.mlx, env.win);
	tmpmlx = ft_create(env.mlx, env.win);		
	printf("3mlx = %s\n win = %s\n",tmpmlx, env.win);
	ft_pixel_put();
	ft_putstr("ouais bof\n");
//	mlx_key_hook(env.win, ft_key_funct, env.mlx);
//	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
//	mlx_loop(tmpmlx);
	printf("4mlx = %s\n win = %s\n",tmpmlx, env.win);
	ft_putstr("seg loop none"); 
	
	return (0);
}
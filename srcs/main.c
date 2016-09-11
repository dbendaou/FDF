/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/11 21:35:24 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_key_funct(int keycode)
{
	if (keycode == 53)
	{
		ft_putstr("Trying to exit.....\n");
		exit (0);
	}
	return (0);
}

int 	ft_mouse_funct(int button, int x, int y, void *param)
{
	printf("bouton: %d\nx:%d y:%d\n", button, x, y);
	return (0);
}

t_env 	*ft_create()
{
	t_env	env;

	env.height = 420;
	env.width = 420;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, TITLE);
	return(&env);
}

void	ft_pixel_put()
{
	t_env	env;
	int x;
	int y;
	void *tmp = env.mlx;
	void *tmpwin = env.win;


	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			mlx_pixel_put(tmp, tmpwin, x, y, BLUE);
			x++;
		}
		y++;
	}

}

/*t_map	ft_parse()
{

}*/

void	ft_loop(t_env env)
{
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
}

int		main(int ac, char **av)
{
	t_env	env;
	int i = 0;
	char *tmp;
	
	// printf("%s\n", av[1]);
	// tmp = read(av[1], O_RDONLY);
	// while (tmp[i])
	// {
	// 	tmp[i] = read(0, &av[1][i], 15);
	// 	i++;
	// }
	// printf("%s\n", tmp);
	
	env = *ft_create();
	ft_pixel_put();
	ft_putstr("ouais bof\n");
	ft_loop(env);
		
	return (0);
}
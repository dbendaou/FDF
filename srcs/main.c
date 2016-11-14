/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/14 01:43:03 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <errno.h>

int		strcheck(char *str)
{
	int 	i;
	int result;

	i = 0;
	result = 0;
	while (i < WIDTH * HEIGHT)
	{
		if (str[i] == '\0')
			result++;
		i++;
	}
	return (WIDTH * HEIGHT - result);
}

int		main(int ac, char **av)
{
	t_env	*env;
	t_map 	*map;
	
	if (ac != 2 || !ft_strstr(av[1], ".fdf"))
	{
		ft_putstr(E_USAGE);
		return (-1);
	}
	env = NULL;
	map = ft_parser(&av[1]);
	env = ft_create();
	isometric(map);
	trace(map, env);
	ft_putendl(env->addr);
	ft_putnbr(mlx_put_image_to_window(env->mlx, env->win, env->addr, 0 , 0));
	perror("ici :");
	ft_putnbr(strcheck(env->addr));
	// ft_loop(*env);
	mlx_loop(env->mlx);
	return (0);
}

int 	ft_mouse_funct(int button, int x, int y, void *param)
{
	param = NULL;

	printf("bouton: %d\nx:%d y:%d\n", button, x, y);
	return (0);
}
/*
void	ft_pixel_put(t_map *map, t_env env)
{
	int i;
	int line = 0;
	int x = 450;
	int y = 300;
	while (map)
	{
		i = 0;
		if (line != map->line)
		{
			y = y+ get_echelle(map);
			x = 450;
			line = map->line;
		}
		while (i <= 10)
		{
				mlx_pixel_put(env.mlx, env.win, x, y, ft_color(map->value));
				x++;
				i++;
		}
		x = x+ (get_echelle(map) / 2);
		map = map->next;
	}
}
*/
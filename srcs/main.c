/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/08 19:21:56 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	env;
	t_map 	*map;
	
	if (ac != 2 || !ft_strstr(av[1], ".fdf"))
	{
		ft_putstr(E_USAGE);
		return (-1);
	}
	map = ft_parser(&av[1]);
	env = ft_create();
	isometric(map);
	ft_pixel_put(map, env);
	ft_loop(env);
		
	return (0);
}

int 	ft_mouse_funct(int button, int x, int y, void *param)
{
	param = NULL;

	printf("bouton: %d\nx:%d y:%d\n", button, x, y);
	return (0);
}

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
			y = y+ 8;
			x = 450;
			line = map->line;
		}
		while (i <= 10)
			{
				mlx_pixel_put(env.mlx, env.win, x, y, ft_color(map->value));
				x++;
				i++;
			}
		x = x+ 4;
		map = map->next;
	}
}

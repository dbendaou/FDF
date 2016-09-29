/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/29 22:45:00 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 	ft_key_funct(int keycode)
{
	if (keycode == 53)
		exit (0);
	return (0);
}

int 	ft_mouse_funct(int button, int x, int y, void *param)
{
	printf("bouton: %d\nx:%d y:%d\n", button, x, y);
	return (0);
}

t_env 	ft_create()
{
	t_env	env;

	env.height = 1000;
	env.width = 1000;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, TITLE);
	return(env);
}

int 	ft_color(int value)
{
	if (value >= 0 && value < 10)
		return (WHITE);
	if (value >= 10 && value < 30)
		return (YELLOW);
	if (value >= 30 && value < 60)
		return (RED);
	else
		return (BLUE);
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

void	ft_loop(t_env env)
{
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
}

t_map 	*ft_parser(char **buf)
{
	t_map	*map;
	t_map	*begin;
	char 	*tmp;
	char	**tab;
	int 	fd;
	int		x;
	int		y;

	map = (t_map *)malloc(sizeof(t_map));
	map->next = NULL;
	begin = map;
	if ((fd = open(*buf, O_RDONLY)) == -1)
		ft_putstr(E_open);
	y = 0;
	while (get_next_line(fd, &tmp))
	{
		x = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[x])
		{

			if (map == begin && x == 0)
			{
				map->x = x;
				map->line = y;
				map->value = ft_atoi(tab[x]);
				map->next = NULL;
			}
			else
			{
				map->next = (t_map *)malloc(sizeof(t_map));
				map = map->next;
				map->next = NULL;
				map->x = x;
				map->line = y;
				map->value = ft_atoi(tab[x]);
			}
			x++;
		}
		y++;
	}
	return (begin);
}

int		main(int ac, char **av)
{
	t_env	env;
	t_map 	*map;
	int 	i = 0;
	
	if (ac != 2)
	{
		ft_putstr(E_usage);
		return (-1);
	}
	map = ft_parser(&av[1]);
	env = ft_create();
	ft_pixel_put(map, env);
	ft_loop(env);
		
	return (0);
}
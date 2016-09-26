/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/26 20:59:35 by dbendaou         ###   ########.fr       */
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

	env.height = 420;
	env.width = 420;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, TITLE);
	return(env);
}

void	ft_pixel_put()
{
	t_env	env;
	int 	x;
	int 	y;
	
	y = 50;
	while (y < 55)
	{
		x = 50;
		while (x < 350)
		{	
			mlx_pixel_put(env.mlx, env.win, x, y, RED);
			mlx_pixel_put(env.mlx, env.win, x, y + 25, BLUE);
			mlx_pixel_put(env.mlx, env.win, x, y + 50, GREEN);
			mlx_pixel_put(env.mlx, env.win, x, y+75, YELLOW);
			mlx_pixel_put(env.mlx, env.win, x, y+100, WHITE);
			x++;
	}
		y++;
	}
}

void	ft_loop(t_env env)
{
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
}

void 	ft_parser(char **buf)
{
	t_map	*map;
	t_map	*begin;
	char 	*tmp;
	char	**tab;
	int 	fd;
	int		x;
	int		y;
	int		z;


	map = (t_map *)malloc(sizeof(t_map));
	map->next = NULL;
	begin = map;
	if ((fd = open(*buf, O_RDONLY)) == -1)
		ft_putstr(E_open);
	y = 0;
	z = 0;
	while (get_next_line(fd, &tmp))
	{
		x = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[x])
		{
			map->x = x;
			map->line = y;
			map->value = ft_atoi(tab[x]);
			map->next = (t_map *)malloc(sizeof(t_map));
			map = map->next;
			map->next = NULL;
			x++;
		}
		y++;
	}
	map = begin;
	while (map)
	{
		int i = 0;
		
		ft_putnbr(map->value);
		ft_putchar(' ');
		if (i != map->line)
		{
			ft_putchar('\n');
			i = map->line;
		}
		map = map->next;
		
	}
}

int		main(int ac, char **av)
{
	t_env	env;
	t_map 	map;
	int 	i = 0;
	
	if (ac != 2)
	{
		ft_putstr(E_usage);
		return (-1);
	}
	ft_parser(&av[1]);
	env = ft_create();
	ft_pixel_put();
	ft_loop(env);
		
	return (0);
}
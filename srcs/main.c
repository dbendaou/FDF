/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/12 18:32:23 by dbendaou         ###   ########.fr       */
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

void	ft_loop(t_env env)
{
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
}

int		main(int ac, char **av)
{
	t_env	env;
	int 	i = 0;
	char 	*tmp;
	int 	fd;

	fd = open(av[1], O_RDONLY);
	printf("%d\n", fd);
	while ((i = read(fd, &tmp, 19) > 0))
	{
		printf("%s\n", &tmp);
	}
	env = ft_create();
	ft_pixel_put();
	ft_putstr("ouais bof\n");
	ft_loop(env);
		
	return (0);
}
/*
int i;
FILE *fp;
int c;

	fp = fopen(argv[i], "r");
	if(fp == NULL)
		{
		fprintf(stderr, "cat: can't open %s\n", argv[i]);
		continue;
		}

	while((c = getc(fp)) != EOF)
		putchar(c);

	fclose(fp);

f=open(argv[1],O_RDONLY);
while ((n=read(f,l,80)) > 0)
    write(1,l,n);
    */
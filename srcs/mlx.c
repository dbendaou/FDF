/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:43:00 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/08 18:53:26 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Cree la fenetre
*/

t_env	ft_create(void)
{
	t_env	env;

	env.height = 2000;
	env.width = 2000;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, TITLE);
	return (env);
}

/*
**	Boucle de mlx_loop
*/

void	ft_loop(t_env env)
{
	mlx_mouse_hook(env.win, ft_mouse_funct, env.mlx);
	mlx_key_hook(env.win, ft_key_funct, env.mlx);
	mlx_loop(env.mlx);
}

/*
**	Definit les couleurs selon l'altitude
*/

int		ft_color(int value)
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

/*
**	Fonction de capture keyboard
*/

int		ft_key_funct(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

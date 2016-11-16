/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/16 21:02:13 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*env;
	t_map	*map;

	if (ac != 2 || !ft_strstr(av[1], ".fdf"))
	{
		ft_putstr(E_USAGE);
		return (-1);
	}
	map = ft_parser(&av[1]);
	env = ft_create();
	isometric(map);
	trace(map);
	ft_loop(*env);
	return (0);
}

int		ft_mouse_funct(int button, int x, int y, void *param)
{
	param = NULL;
	printf("bouton: %d\nx:%d y:%d\n", button, x, y);
	return (0);
}

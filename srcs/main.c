/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:13:57 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/17 17:13:45 by dbendaou         ###   ########.fr       */
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
	free(env);
	free(map);
	return (0);
}

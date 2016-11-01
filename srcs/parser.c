/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:03:08 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/01 20:26:12 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Open the file
*/

int		ft_open(char **buf)
{
	int		fd;
	if ((access(*buf, R_OK) == -1))
	{
		ft_putstr(E_FILE);
		exit (-1);
	}
	if ((fd = open(*buf, O_RDONLY) == -1))
	{
		ft_putstr(E_OPEN);
		exit (-1);
	}
	return (fd);
}

/*
**	Parse the map
*/

t_map	*ft_parser(char **buf)
{
	char	**tab;
	char 	*tmp;
	t_map	*map;
	t_map	*begin;
	int 	fd;
	int 	x;
	int 	y;

	if ((fd = open(*buf, O_RDONLY)) == -1)
		ft_putstr(E_OPEN);
	y = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->next = NULL;
	begin = map;
	while (get_next_line(fd, &tmp))
	{
		x = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[x])
		{
			if (map == begin && x == 0)
				ft_map1(x, y, tab, map);
			else
			{
				// ft_map2(x, y, tab, map);
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

void 	ft_map1(int x, int y, char **tab, t_map *map)
{
	map->x = x;
	map->line = y;
	map->value = ft_atoi(tab[x]);
	map->next = NULL;
}

void	ft_map2(int x, int y, char **tab, t_map *map)
{
	t_map *tmp;

	tmp = map;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		tmp->next = (t_map *)malloc(sizeof(t_map));
	tmp->next = NULL;
	tmp->x = x;
	tmp->line = y;
	tmp->value = ft_atoi(tab[x]);
	}
}
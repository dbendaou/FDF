/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:03:08 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/15 17:25:09 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Ouvre la map la split et l'envoie en tableau a ft_parser
*/

void	run_map(int fd, char *tmp, t_map *begin, t_map *map)
{
	int		x;
	int		y;
	char	**tab;

	y = 0;
	while (get_next_line(fd, &tmp))
	{
		ft_check(tmp);
		x = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[x])
		{
			if (map == begin && x == 0)
				ft_map1(x, y, tab, map);
			else
			{
				map->next = ft_map2(x, y, tab);
				map = map->next;
			}
			x++;
		}
		y++;
	}
}

/*
**	Parse la map
*/

t_map	*ft_parser(char **buf)
{
	char	*tmp;
	t_map	*map;
	t_map	*begin;
	int		fd;

	tmp = NULL;
	fd = open(*buf, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(E_FILE);
		exit(-1);
	}
	map = (t_map *)malloc(sizeof(t_map));
	map->next = NULL;
	begin = map;
	run_map(fd, tmp, begin, map);
	return (begin);
}

/*
**	Mets la map dans struct si premier passage
*/

void	ft_map1(int x, int y, char **tab, t_map *map)
{
	map->x = x;
	map->line = y;
	map->value = -ft_atoi(tab[x]);
	map->next = NULL;
}

/*
**	Mets la map dans la structure
*/

t_map	*ft_map2(int x, int y, char **tab)
{
	t_map *tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	tmp->next = NULL;
	tmp->x = x;
	tmp->line = y;
	tmp->value = -ft_atoi(tab[x]);
	return (tmp);
}

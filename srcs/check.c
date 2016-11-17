/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:24:03 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/17 17:28:22 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**	Verifie si la map contient uniquement des chiffres, espace ou '-'
*/

void	ft_check(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if ((line[i] >= 48 && line[i] <= 57) || line[i] == 45 || line[i] == 32)
			i++;
		else
		{
			ft_putstr(E_MAP);
			exit(0);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:15:38 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/13 18:07:07 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	int 		height; //hauteur
	int 		width;	//largeur
}				t_env;

typedef struct s_map
{
	int 		i;
	int 		line;
	int 		value;
	struct s_map *next;
}				t_map;

# define	E_mlx_init 	"fails to set up the connection to the X server\n"
# define	E_mlx_win	"mlx_new_window fails to create a new window\n"
# define	E_open		"Open function fail to open the file\n"
# define	USAGE		"usage :\n ./fdf [maps]\n"
/* fenetre */
# define	TITLE		"FDF x 42"

/* couleurs */
# define WHITE 	0x00FFFFFF
# define RED 	0x00FF0000
# define BLUE 	0x000000FF

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

#include "../libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

#endif

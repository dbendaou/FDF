/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:15:38 by dbendaou          #+#    #+#             */
/*   Updated: 2016/10/31 16:57:42 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
**	Includes
*/
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>

/*
**	Erreurs
*/
# define E_MLX_INIT 	"fails to set up the connection to the X server\n"
# define E_MLX_WIN		"mlx_new_window fails to create a new window\n"
# define E_OPEN			"Open function fail to open the file\n"
# define E_USAGE		"usage :\n ./fdf [maps]\n"

/*
** Titre de la fenetre
*/
# define TITLE			"FDF x 42"

/*
**	Couleurs
*/
# define WHITE 			0x00FFFFFF
# define RED 			0x00FF0000
# define BLUE 			0x000000FF
# define GREEN			0x0000FF00
# define YELLOW 		0x00FFFF00

/*
**	Structure
*/
typedef struct			s_env
{
	void				*win;
	void				*mlx;
	int					height;		/*hauteur*/
	int					width;		/*largeur*/
}						t_env;

typedef struct			s_map
{
	int					x;
	int					line;
	int					value;
	struct s_map		*next;
}						t_map;

#endif

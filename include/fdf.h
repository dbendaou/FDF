/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:15:38 by dbendaou          #+#    #+#             */
/*   Updated: 2016/09/07 16:16:46 by dbendaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FDF_H
# define	FDF_H

typedef struct	s_env
{
	void	*win;
	void	*mlx;
	int 	height; //hauteur
	int 	width;	//largeur
}				t_env;

# define	E_mlx_init 	"fails to set up the connection to the X server"
# define	E_mlx_win	"mlx_new_window fails to create a new window"

/* couleurs */
# define WHITE 	0x00FFFFFF
# define RED 	0x00FF0000
# define BLUE 	0x000000FF

#include <mlx.h>
#include <stdlib.h>
#include "../libft/libft.h"
//#include "get_next_line.h"

#endif

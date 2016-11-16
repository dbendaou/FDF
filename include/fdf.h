/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:15:38 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/16 20:07:31 by dbendaou         ###   ########.fr       */
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
**	Constante
*/
# define CTE_1 0.5
# define CTE_2 0.5
# define E_CTE 1

/*
**	Erreurs
*/
# define E_MLX_INIT 	"fails to set up the connection to the X server\n"
# define E_MLX_WIN		"mlx_new_window fails to create a window\n"
# define E_OPEN			"Open function fail to open the file\n"
# define E_USAGE		"usage :\n ./fdf [maps.fdf]\n"
# define E_FILE			"The file doesn't exist or you don't have the right\n"
# define E_MAP			"The map is not valid\n"

/*
** Fenetre
*/
# define TITLE			"FDF x 42"
# define WIDTH			2000
# define HEIGHT			2000

/*
**	Couleurs
*/
# define WHITE 			0x00FFFFFF
# define RED 			0x00FF0000
# define BLUE 			0x000000FF
# define GREEN			0x0000FF00
# define YELLOW 		0x00FFFF00

/*
**	Pour une lecture plus simple de trace.c
*/
# define X 				tmp->x
# define Y 				tmp->y
# define TP 			tmp->tp
# define DX 			tmp->dx
# define DY 			tmp->dy
# define DELTAE 		tmp->deltaE
# define DELTANE 		tmp->deltaNE
# define DP 			tmp->dp
// # define X0 			tab[0]
// # define X1 			tab[1]
// # define Y0 			tab[2]
// # define Y1 			tab[3]



/*
**	Structure
*/
typedef struct			s_env
{
	void				*win;
	void				*mlx;
}						t_env;

typedef struct			s_map
{
	int					x;
	int					line;
	int					value;

	int					x3;
	int					y3;
	struct s_map		*next;
}						t_map;

typedef struct			s_tmp
{
	int 				x;
	int 				y;
	int 				tp;
	int 				dx;
	int 				dy;
	int 				deltaE;
	int 				deltaNE;
	int 				dp;
}						t_tmp;


void	myseg_trace1(int X0, int X1, int Y0, int Y1, t_env *env);
// void	my_seg_trace(int x0, int y0, int x1, int y1, t_env *env);
// void	my_seg_trace(t_map *map1, t_map *map2, t_env *env);

/*
**	trace.c
*/
void	myseg_trace(t_map *map1, t_map *map2, t_env *env);
void 	ft_cas1(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env);
void 	ft_cas2(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env);
void 	ft_cas3(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env);
void 	ft_cas4(t_map *map1, t_map *map2, t_tmp *tmp, t_env *env);

/*
**	Parser.c
*/
t_map					*ft_parser(char **buf);
t_map					*ft_map(char **tab, t_map *map, t_map *begin);
void					ft_map1(int x, int y, char **tab, t_map *map);
t_map					*ft_map2(int x, int y, char **tab);

/*
**	iso.c
*/
void					isometric(t_map *map);
int						get_echelle(t_map *map);
int						get_max_size(t_map *map);
int						list_len(t_map *map);

/*
**	mlx.c
*/
int						ft_key_funct(int keycode);
void					ft_loop(t_env env);
t_env					*ft_create(void);
int						ft_color(int value);

/*
**	check.c
*/
void					ft_check(char *file);

/*
**	draw.c
*/
void					trace(t_map *begin, t_env *env);
void					ft_init(t_map *map1, t_map *map2, t_tmp *tmp);

void					ft_pixel_put(t_map *map, t_env env);
int						ft_mouse_funct(int button, int x, int y, void *param);

#endif

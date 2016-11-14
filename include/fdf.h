/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendaou <dbendaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 16:15:38 by dbendaou          #+#    #+#             */
/*   Updated: 2016/11/14 01:25:22 by dbendaou         ###   ########.fr       */
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
# define WHITE 			0xff
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
	void				*image;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
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
void					draw_seg(t_map *map1, t_map *map2, t_env *env);
void					draw1(t_map *map1, t_map *map2, t_env *env);
void					draw2(t_map *map1, t_map *map2, t_env *env);

void					ft_pixel_put(t_map *map, t_env env);
int						ft_mouse_funct(int button, int x, int y, void *param);

#endif

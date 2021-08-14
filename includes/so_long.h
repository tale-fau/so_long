/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:55:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/14 20:31:08 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <sys/types.h>
# include <limits.h>

# define PATH "/Users/tale-fau/github/so_long/srcs/Textures/p.xpm /Users/tale-fau/github/so_long/srcs/Textures/e.xpm /Users/tale-fau/github/so_long/srcs/Textures/c.xpm /Users/tale-fau/github/so_long/srcs/Textures/0.xpm /Users/tale-fau/github/so_long/srcs/Textures/1.xpm"

typedef struct s_data
{
	void	*texts[5];	//tableau void pour stocker les textures
	void	*mlx_ptr;	//pour la mlx
	void	*window_ptr;	//pour la mlx
	void	*img_ptr;	//pour la mlx
	char	**map;	//map en tableau
	char	*img_addr;	//pour la mlx
	char	*relative_path;	//pour la mlx
	char	*linear_map;	//map en string pour envoyer vers tableau
	char	*path_player;
	char	*path_wall;
	char	*path_coin;
	char	*path_playgd;
	char	*path_exit;
	int		xwidth[5];
	int		yheight[5];
	int		player_pos[2]; //position du joueur
	int		exit_pos[2];	//position exit
	int		img_width;	//pour la mlx
	int		img_height;	//pour la mlx
	int		bits_per_pixel;	//pour la mlx
	int		line_length;	//pour la mlx
	int		endian;	//pour la mlx
	int		size_x;	//pour la mlx
	int		size_y;	//pour la mlx
	int		i;	//TEST index pour la map 3d dans GNL
	int		colonne;	//colonne de la char **map
	int		ligne;	//ligne de la char **map
	int		sym_e;	//compteur de symboles E
	int		sym_c;	//compteur de symboles C
	int		sym_p;	//compteur de symboles P
	int		key_count;	//compteur du nombre de mouvements
	int		max_colonne;
	int		max_ligne;
	int		index;
	int		ret_read;
	int		size_game;
	int		res_y;	//resolution window
	int		res_x;
	int		coins;	//boolean si il reste des collectibles ou non
	int		fast;
}	t_data;

int			render_next_frame(t_data *data);
int			color_image(t_data *data);
int			ft_map_validity(char *map, t_data *data);
int			split_map(char *map, t_data *data);
int			handle_errors(int i);
int			get_next_line(int fd, t_data *data);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
int			ft_check(char *str, t_data *data);
void		ft_init(void *s, int c, size_t n);
void		*ft_realloc(void *ptr, size_t size);
void		ft_pixel_put(t_data *data, int x, int y, int color);
int			key_manager(int keycode, t_data *data);
int			new_image(t_data *data);
int			ft_exit(t_data *data);
int			key_manager(int keycode, t_data *data);
int			down_arrow(t_data *data);
int			up_arrow(t_data *data);
int			left_arrow(t_data *data);
int			right_arrow(t_data *data);
int			mouse_manager(t_data *data);
int			exit_win(t_data *data);
int			scan_map(t_data *data);
int			display(t_data *data);
int			init_data(t_data *data);
void		ft_pixel_put(t_data *data, int x, int y, int color);
int			mlx_initialize(t_data *data);
int			data_init(t_data *data);
int			check_extension(char *av);
int			new_window(t_data *data);
int			new_image(t_data *data);
int			get_3dmap(char *path, t_data *data);
int			ft_free(t_data *data);
int			ft_hooks(t_data *data);
int			display_walls(t_data *data);
int			load_textures(t_data *data);
int			free_tab(char **tab);
#endif

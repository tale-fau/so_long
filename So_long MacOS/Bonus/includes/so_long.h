/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:55:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/08/19 15:01:57 by tale-fau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
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

typedef struct s_mvcount
{
	void	*mv[10];
	int		xwidth[10];
	int		yheight[10];
}	t_mvcount;

typedef struct s_enemy
{
	void	*txt;
	int		xwidth;
	int		yheight;
	int		pos[2];
	int		right;
}	t_enemy;

typedef struct s_data
{
	void		*texts[9];
	void		*mlx_ptr;
	void		*window_ptr;
	void		*img_ptr;
	char		**map;
	char		*img_addr;
	char		*relative_path;
	int			xwidth[9];
	int			yheight[9];
	int			player_pos[2];
	int			exit_pos[2];
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			size_x;
	int			size_y;
	int			colonne;
	int			ligne;
	int			sym_e;
	int			sym_c;
	int			sym_p;
	int			key_count;
	int			max_colonne;
	int			max_ligne;
	int			index;
	int			ret_read;
	int			size_game;
	int			res_y;
	int			res_x;
	int			coins;
	int			fast;
	t_mvcount	mvcount;
	t_enemy		enemy;
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
int			scan_map(t_data *data, char c);
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
int			load_numbers(t_data *data);
int			free_tab(char **tab);
int			anim_p(t_data *data);
int			anim_c(t_data *data, int i, int j);
int			anim_e(t_data *data, int i, int j);
char		**set_path_number(void);
int			display_mvcount(t_data *data);
int			set_path_load_enemy(t_data *data);
int			locate_enemy(t_data *data);
int			display_enemy(t_data *data);
int			enemy_right(t_data *data);
int			enemy_up(t_data *data);
int			enemy_down(t_data *data);
int			enemy_left(t_data *data);
int			enemy_move(t_data *data);

#endif
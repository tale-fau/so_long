/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tale-fau <tale-fau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:55:31 by tale-fau          #+#    #+#             */
/*   Updated: 2021/07/27 23:39:25 by tale-fau         ###   ########.fr       */
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

typedef struct s_data
{
	void	*mlx_ptr;	//pour la mlx
	void	*window_ptr;	//pour la mlx
	void	*img_ptr;	//pour la mlx
	char	**map;	//map en tableau
	char	*img_addr;	//pour la mlx
	char	*relative_path;	//pour la mlx
	char	*linear_map;	//map en string pour envoyer vers tableau
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
	int		sym_c;
	int		sym_p;
	int		nl_count;
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:08:41 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 12:46:57 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_point_exit
{
	int	exit_row;
	int	exit_column;
	int	count_exits;
}	t_point_exit;

typedef struct s_point_enemy
{
	int	enemy_row;
	int	enemy_column;
	int	count_enemies;
}	t_point_enemy;

typedef struct s_all
{
	mlx_texture_t	*t_co;
	mlx_texture_t	*t_es;
	mlx_texture_t	*t_o_ex;
	mlx_texture_t	*t_c_ex;
	mlx_texture_t	*t_pl;
	mlx_texture_t	*t_wa;
	mlx_texture_t	*t_en;
	mlx_image_t		*i_co;
	mlx_image_t		*i_es;
	mlx_image_t		*i_o_ex;
	mlx_image_t		*i_c_ex;
	mlx_image_t		*i_pl;
	mlx_image_t		*i_wa;
	mlx_image_t		*i_en;
	int				n_c;
	int				n_e;
	int				n_p;
	int				p_r;
	int				p_c;
	int				o_r;
	int				o_c;
	char			move;
	mlx_t			*mlx;
	int				w;
	int				h;
	int				rs;
	int				cs;
	char			**con;
	t_point_exit	*exs;
	t_point_enemy	*ens;
	int				t_m;
	mlx_texture_t	*t_n0;
	mlx_texture_t	*t_n1;
	mlx_texture_t	*t_n2;
	mlx_texture_t	*t_n3;
	mlx_texture_t	*t_n4;
	mlx_texture_t	*t_n5;
	mlx_texture_t	*t_n6;
	mlx_texture_t	*t_n7;
	mlx_texture_t	*t_n8;
	mlx_texture_t	*t_n9;
	mlx_image_t		*i_n0;
	mlx_image_t		*i_n1;
	mlx_image_t		*i_n2;
	mlx_image_t		*i_n3;
	mlx_image_t		*i_n4;
	mlx_image_t		*i_n5;
	mlx_image_t		*i_n6;
	mlx_image_t		*i_n7;
	mlx_image_t		*i_n8;
	mlx_image_t		*i_n9;
}	t_all;

//GET_NEXT_LINE_UTILS
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
int				ft_strlen_n(const char *str);

//GET_NEXT_LINE
char			*ft_get_next_line(int fd);

char			*ft_strnstr(const char *b, const char *l, size_t len);
int				ft_number_columns(int fd);
int				ft_number_rows(int fd);
int				ft_check_walls(t_all data);
char			**ft_create_content(int fd, int rows);
void			ft_control_char_count(t_all *data);
int				ft_control_char(t_all *data);

int				ft_check_enemy(t_all *d);
int				ft_check_finish(t_all *d);
void			ft_count_positions(t_all *d, int *c_p, char l);
t_point_exit	*ft_configure_exits(t_all *d);
t_point_enemy	*ft_configure_enemies(t_all *d);
void			ft_player_position(t_all *data);
int				ft_check_prev_position(t_point_exit *exits, int r, int c);
int				ft_check_other_position(t_all *data);
void			ft_initialize_textures(t_all *data);
void			ft_delete_all(t_all *data);
void			ft_draw_map(t_all *data);
void			ft_draw_exits(t_all *d, int r, int c);
void			ft_initialize_counter(t_all *d);
void			ft_initial_counter(t_all *d);
char			*ft_itoa(int n);
void			ft_delete_counter(t_all *d);

#endif
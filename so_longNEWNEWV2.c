#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_t_i
{
	mlx_texture_t	*t_co;
	mlx_texture_t	*t_es;
	mlx_texture_t	*t_ex;
	mlx_texture_t	*t_pl;
	mlx_texture_t	*t_wa;
	mlx_texture_t	*t_en;
	mlx_image_t	*i_co;
	mlx_image_t	*i_es;
	mlx_image_t	*i_ex;
	mlx_image_t	*i_pl;
	mlx_image_t	*i_wa;
	mlx_image_t	*i_en;
}	t_t_i;

typedef struct s_type_char
{
	int	n_c;
	int	n_e;
	int	n_p;
	int	row;
	int	column;
}	t_type_char;

typedef struct s_player
{
	int	player_row;
	int	player_column;
	int	op_row;
	int	op_column;
	char	move;
}	t_player;

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
	mlx_texture_t	*t_ex;
	mlx_texture_t	*t_pl;
	mlx_texture_t	*t_wa;
	mlx_texture_t	*t_en;
	mlx_image_t		*i_co;
	mlx_image_t		*i_es;
	mlx_image_t		*i_ex;
	mlx_image_t		*i_pl;
	mlx_image_t		*i_wa;
	mlx_image_t		*i_en;
	int				n_c;
	int				n_e;
	int				n_p;
	int				player_row;
	int				player_column;
	int				op_row;
	int				op_column;
	char			move;
	mlx_t			*mlx;
	int				width;
	int				height;
	int				rows;
	int				columns;
	char			**content;
	t_point_exit	*exits;
	t_point_enemy	*enemies;
}	t_all;

//GET_NEXT_LINE_UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		ft_strlen_n(const char *str);

//GET_NEXT_LINE
char	*ft_get_next_line(int fd);

//CHECK
char	*ft_strnstr(const char *b, const char *l, size_t len);
int		ft_number_columns(int fd);
int		ft_number_rows(int fd);
int		ft_check_walls(t_all data);
char	**ft_create_content(int fd, int rows);
void	ft_control_char_count(t_all *data);
int		ft_control_char(t_all *data);

//KERNEL
int				ft_check_enemy(int row_player, int column_player, t_point_enemy *enemies);
int				ft_check_finish(int row_player, int column_player, t_point_exit *exits);
void			ft_count_positions(char **content, int rows, int columns, int *count_positions, char letter);
t_point_exit	*ft_configure_exits(char **content, int rows, int columns);
t_point_enemy	*ft_configure_enemies(char **content, int rows, int columns);
void			ft_print_map(char **content, int rows);
void			ft_player_position(t_all *data);
int				ft_check_prev_position(t_point_exit *exits, int row, int column);
int				ft_check_other_position(t_all *data/*, t_point_exit *exits*/);
int				ft_move_player(t_all *data/*char **content, t_player *player, int rows, int columns, t_point_exit *exits*/);
void			ft_kernel(char **content, int rows, int columns);

#endif

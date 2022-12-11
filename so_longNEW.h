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

//GET_NEXT_LINE_UTILS
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int	ft_strlen_n(const char *str);

//GET_NEXT_LINE
char	*ft_get_next_line(int fd);

//CHECK
char	*ft_strnstr(const char *b, const char *l, size_t len);
int	ft_number_columns(int fd);
int	ft_number_rows(int fd);
int	ft_check_walls(char **content, int rows, int columns);
char	**ft_create_content(int fd, int rows);
void	ft_control_char_count(char **c, int row, int col, t_type_char *tc);
int	ft_control_char(char **content, int rows, int columns);

#endif

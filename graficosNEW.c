#include "so_long.h"

//GET_NEXT_LINE_UTILS------------------------------------------------------

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	p;

	p = 0;
	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (*str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (s1[p])
	{
		str[p] = s1[p];
		p++;
	}
	while (*s2)
	{
		str[p] = *s2;
		p++;
		s2++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	p;

	p = 0;
	str = malloc ((len + 1) * sizeof (*str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (s[start + p] && p < len)
	{
		str[p] = s[start + p];
		p++;
	}
	str[p] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char) c;
	while (*s != letter)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *) s);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_strlen_n(const char *s)
{
	size_t	len;
	
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

//GET_NEXT_LINE------------------------------------------------------------

char	*ft_join_free(char *buffer, char *str)
{
	char *temp;

	temp = ft_strjoin(buffer, str);
	free (buffer);
	return (temp);
}

char	*ft_total_line(char *buffer, int fd)
{
	int	bytes;
	char	*str;

	bytes = 1;
	str = malloc ((BUFFER_SIZE + 1) * sizeof (*str));
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (str);
			free (buffer);
			return (NULL);
		}
		str[bytes] = '\0';
		buffer = ft_join_free(buffer, str);
	}
	free (str);
	return (buffer);
}

char	*ft_to_nl(char *buffer)
{
	int	nl;

	nl = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[nl] && buffer[nl] != '\n')
		nl++;
	nl++;
	return (ft_substr(buffer, 0, nl));
}

char	*ft_from_nl(char *buffer)
{
	int	nl;
	int	len;
	char	*str;

	nl = 0;
	len = 0;
       	while (buffer[nl] && buffer[nl] != '\n')
		nl++;
	if (!buffer[nl])
	{
		free (buffer);
		return (NULL);
	}
	nl++;
	len = ft_strlen(&buffer[nl]);
	str = ft_substr(buffer, nl, len);
	free (buffer);
	return (str);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	if (!buffer)
	{
		buffer = malloc (1 * sizeof (*buffer));
		if (!buffer)
		{
			free (buffer);
			return (NULL);
		}
		*buffer = 0;
	}
	buffer = ft_total_line(buffer, fd);
	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
	{
		free (buffer);
		return (NULL);
	}
	str = ft_to_nl(buffer);
	buffer = ft_from_nl(buffer);
	return (str);
}

//CHECK--------------------------------------------------------------------

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	p1;
	size_t	p2;

	p1 = 0;
	if (!*l)
		return ((char *) b);
	while (b[p1] && p1 < len)
	{
		p2 = 0;
		while (b[p1 + p2] && b[p1 + p2] == l[p2] && p1 + p2 < len)
		{
			if (l[p2 + 1] == '\0' && b[p1 + p2 + 1] == '\0')
				return ((char *) &b[p1]);
			p2++;
		}
		p1++;
	}
	return (NULL);
}

int	ft_number_columns(int fd)
{
	char	*str;
	int	column1;
	int	columnn;
	int	control;

	column1 = 0;
	columnn = 0;
	control = 1;
	str = ft_get_next_line(fd);
	while (str && control == 1)
	{
		columnn = 0;
		if (column1 == 0)
			column1 = ft_strlen_n(str);
		else
			columnn = ft_strlen_n(str);
		if (column1 != columnn && columnn != 0)
			control = 0;
		str = ft_get_next_line(fd);
	}
	close(fd);
	if (control == 0)
	{
		printf("ERROR\nNO TODAS LAS LINEAS TIENEN LA MISMA LONGITUD\n");
		return (-1);
	}
	else
	{
		printf("NUMERO DE COLUMNAS %i\n", column1);
		return (column1);
	}
}

int	ft_number_rows(int fd)
{
	int	rows;
	char	*str;

	rows = 0;
	str = ft_get_next_line(fd);
	while (str)
	{
		rows++;
		str = ft_get_next_line(fd);
	}
	printf("NUMERO DE LINEAS %i\n", rows);
	return (rows);
}

int	ft_check_walls(char **content, int rows, int columns)
{
	int	r;
	int	c;
	int	walls_ok;

	r = 0;
	c = 0;
	walls_ok = 1;
	while(r < rows && walls_ok == 1)
	{
		c = 0;
		while (c < columns && walls_ok == 1)
		{
			if (r != 0 && r != rows - 1)
			{
				if (c == 0 || c == columns - 1)
				{
					if (content [r][c] != '1')
						walls_ok = 0;
				}
			}
			else if (r == 0 || r == rows - 1)
			{
				if (content[r][c] != '1')
					walls_ok = 0;
			}
			c++;
		}
		r++;
	}
	if (walls_ok)
		printf("MUROS CORRECTOS\n");
	else
		printf("MUROS ERRONEOS\n");
}

char	**ft_create_content(int fd, int rows)
{
	char	**content;
	char	*str;
	int	r;

	r = 0;
	content = malloc (rows * sizeof (char *));
	if (!content)
		return (NULL);
	str = ft_get_next_line(fd);
	while (str && r < rows)
	{
		content[r++] = ft_substr(str, 0, ft_strlen_n(str));
		str = ft_get_next_line(fd);
	}
	close(fd);
	return (content);
}

void	ft_control_char_count(char **c, int row, int col, t_type_char *tc)
{
	while (tc->row < row)
	{
		tc->column = 0;
		while (tc->column < col)
		{
			if (c[tc->row][tc->column] == 'C')
				tc->n_c += 1;			
			else if (c[tc->row][tc->column] == 'E')
				tc->n_e += 1;
			else if (c[tc->row][tc->column] == 'P')
				tc->n_p += 1;
			tc->column++;
		}
		tc->row++;
	}
	printf("C->%i\t\tE->%i\t\tP->%i\n", tc->n_c, tc->n_e, tc->n_p);
}

int	ft_control_char(char **content, int rows, int columns)
{
	t_type_char tc;

	tc.n_c = 0;
	tc.n_e = 0;
	tc.n_p = 0;
	tc.row = 0;
	tc.column = 0;
	ft_control_char_count(content, rows, columns, &tc);
	if (tc.n_c <= 0 || tc.n_e <= 0 || tc.n_p <= 0)
	{
		printf("ERROR\nPARAMETROS INCORRECTOS\n");
		return (0);
	}
	return (1);
}


//GRAFICOS-----------------------------------------------------------------

void	ft_initialize_textures(t_t_i *t_i, mlx_t *mlx)
{
	t_i->t_co = mlx_load_png("./sprites/collectable.png");
	t_i->t_es = mlx_load_png("./sprites/empty_space.png");
	t_i->t_ex = mlx_load_png("./sprites/exit.png");
	t_i->t_pl = mlx_load_png("./sprites/player.png");
	t_i->t_wa = mlx_load_png("./sprites/wall.png");
	t_i->t_en = mlx_load_png("./sprites/enemy.png");
	if (!t_i->t_co || !t_i->t_es || !t_i->t_ex)
		exit (EXIT_FAILURE);
	if (!t_i->t_pl || !t_i->t_wa || !t_i->t_en)
		exit (EXIT_FAILURE);
	t_i->i_co = mlx_texture_to_image(mlx, t_i->t_co);
	t_i->i_es = mlx_texture_to_image(mlx, t_i->t_es);
	t_i->i_ex = mlx_texture_to_image(mlx, t_i->t_ex);
	t_i->i_pl = mlx_texture_to_image(mlx, t_i->t_pl);
	t_i->i_wa = mlx_texture_to_image(mlx, t_i->t_wa);
	t_i->i_en = mlx_texture_to_image(mlx, t_i->t_en);
	if (!t_i->i_co || !t_i->i_es || !t_i->i_ex)
		exit (EXIT_FAILURE);
	if (!t_i->i_pl || !t_i->i_wa || !t_i->i_en)
		exit (EXIT_FAILURE);
}

void	ft_delete_all(mlx_t *mlx, t_t_i t_i)
{
	mlx_delete_image(mlx, t_i.i_co);
	mlx_delete_image(mlx, t_i.i_es);
	mlx_delete_image(mlx, t_i.i_ex);
	mlx_delete_image(mlx, t_i.i_pl);
	mlx_delete_image(mlx, t_i.i_wa);
	mlx_delete_image(mlx, t_i.i_en);
	mlx_delete_texture(t_i.t_co);
	mlx_delete_texture(t_i.t_es);
	mlx_delete_texture(t_i.t_ex);
	mlx_delete_texture(t_i.t_pl);
	mlx_delete_texture(t_i.t_wa);
	mlx_delete_texture(t_i.t_en);
	mlx_terminate(mlx);
}

int	main(void)
{
	mlx_t	*mlx;
	t_t_i	t_i;
	int	width;
	int	height;

	width = 500;
	height = 500;
	mlx = mlx_init(width, height, "PRUEBA SPRITES UBUNTU", false);
	if (!mlx)
		exit (EXIT_FAILURE);
	ft_initialize_textures(&t_i, mlx);
	mlx_image_to_window(mlx, t_i.i_co, 32*0, 0);
	mlx_image_to_window(mlx, t_i.i_es, 32*1, 0);
	mlx_image_to_window(mlx, t_i.i_ex, 32*2, 0);
	mlx_image_to_window(mlx, t_i.i_pl, 32*3, 0);
	mlx_image_to_window(mlx, t_i.i_wa, 32*4, 0);
	mlx_image_to_window(mlx, t_i.i_en, 32*5, 0);
	mlx_loop(mlx);
	ft_delete_all(mlx, t_i);
	return (EXIT_SUCCESS);
}

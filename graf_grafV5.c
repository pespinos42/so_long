#include "so_longNEW.h"

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

int	ft_number_columns(int fd) //HAY QUE REVISAR ESTA FUNCION EN MAC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	char	*str;
	int		column1;
	int		columnn;
	int		control;

	column1 = 0;
	columnn = 0;
	control = 1;
	str = ft_get_next_line(fd);
	while (str && control == 1)
	{
		columnn = 0;
		if (column1 == 0)
		{
			column1 = ft_strlen_n(str);
			printf("C1 -> %i\t\t\t CN -> %i\n", column1, columnn);
		}
		else
		{
			columnn = ft_strlen_n(str);
			printf("C1 -> %i\t\t\t CN -> %i\n", column1, columnn);
		}
		if (column1 != columnn && columnn != 0)
			control = 0;
		str = ft_get_next_line(fd);
	}
	close(fd);
	if (control == 0)
	{
		printf("ERROR\nNO TODAS LAS LINEAS TIENEN LA MISMA LONGITUD\n");
		return (-1); //ESTO HAY QUE DESCOMENTARLO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	else
	{
		printf("NUMERO DE COLUMNAS %i\n", column1);
		return (column1); //ESTO HAY QUE METERLO DENTRO DEL ELSE Y CAMBIARLO POR COLUMN1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
}

int	ft_number_rows(int fd)
{
	int		rows;
	char	*str;

	rows = 0;
	str = ft_get_next_line(fd);
	while (str)
	{
		rows++;
		str = ft_get_next_line(fd);
	}
	printf("EL NUMERO DE LINEAS %i\n", rows);
	return (rows);
}

int	ft_check_walls(t_all data/*char **content, int rows, int columns*/)
{
	int	r;
	int	c;
	int	walls_ok;

	r = 0;
	c = 0;
	walls_ok = 1;
	while (r < data.rows && walls_ok == 1)
	{
		c = 0;
		while (c < data.columns && walls_ok == 1)
		{
			if (r != 0 && r != data.rows - 1)
			{
				if (c == 0 || c == data.columns - 1)
				{
					if (data.content[r][c] != '1')
						walls_ok = 0;
				}
			}
			else if (r == 0 || r == data.rows - 1)
			{
				if (data.content[r][c] != '1')
					walls_ok = 0;
			}
			c++;
		}
		r++;
	}
	if (walls_ok)
		return (1);
		//printf("MUROS CORRECTOS\n");
	else
		return (0);
		//printf("MUROS ERRONEOS\n");
}

char	**ft_create_content(int fd, int rows)
{
	char	**content;
	char	*str;
	int		r;

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

void	ft_control_char_count(t_all *data/*char **c, int row, int col, t_type_char *tc*/)
{	
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < data->rows)
	{
		column = 0;
		while (column < data->columns)
		{
			if (data->content[row][column] == 'C')
				data->n_c += 1;
			else if (data->content[row][column] == 'E')
				data->n_e += 1;
			else if (data->content[row][column] == 'P')
				data->n_p += 1;
			column++;
		}
		row++;
	}
	printf("C->%i\t\tE->%i\t\tP->%i\n", data->n_c, data->n_e, data->n_p);

	// while (tc->row < row)
	// {
	// 	tc->column = 0;
	// 	while (tc->column < col)
	// 	{
	// 		if (c[tc->row][tc->column] == 'C')
	// 			tc->n_c += 1;
	// 		else if (c[tc->row][tc->column] == 'E')
	// 			tc->n_e += 1;
	// 		else if (c[tc->row][tc->column] == 'P')
	// 			tc->n_p += 1;
	// 		tc->column++;
	// 	}
	// 	tc->row++;
	// }
	// printf("C->%i\t\tE->%i\t\tP->%i\n", tc->n_c, tc->n_e, tc->n_p);
}

int	ft_control_char(t_all *data/*char **content, int rows, int columns*/)
{
	//t_type_char tc;

	data->n_c = 0;
	data->n_e = 0;
	data->n_p = 0;
	// ft_control_char_count(data->content, data->rows, data->columns, &tc);
	ft_control_char_count(data);
	//printf("C->%i\t\tE->%i\t\tP->%i\n", data->n_c, data->n_e, data->n_p);
	if (data->n_c <= 0 || data->n_e <= 0 || data->n_p <= 0)
	{
		printf("ERROR\nPARAMETROS INCORRECTOS\n");
		return (0);
	}
	return (1);
}

//KERNEL-------------------------------------------------------------------

int	ft_check_enemy(int row_player, int column_player, t_point_enemy *enemies)
{
	int	index;
	int	find;

	index = 0;
	find = 0;
	while (index < enemies[0].count_enemies)
	{
		if (row_player == enemies[index].enemy_row && column_player == enemies[index].enemy_column)
			find = 1;
		index++;
	}
	return (find);
}

int	ft_check_finish(int row_player, int column_player, t_point_exit *exits)
{
	int	index;
	int	find;

	index = 0;
	find = 0;
	while (index < exits[0].count_exits)
	{
		if (row_player == exits[index].exit_row && column_player == exits[index].exit_column)
			find = 1;
		index++;
	}
	return (find);
}

void	ft_count_positions(char **content, int rows, int columns, int *count_positions, char letter)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	*count_positions = 0;
	while (r < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (content[r][c] == letter)
				*count_positions += 1;
			c++;
		}
		r++;
	}
}

t_point_exit	*ft_configure_exits(char **content, int rows, int columns)
{
	int		count_exit;
	int		r;
	int		c;
	int		n_exit;
	t_point_exit	*exits;

	count_exit = 0;
	r = 0;
	n_exit = 0;
	ft_count_positions(content, rows, columns, &count_exit, 'E');
	exits = malloc (count_exit * sizeof (*exits));
	if (!exits)
		return (NULL);
	exits[0].count_exits = count_exit;
	while (r < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (content[r][c] == 'E')
			{
				exits[n_exit].exit_row = r;
				exits[n_exit++].exit_column = c;
			}
			c++;
		}
		r++;
	}
	return (exits);
}

t_point_enemy	*ft_configure_enemies(char **content, int rows, int columns)
{
	int				count_enemies;
	int 			r;
	int				c;
	int				n_enemy;
	t_point_enemy	*enemies;

	count_enemies = 0;
	r = 0;
	n_enemy = 0;
	ft_count_positions(content, rows, columns, &count_enemies, 'E');
	enemies = malloc (count_enemies * sizeof (*enemies));
	if (!enemies)
		return (NULL);
	enemies[0].count_enemies = count_enemies;
	while (r < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (content[r][c] == 'X')
			{
				enemies[n_enemy].enemy_row = r;
				enemies[n_enemy++].enemy_column = c;
			}
			c++;
		}
		r++;
	}
	return (enemies);
}

void	ft_print_map(char **content, int rows)
{
	int	r;

	r = 0;
	while (r < rows)
		printf("%s\n", content[r++]);
}

void	ft_player_position(t_all *data)
{
	int	find;

	find = 0;
	while (data->content[data->player_row] && find == 0)
	{
		data->player_column = 0;
		while (data->content[data->player_row][data->player_column] && find == 0)
		{
			if (data->content[data->player_row][data->player_column] == 'P')
				find = 1;
			if (find == 0)
				data->player_column += 1;
		}
		if (find == 0)
			data->player_row += 1;
	}
	printf("El jugador se encuentra en la posicion [%i][%i]\n", data->player_row, data->player_column);
}

int	ft_check_prev_position(t_point_exit *exits, int row, int column)
{
	int	prev_exit;
	int	index;

	prev_exit = 0;
	index = 0;
	while (index < exits[0].count_exits && prev_exit == 0)
	{
		if (exits[index].exit_column == column && exits[index].exit_row == row)
		{
				prev_exit = 1;
				printf("LA POSICION [%i][%i] ERA UNA SALIDA\n", exits[index].exit_row, exits[index].exit_column);
		}
        index++;
	}
	return (prev_exit);
}

int	ft_check_other_position(t_all *data/*, t_point_exit *exits*/)
{
	int	ok_data;
	char str;

	ok_data = 1;
	printf("POSICION FUTURA: FILA -> %i \tCOLUMNA -> %i\n", data->op_row, data->op_column);
	if (data->op_row < 0 || data->op_row >= data->rows)
	{
		printf("FILA INVALIDA\n");
		ok_data = 0;
	}
	if (data->op_column < 0 || data->op_column >= data->columns)
	{
		printf("COLUMNA INVALIDA");
		ok_data = 0;
	}
	if (ok_data == 1)
	{
		if (data->content[data->op_row][data->op_column] != '1')
		{
			data->content[data->op_row][data->op_column] = 'P';
			if (ft_check_prev_position(data->exits, data->player_row, data->player_column))
				data->content[data->player_row][data->player_column] = 'E';
			else
				data->content[data->player_row][data->player_column] = '0';
			data->player_row = data->op_row;
			data->player_column = data->op_column;
			return (1);
		}
		else
		{	
			printf("HAY UN MURO EN ESA POSICION\n");
			return(0);
		}
	}
	else
		return (0);
	
}

int	ft_move_player(t_all *data/*char **content, t_player *player, int rows, int columns, t_point_exit *exits*/)
{	
	if (data->move == 'w')
	{
		data->op_column = data->player_column;
		data->op_row = data->player_row - 1;
	}
	else if (data->move == 'a')
	{
		data->op_column = data->player_column - 1;
		data->op_row = data->player_row;
	}
	else if (data->move == 's')
	{
		data->op_column = data->player_column;
		data->op_row = data->player_row + 1;
	}
	else if (data->move == 'd')
	{
		data->op_column = data->player_column + 1;
		data->op_row = data->player_row;
	}
    printf("POSICION ACTUAL [%i][%i]\n", data->player_row, data->player_column);
    printf("OTRA POSICION [%i][%i]\n", data->op_row, data->op_column);
	return(ft_check_other_position(data));
}

void	ft_kernel(char **content, int rows, int columns)
{
	char			key_press;
	t_player		p;
	t_point_exit	*exits;
	t_point_enemy	*enemies;
	int				n_c;
	//int							contador = 0;

	exits = ft_configure_exits(content, rows, columns);
	enemies = ft_configure_enemies(content, rows, columns);
	key_press = 0;
	p.player_row = 0;
	p.player_column = 0;
	p.op_column = 0;
	p.op_row = 0;
	p.move = 0;
	n_c = 0;
	printf("\n\n\nCOMIENZA EL JUEGO......\n");
	//ft_player_position(content, &p);
	printf("EL JUGADOR SE ENCUENTRA EN LA FILA %i COLUMNA %i\n", p.player_row, p.player_column);
	while (key_press != 'q')
	{
		// if (contador == 0)
		// 	key_press = 'd';
		// else 
		// 	key_press = 'a';
		ft_print_map(content, rows);
		printf("WASD -> ");
		scanf(" %c", &key_press);
		if (key_press != 'q')
		{
			if (key_press == 'w')
			{
				printf("JUGADOR MOVIENDOSE ARRIBA\n");
				p.move = 'w';
			}
			else if (key_press == 'a')
			{
				printf("JUGADOR MOVIENDOSE IZQUIERDA\n");
				p.move = 'a';
			}
			else if (key_press == 's')
			{
				printf("JUGADOR MOVIENDOSE ABAJO\n");
				p.move = 's';
			}
			else if (key_press == 'd')
			{
				printf("JUGADOR MOVIENDOSE DERECHA\n");
				p.move = 'd';
			}
			//ft_move_player(content, &p, rows, columns, exits);
			printf("NUEVA POSICION DEL PLAYER FILA -> %i \t COLUMNA -> %i\n", p.player_row, p.player_column);
			ft_count_positions(content, rows, columns, &n_c, 'C');
			printf("CONTADOR DE MONEDAS %i\n", n_c);
			if (n_c == 0 && ft_check_finish(p.player_row, p.player_column, exits))
			{
				printf("HAS GANADO!!!!!!!\n");
				key_press = 'q';
			}
			if (ft_check_enemy(p.player_row, p.player_column, enemies))
			{
				printf("HAS MUERTO!!!!!!!!\n");
				key_press = 'q';
			}
			
		}
		else
			printf("SALIENDO DEL JUEGO...");
		// contador++;
	}
}

//GRAFICOS-----------------------------------------------------------------

void	ft_initialize_textures(t_all *data)
{
	data->t_co = mlx_load_png("./sprites/collectable.png");
	data->t_es = mlx_load_png("./sprites/empty_space.png");
	data->t_ex = mlx_load_png("./sprites/exit.png");
	data->t_pl = mlx_load_png("./sprites/player.png");
	data->t_wa = mlx_load_png("./sprites/wall.png");
	data->t_en = mlx_load_png("./sprites/enemy.png");
	if (!data->t_co || !data->t_es || !data->t_ex)
		exit (EXIT_FAILURE);
	if (!data->t_pl || !data->t_wa || !data->t_en)
		exit (EXIT_FAILURE);
	data->i_co = mlx_texture_to_image(data->mlx, data->t_co);
	data->i_es = mlx_texture_to_image(data->mlx, data->t_es);
	data->i_ex = mlx_texture_to_image(data->mlx, data->t_ex);
	data->i_pl = mlx_texture_to_image(data->mlx, data->t_pl);
	data->i_wa = mlx_texture_to_image(data->mlx, data->t_wa);
	data->i_en = mlx_texture_to_image(data->mlx, data->t_en);
	if (!data->i_co || !data->i_es || !data->i_ex)
		exit (EXIT_FAILURE);
	if (!data->i_pl || !data->i_wa || !data->i_en)
		exit (EXIT_FAILURE);
}

void	ft_delete_all(t_all *data)
{
	mlx_delete_image(data->mlx, data->i_co);
	mlx_delete_image(data->mlx, data->i_es);
	mlx_delete_image(data->mlx, data->i_ex);
	mlx_delete_image(data->mlx, data->i_pl);
	mlx_delete_image(data->mlx, data->i_wa);
	mlx_delete_image(data->mlx, data->i_en);
	mlx_delete_texture(data->t_co);
	mlx_delete_texture(data->t_es);
	mlx_delete_texture(data->t_ex);
	mlx_delete_texture(data->t_pl);
	mlx_delete_texture(data->t_wa);
	mlx_delete_texture(data->t_en);
	mlx_terminate(data->mlx);
}

void	ft_draw_map(t_all *data)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < data->rows)
	{
		c = 0;
		while (c < data->columns)
		{
			if (data->content[r][c] == '1')
				mlx_image_to_window(data->mlx, data->i_wa, 32 * c, 32 * r);
			else if (data->content[r][c] == '0')
				mlx_image_to_window(data->mlx, data->i_es, 32 * c, 32 * r);
			else if (data->content[r][c] == 'P')
				mlx_image_to_window(data->mlx, data->i_pl, 32 * c, 32 * r);
			else if (data->content[r][c] == 'E')
				mlx_image_to_window(data->mlx, data->i_ex, 32 * c, 32 * r);
			else if (data->content[r][c] == 'C')
				mlx_image_to_window(data->mlx, data->i_co, 32 * c, 32 * r);
			else if (data->content[r][c] == 'X')
				mlx_image_to_window(data->mlx, data->i_en, 32 * c, 32 * r);
			c++;
		}
		r++;
	}
}


//MAIN--------------------------------------------------------------------------------

void	ft_op_positions(t_all *data)
{
	if (data->move == 'W')
	{
		data->op_row = data->player_row - 1;
		data->op_column = data->player_column;
	}
	else if (data->move == 'A')
	{
		data->op_row = data->player_row;
		data->op_column = data->player_column - 1;
	}
	else if (data->move == 'S')
	{
		data->op_row = data->player_row + 1;
		data->op_column = data->player_column;
	}
	else if (data->move == 'D')
	{
		data->op_row = data->player_row;
		data->op_column = data->player_column + 1;
	}
}

void	ft_keys(void *param)
{
	t_all	*d;

	d = param;
	if (mlx_is_key_down(d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(d->mlx);
	else if (mlx_is_key_down(d->mlx, MLX_KEY_W))
	{
		ft_player_position(d);
		printf("TECLA ARRIBA\n");
		d->move = 'W';
		ft_op_positions(d);
        printf("OTRA POSICION [%i][%i]\n", d->op_row, d->op_column);
	}
	else if (mlx_is_key_down(d->mlx, MLX_KEY_S))
	{
		ft_player_position(d);
		printf("TECLA ABAJO\n");
		d->move = 'S';
		ft_op_positions(d);
        printf("OTRA POSICION [%i][%i]\n", d->op_row, d->op_column);
	}
	else if (mlx_is_key_down(d->mlx, MLX_KEY_A))
	{
		ft_player_position(d);
		printf("TECLA IZQUIERDA\n");
		d->move = 'A';
		ft_op_positions(d);
        printf("OTRA POSICION [%i][%i]\n", d->op_row, d->op_column);
	}
	else if (mlx_is_key_down(d->mlx, MLX_KEY_D))
	{
		ft_player_position(d);
		printf("TECLA DERECHA\n");
		d->move = 'D';
		ft_op_positions(d);
        printf("OTRA POSICION [%i][%i]\n", d->op_row, d->op_column);
	}	
}

void	ft_initialize_data(t_all *data)
{
	int	fd;

	fd = 0;
	data->n_c = 0;
	data->n_e = 0;
	data->n_p = 0;
	data->player_row = 0;
	data->player_column = 0;
	data->op_row = 0;
	data->op_column = 0;
	data->move = 0;
	fd = open("mapa1.ber", O_RDONLY);
	data->rows = ft_number_rows(fd);
	fd = open("mapa1.ber", O_RDONLY);
	data->columns = ft_number_columns(fd);
	data->width = data->columns * 32;
	data->height = data->rows * 32;
	fd = open("mapa1.ber", O_RDONLY);
	data->content = ft_create_content(fd, data->rows);
	data->exits = ft_configure_exits(data->content, data->rows, data->columns);
	data->enemies = ft_configure_enemies(data->content, data->rows, data->columns);
}

int	main(void)
{
	t_all			d;
	//t_point_exit	*exits;
	//t_point_enemy	*enemies;
	
	ft_initialize_data(&d);
	// ft_print_map(d.content, d.rows);
	// printf("WIDTH -> %i\nHEIGHT -> %i\n", d.width, d.height);
	if (ft_control_char(&d) && ft_check_walls(d))
	{
		d.mlx = mlx_init(d.width, d.height, "V1", false);
		if (!d.mlx)
			exit(EXIT_FAILURE);
		ft_initialize_textures(&d);
		//exits = ft_configure_exits(d.content, d.rows, d.columns);
		//enemies = ft_configure_enemies(d.content, d.rows, d.columns);
		ft_draw_map(&d);
		mlx_loop_hook(d.mlx, &ft_keys, &d);
		mlx_loop(d.mlx);
		ft_delete_all(&d);
	}
	return (EXIT_SUCCESS);
}

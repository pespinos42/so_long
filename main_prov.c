/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:30:10 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/08 20:44:33 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//GET_NEXT_LINE------------------------------------------------------------------------------------------------------
char	*ft_join_free(char *buffer, char *str)
{
	char	*temp;

	temp = ft_strjoin(buffer, str);
	free (buffer);
	return (temp);
}

char	*ft_total_line(char *buffer, int fd)
{
	int		bytes;
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
	int		nl;
	int		len;
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

//GET_NEXT_LINE_UTILS------------------------------------------------------------------------------------------------------

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		p;

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

//CHECK------------------------------------------------------------------------------------------------------

typedef struct s_type_char
{
	int	n_c;
	int	n_e;
	int	n_p;
	int	row;
	int	column;
}	t_type_char;

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

void	ft_check_walls(char **content, int rows, int columns)
{
	int	r;
	int	c;
	int	walls_ok;

	r = 0;
	c = 0;
	walls_ok = 1;
	while (r < rows && walls_ok == 1)
	{
		c = 0;
		while (c < columns && walls_ok == 1)
		{
			if (r != 0 && r != rows - 1)
			{
				if (c == 0 || c == columns - 1)
				{
					if (content[r][c] != '1')
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

static void	ft_control_char_count(char **c, int row, int col, t_type_char *tc)
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
	//printf("C->%i\t\tE->%i\t\tP->%i\n", tc.n_c, tc.n_e, tc.n_p);
	if (tc.n_c <= 0 || tc.n_e <= 0 || tc.n_p <= 0)
	{
		printf("ERROR\nPARAMETROS INCORRECTOS\n");
		return (0);
	}
	return (1);
}

//KERNEL----------------------------------------------------------------------------------------------------

typedef struct s_player
{
	int		player_row;
	int		player_column;
	int		op_row;
	int		op_column;
	char	move;
}	t_player;

typedef struct s_point_exit
{
	int		exit_row;
	int		exit_column;
	int		count_exits;
}	t_point_exit;

void	ft_count_exits(char **content, int rows, int columns, int *count_exits)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (content[r][c] == 'E')
				*count_exits += 1;
			c++;
		}
		r++;
	}
}

t_point_exit	*ft_configure_exits(char **content, int rows, int columns)
{
	int				count_exit;
	int 			r;
	int				c;
	int				n_exit;
	t_point_exit	*exits;

	count_exit = 0;
	r = 0;
	n_exit = 0;
	ft_count_exits(content, rows, columns, &count_exit);
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

void	ft_print_map(char **content, int rows)
{
	int	r;

	r = 0;
	while (r < rows)
		printf("%s\n", content[r++]);
}

void	ft_player_position(char **content, t_player *player)
{
	int	find;

	find = 0;
	while (content[player->player_row] && find == 0)
	{
		player->player_column = 0;
		while (content[player->player_row][player->player_column] && find == 0)
		{
			if (content[player->player_row][player->player_column] == 'P')
				find = 1;
			if (find == 0)
				player->player_column += 1;
		}
		if (find == 0)
			player->player_row += 1;
	}
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

int	ft_check_other_position(char **content, t_player *player, int rows, int columns, t_point_exit *exits)
{
	int	ok_data;
	char str;

	ok_data = 1;
	printf("POSICION FUTURA: FILA -> %i \tCOLUMNA -> %i\n", player->op_row, player->op_column);
	if (player->op_row < 0 || player->op_row >= rows)
	{
		printf("FILA INVALIDA\n");
		ok_data = 0;
	}
	if (player->op_column < 0 || player->op_column >= columns)
	{
		printf("COLUMNA INVALIDA");
		ok_data = 0;
	}
	if (ok_data == 1)
	{
		if (content[player->op_row][player->op_column] != '1')
		{
			content[player->op_row][player->op_column] = 'P';
			if (ft_check_prev_position(exits, player->player_row, player->player_column))
				content[player->player_row][player->player_column] = 'E';
			else
				content[player->player_row][player->player_column] = '0';
			player->player_row = player->op_row;
			player->player_column = player->op_column;
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

int	ft_move_player(char **content, t_player *player, int rows, int columns, t_point_exit *exits)
{	
	if (player->move == 'w')
	{
		player->op_column = player->player_column;
		player->op_row = player->player_row - 1;
	}
	else if (player->move == 'a')
	{
		player->op_column = player->player_column - 1;
		player->op_row = player->player_row;
	}
	else if (player->move == 's')
	{
		player->op_column = player->player_column;
		player->op_row = player->player_row + 1;
	}
	else if (player->move == 'd')
	{
		player->op_column = player->player_column + 1;
		player->op_row = player->player_row;
	}
	return(ft_check_other_position(content, player, rows, columns, exits));
}

void	ft_kernel(char **content, int rows, int columns)
{
	char			key_press;
	t_player		p;
	t_point_exit	*exits;
	int								contador = 0;

	exits = ft_configure_exits(content, rows, columns);
	key_press = 0;
	p.player_row = 0;
	p.player_column = 0;
	p.op_column = 0;
	p.op_row = 0;
	p.move = 0;
	printf("\n\n\nCOMIENZA EL JUEGO......\n");
	ft_player_position(content, &p);
	printf("EL JUGADOR SE ENCUENTRA EN LA FILA %i COLUMNA %i\n", p.player_row, p.player_column);
	while (key_press != 'q')
	{
		ft_print_map(content, rows);
		printf("WASD -> ");
		scanf(" %c", &key_press);
		// if (contador == 0)
		// {
		// 	key_press = 'a';
		// 	contador++;
		// }
		// else
		// 	key_press = 'd';
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
			ft_move_player(content, &p, rows, columns, exits);
			printf("NUEVA POSICION DEL PLAYER FILA -> %i \t COLUMNA -> %i\n", p.player_row, p.player_column);
		}
		else
			printf("SALIENDO DEL JUEGO...");
	}
}

//MAIN------------------------------------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	//mlx_t	*mlx;
	char	**content;
	int		rows;
	int		columns;
	int		fd;
	int r = 0;
	//int	width = 0;
	//int height = 0;

	fd = 0;
	rows = 0;
	columns = 0;
									// if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
									// {
									// 	fd = open(argv[1], O_RDONLY);
									// 	rows = ft_number_rows(fd);
									// 	fd = open(argv[1], O_RDONLY);
									// 	columns = ft_number_columns(fd);
										
									// 	// width = columns * 32;
									// 	// height = rows * 32;
									// 	// mlx = mlx_init(width, height, "PRUEBA SPRITES", false);
										
									// 	fd = open(argv[1], O_RDONLY);
									// 	content = ft_create_content(fd, rows);
									// 	if (ft_control_char(content, rows, columns))
									// 	{
									// 		//ft_print_map(content, rows);
									// 		ft_check_walls(content, rows, columns);
									// 		ft_kernel(content, rows, columns);
									// 	}
									// 	//ft_create_map(content, rows, columns, mlx);
									// }
									// else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
									// 	write(1, "ERROR\nEXTENSION DE ARCHIVO INVALIDA\n", 36);
	fd = open("mapa1.ber", O_RDONLY);
	rows = ft_number_rows(fd);
	fd = open("mapa1.ber", O_RDONLY);
	columns = ft_number_columns(fd);
	
	// width = columns * 32;
	// height = rows * 32;
	// mlx = mlx_init(width, height, "PRUEBA SPRITES", false);
	
	fd = open("mapa1.ber", O_RDONLY);
	content = ft_create_content(fd, rows);
	if (ft_control_char(content, rows, columns))
	{
		//ft_print_map(content, rows);
		ft_check_walls(content, rows, columns);
		ft_kernel(content, rows, columns);
	}
	return (0);
}
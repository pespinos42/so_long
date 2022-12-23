/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf_graf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:26:13 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 17:00:17 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// //GET_NEXT_LINE_UTILS------------------------------------------------------

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	int		p;

// 	p = 0;
// 	str = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (s1[p])
// 	{
// 		str[p] = s1[p];
// 		p++;
// 	}
// 	while (*s2)
// 	{
// 		str[p] = *s2;
// 		p++;
// 		s2++;
// 	}
// 	str[p] = '\0';
// 	return (str);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*str;
// 	size_t	p;

// 	p = 0;
// 	str = malloc ((len + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (s[start + p] && p < len)
// 	{
// 		str[p] = s[start + p];
// 		p++;
// 	}
// 	str[p] = '\0';
// 	return (str);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	char	letter;

// 	letter = (char) c;
// 	while (*s != letter)
// 	{
// 		if (*s == '\0')
// 			return (NULL);
// 		s++;
// 	}
// 	return ((char *) s);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	return (len);
// }

// int	ft_strlen_n(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] && s[len] != '\n')
// 		len++;
// 	return (len);
// }

// //GET_NEXT_LINE------------------------------------------------------------

// char	*ft_join_free(char *buffer, char *str)
// {
// 	char *temp;

// 	temp = ft_strjoin(buffer, str);
// 	free (buffer);
// 	return (temp);
// }

// char	*ft_total_line(char *buffer, int fd)
// {
// 	int	bytes;
// 	char	*str;

// 	bytes = 1;
// 	str = malloc ((BUFFER_SIZE + 1) * sizeof (*str));
// 	if (!str)
// 	{
// 		free (str);
// 		return (NULL);
// 	}
// 	while (bytes > 0 && !ft_strchr(buffer, '\n'))
// 	{
// 		bytes = read(fd, str, BUFFER_SIZE);
// 		if (bytes < 0)
// 		{
// 			free (str);
// 			free (buffer);
// 			return (NULL);
// 		}
// 		str[bytes] = '\0';
// 		buffer = ft_join_free(buffer, str);
// 	}
// 	free (str);
// 	return (buffer);
// }

// char	*ft_to_nl(char *buffer)
// {
// 	int	nl;

// 	nl = 0;
// 	if (!*buffer)
// 		return (NULL);
// 	while (buffer[nl] && buffer[nl] != '\n')
// 		nl++;
// 	nl++;
// 	return (ft_substr(buffer, 0, nl));
// }

// char	*ft_from_nl(char *buffer)
// {
// 	int	nl;
// 	int	len;
// 	char	*str;

// 	nl = 0;
// 	len = 0;
//        	while (buffer[nl] && buffer[nl] != '\n')
// 		nl++;
// 	if (!buffer[nl])
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	nl++;
// 	len = ft_strlen(&buffer[nl]);
// 	str = ft_substr(buffer, nl, len);
// 	free (buffer);
// 	return (str);
// }

// char	*ft_get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*str;

// 	if (!buffer)
// 	{
// 		buffer = malloc (1 * sizeof (*buffer));
// 		if (!buffer)
// 		{
// 			free (buffer);
// 			return (NULL);
// 		}
// 		*buffer = 0;
// 	}
// 	buffer = ft_total_line(buffer, fd);
// 	if (!buffer || fd < 0 || BUFFER_SIZE <= 0)
// 	{
// 		free (buffer);
// 		return (NULL);
// 	}
// 	str = ft_to_nl(buffer);
// 	buffer = ft_from_nl(buffer);
// 	return (str);
// }

//CHECK--------------------------------------------------------------------

// char	*ft_strnstr(const char *b, const char *l, size_t len)
// {
// 	size_t	p1;
// 	size_t	p2;

// 	p1 = 0;
// 	if (!*l)
// 		return ((char *) b);
// 	while (b[p1] && p1 < len)
// 	{
// 		p2 = 0;
// 		while (b[p1 + p2] && b[p1 + p2] == l[p2] && p1 + p2 < len)
// 		{
// 			if (l[p2 + 1] == '\0' && b[p1 + p2 + 1] == '\0')
// 				return ((char *) &b[p1]);
// 			p2++;
// 		}
// 		p1++;
// 	}
// 	return (NULL);
// }

// int	ft_number_columns(int fd)
// {
// 	char	*str;
// 	int		column1;
// 	int		columnn;
// 	int		control;

// 	column1 = 0;
// 	columnn = 0;
// 	control = 1;
// 	str = ft_get_next_line(fd);
// 	while (str && control == 1)
// 	{
// 		columnn = 0;
// 		if (column1 == 0)
// 			column1 = ft_strlen_n(str);
// 		else
// 			columnn = ft_strlen_n(str);
// 		if (column1 != columnn && columnn != 0)
// 			control = 0;
// 		str = ft_get_next_line(fd);
// 	}
// 	close(fd);
// 	if (control == 0)
// 	{
// 		printf("ERROR\nNO TODAS LAS LINEAS TIENEN LA MISMA LONGITUD\n");
// 		return (-1); 
// 	}
// 	else
// 	{
// 		return (column1); 
// 	}
// }

// int	ft_number_rows(int fd)
// {
// 	int		rows;
// 	char	*str;

// 	rows = 0;
// 	str = ft_get_next_line(fd);
// 	while (str)
// 	{
// 		rows++;
// 		str = ft_get_next_line(fd);
// 	}
// 	return (rows);
// }

// int	ft_check_walls(t_all data)
// {
// 	int	r;
// 	int	c;
// 	int	walls_ok;

// 	r = 0;
// 	c = 0;
// 	walls_ok = 1;
// 	while (r < data.rs && walls_ok == 1)
// 	{
// 		c = 0;
// 		while (c < data.cs && walls_ok == 1)
// 		{
// 			if (r != 0 && r != data.rs - 1)
// 			{
// 				if (c == 0 || c == data.cs - 1)
// 				{
// 					if (data.con[r][c] != '1')
// 						walls_ok = 0;
// 				}
// 			}
// 			else if (r == 0 || r == data.rs - 1)
// 			{
// 				if (data.con[r][c] != '1')
// 					walls_ok = 0;
// 			}
// 			c++;
// 		}
// 		r++;
// 	}
// 	if (walls_ok)
// 		return (1);
// 	else
// 	{
// 		printf("ERROR\nMUROS ERRONEOS\n");
// 		return (0);
// 	}
// }

// char	**ft_create_content(int fd, int rows)
// {
// 	char	**content;
// 	char	*str;
// 	int		r;

// 	r = 0;
// 	content = malloc (rows * sizeof (char *));
// 	if (!content)
// 		return (NULL);
// 	str = ft_get_next_line(fd);
// 	while (str && r < rows)
// 	{
// 		content[r++] = ft_substr(str, 0, ft_strlen_n(str));
// 		str = ft_get_next_line(fd);
// 	}
// 	close(fd);
// 	return (content);
// }

// void	ft_control_char_count(t_all *data)
// {	
// 	int	row;
// 	int	column;

// 	row = 0;
// 	column = 0;
// 	while (row < data->rs)
// 	{
// 		column = 0;
// 		while (column < data->cs)
// 		{
// 			if (data->con[row][column] == 'C')
// 				data->n_c += 1;
// 			else if (data->con[row][column] == 'E')
// 				data->n_e += 1;
// 			else if (data->con[row][column] == 'P')
// 				data->n_p += 1;
// 			column++;
// 		}
// 		row++;
// 	}
// }

// int	ft_control_char(t_all *data)
// {
// 	data->n_c = 0;
// 	data->n_e = 0;
// 	data->n_p = 0;
// 	ft_control_char_count(data);
// 	if (data->n_c <= 0 || data->n_e <= 0 || data->n_p <= 0 || data->n_p > 1)
// 	{
// 		printf("ERROR\nPARAMETROS INCORRECTOS\n");
// 		return (0);
// 	}
// 	return (1);
// }

//KERNEL-------------------------------------------------------------------

// int	ft_check_enemy(t_all *d)
// {
// 	int	index;
// 	int	find;

// 	index = 0;
// 	find = 0;
// 	while (index < d->ens[0].count_enemies)
// 	{
// 		if (d->p_r == d->ens[index].enemy_row && d->p_c == d->ens[index].enemy_column)
// 			find = 1;
// 		index++;
// 	}
// 	return (find);
// }

// int	ft_check_finish(t_all *d/*int r_p, int c_p, t_point_exit *ex*/)
// {
// 	int	index;
// 	int	find;

// 	index = 0;
// 	find = 0;
// 	while (index < d->exs[0].count_exits)
// 	{
// 		if (d->p_r == d->exs[index].exit_row && d->p_c == d->exs[index].exit_column)
// 			find = 1;
// 		index++;
// 	}
// 	return (find);
// }

// void	ft_count_positions(t_all *d, int *c_p, char l)
// {
// 	int	r;
// 	int	c;

// 	r = 0;
// 	c = 0;
// 	*c_p = 0;
// 	while (r < d->rs)
// 	{
// 		c = 0;
// 		while (c < d->cs)
// 		{
// 			if (d->con[r][c] == l)
// 				*c_p += 1;
// 			c++;
// 		}
// 		r++;
// 	}
// }

// t_point_exit	*ft_configure_exits(t_all *d)
// {
// 	int		count_exit;
// 	int		r;
// 	int		c;
// 	int		n_exit;
// 	t_point_exit	*exits;

// 	count_exit = 0;
// 	r = 0;
// 	n_exit = 0;
// 	ft_count_positions(d, &count_exit, 'E');
// 	exits = malloc (count_exit * sizeof (*exits));
// 	if (!exits)
// 		return (NULL);
// 	exits[0].count_exits = count_exit;
// 	while (r < d->rs)
// 	{
// 		c = 0;
// 		while (c < d->cs)
// 		{
// 			if (d->con[r][c] == 'E')
// 			{
// 				exits[n_exit].exit_row = r;
// 				exits[n_exit++].exit_column = c;
// 			}
// 			c++;
// 		}
// 		r++;
// 	}
// 	return (exits);
// }

// t_point_enemy	*ft_configure_enemies(t_all *d)
// {
// 	int				count_enemies;
// 	int 			r;
// 	int				c;
// 	int				n_enemy;
// 	t_point_enemy	*enemies;

// 	count_enemies = 0;
// 	r = 0;
// 	n_enemy = 0;
// 	ft_count_positions(d, &count_enemies, 'E');
// 	enemies = malloc (count_enemies * sizeof (*enemies));
// 	if (!enemies)
// 		return (NULL);
// 	enemies[0].c_e = count_enemies;
// 	while (r < d->rs)
// 	{
// 		c = 0;
// 		while (c < d->cs)
// 		{
// 			if (d->con[r][c] == 'X')
// 			{
// 				enemies[n_enemy].e_r = r;
// 				enemies[n_enemy++].e_c = c;
// 			}
// 			c++;
// 		}
// 		r++;
// 	}
// 	return (enemies);
// }

// void	ft_player_position(t_all *d)
// {
// 	int	find;

// 	find = 0;
// 	while (d->con[d->p_r] && find == 0)
// 	{
// 		d->p_c = 0;
// 		while (d->con[d->p_r][d->p_c] && find == 0)
// 		{
// 			if (d->con[d->p_r][d->p_c] == 'P')
// 				find = 1;
// 			if (find == 0)
// 				d->p_c += 1;
// 		}
// 		if (find == 0)
// 			d->p_r += 1;
// 	}
// }

// int	ft_check_prev_position(t_point_exit *exits, int row, int column)
// {
// 	int	prev_exit;
// 	int	index;

// 	prev_exit = 0;
// 	index = 0;
// 	while (index < exits[0].c_e && prev_exit == 0)
// 	{
// 		if (exits[index].e_c == column && exits[index].e_r == row)
// 				prev_exit = 1;
//         index++;
// 	}
// 	return (prev_exit);
// }

// int	ft_check_other_position(t_all *d)
// {
// 	int	ok_d;
// 	char str;

// 	ok_d = 1;
// 	if (d->o_r < 0 || d->o_r >= d->rs)
// 	{
// 		printf("ERROR\nFILA INVALIDA\n");
// 		ok_d = 0;
// 	}
// 	if (d->o_c < 0 || d->o_c >= d->cs)
// 	{
// 		printf("ERROR\nCOLUMNA INVALIDA");
// 		ok_d = 0;
// 	}
// 	if (ok_d == 1)
// 	{
// 		if (d->con[d->o_r][d->o_c] != '1')
// 		{
// 			d->con[d->o_r][d->o_c] = 'P';
// 			if (ft_check_prev_position(d->exs, d->p_r, d->p_c))
// 				d->con[d->p_r][d->p_c] = 'E';
// 			else
// 				d->con[d->p_r][d->p_c] = '0';
// 			d->p_r = d->o_r;
// 			d->p_c = d->o_c;
// 			d->t_m += 1;
// 			return (1);
// 		}
// 		else
// 			return(0);
// 	}
// 	else
// 		return (0);
	
// }

//GRAFICOS-----------------------------------------------------------------

// void	ft_initialize_textures(t_all *d)
// {
// 	d->t_co = mlx_load_png("./sprites/collectable.png");
// 	d->t_es = mlx_load_png("./sprites/empty_space.png");
// 	d->t_c_ex = mlx_load_png("./sprites/closed_door.png");
// 	d->t_pl = mlx_load_png("./sprites/player.png");
// 	d->t_wa = mlx_load_png("./sprites/wall.png");
// 	d->t_en = mlx_load_png("./sprites/enemy.png");
// 	if (!d->t_co || !d->t_es || !d->t_c_ex)
// 		exit (EXIT_FAILURE);
// 	if (!d->t_pl || !d->t_wa || !d->t_en)
// 		exit (EXIT_FAILURE);
// 	d->i_co = mlx_texture_to_image(d->mlx, d->t_co);
// 	d->i_es = mlx_texture_to_image(d->mlx, d->t_es);
// 	d->i_c_ex = mlx_texture_to_image(d->mlx, d->t_c_ex);
// 	d->i_pl = mlx_texture_to_image(d->mlx, d->t_pl);
// 	d->i_wa = mlx_texture_to_image(d->mlx, d->t_wa);
// 	d->i_en = mlx_texture_to_image(d->mlx, d->t_en);
// 	if (!d->i_co || !d->i_es || !d->i_c_ex)
// 		exit (EXIT_FAILURE);
// 	if (!d->i_pl || !d->i_wa || !d->i_en)
// 		exit (EXIT_FAILURE);
// }

// void	ft_delete_all(t_all *d)
// {
// 	mlx_delete_image(d->mlx, d->i_co);
// 	mlx_delete_image(d->mlx, d->i_es);
// 	mlx_delete_image(d->mlx, d->i_c_ex);
// 	mlx_delete_image(d->mlx, d->i_pl);
// 	mlx_delete_image(d->mlx, d->i_wa);
// 	mlx_delete_image(d->mlx, d->i_en);
// 	mlx_delete_texture(d->t_co);
// 	mlx_delete_texture(d->t_es);
// 	mlx_delete_texture(d->t_c_ex);
// 	mlx_delete_texture(d->t_pl);
// 	mlx_delete_texture(d->t_wa);
// 	mlx_delete_texture(d->t_en);
// 	mlx_terminate(d->mlx);
// }

// void	ft_draw_map(t_all *d)
// {
// 	int	r;
// 	int	c;

// 	r = 0;
// 	c = 0;
// 	while (r < d->rs)
// 	{
// 		c = 0;
// 		while (c < d->cs)
// 		{
// 			if (d->con[r][c] == '1')
// 				mlx_image_to_window(d->mlx, d->i_wa, 32 * c, 32 * r);
// 			else if (d->con[r][c] == '0')
// 				mlx_image_to_window(d->mlx, d->i_es, 32 * c, 32 * r);
// 			else if (d->con[r][c] == 'P')
// 				mlx_image_to_window(d->mlx, d->i_pl, 32 * c, 32 * r);
// 			else if (d->con[r][c] == 'E')
// 				mlx_image_to_window(d->mlx, d->i_c_ex, 32 * c, 32 * r);
// 			else if (d->con[r][c] == 'C')
// 				mlx_image_to_window(d->mlx, d->i_co, 32 * c, 32 * r);
// 			else if (d->con[r][c] == 'X')
// 				mlx_image_to_window(d->mlx, d->i_en, 32 * c, 32 * r);
// 			c++;
// 		}
// 		r++;
// 	}
// }


//MAIN--------------------------------------------------------------------------------

void	ft_op_positions(t_all *d)
{
	if (d->move == 'W')
	{
		d->o_r = d->p_r - 1;
		d->o_c = d->p_c;
	}
	else if (d->move == 'A')
	{
		d->o_r = d->p_r;
		d->o_c = d->p_c - 1;
	}
	else if (d->move == 'S')
	{
		d->o_r = d->p_r + 1;
		d->o_c = d->p_c;
	}
	else if (d->move == 'D')
	{
		d->o_r = d->p_r;
		d->o_c = d->p_c + 1;
	}
}

void	ft_keys_conditions(t_all *d)
{
	ft_op_positions(d);
	ft_check_other_position(d);
	ft_draw_map(d);
	ft_count_positions(d, &d->n_c, 'C');
	if (d->n_c == 0 && ft_check_finish(d))
	{
		printf("HAS GANADO!!!!!!");
		mlx_close_window(d->mlx);
	}
	if (ft_check_enemy(d))
	{
		printf("HAS MUERTO!!!!!!");
		mlx_close_window(d->mlx);
	}
	printf("TOTAL MOVIMIENTOS -> %i\n", d->t_m);
}

void	ft_keys(mlx_key_data_t key, void *param)
{
	t_all	*d;

	d = param;
	if (key.action == MLX_PRESS)
		ft_player_position(d);
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_RELEASE)
		mlx_close_window(d->mlx);
	else if (key.key == MLX_KEY_W && key.action == MLX_RELEASE)
		d->move = 'W';
	else if (key.key == MLX_KEY_S && key.action == MLX_RELEASE)
		d->move = 'S';
	else if (key.key == MLX_KEY_A && key.action == MLX_RELEASE)
		d->move = 'A';
	else if (key.key == MLX_KEY_D && key.action == MLX_RELEASE)
		d->move = 'D';
	if (key.action == MLX_RELEASE)
	{
		ft_keys_conditions(d);
	}
}

void	ft_initialize_data(t_all *d)
{
	int	fd;

	fd = 0;
	d->n_c = 0;
	d->n_e = 0;
	d->n_p = 0;
	d->p_r = 0;
	d->p_c = 0;
	d->o_r = 0;
	d->o_c = 0;
	d->move = 0;
	fd = open("mapa1.ber", O_RDONLY);
	d->rs = ft_number_rows(fd);
	fd = open("mapa1.ber", O_RDONLY);
	d->cs = ft_number_columns(fd);
	d->w = d->cs * 32;
	d->h = d->rs * 32;
	fd = open("mapa1.ber", O_RDONLY);
	d->con = ft_create_content(fd, d->rs);
	d->exs = ft_configure_exits(d);
	d->ens = ft_configure_enemies(d);
	d->t_m = 0;
}

int	main(int argc, char **argv)
{
	t_all			d;

	if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		ft_initialize_data(&d);
		if (ft_control_char(&d) && ft_check_walls(d))
		{
			d.mlx = mlx_init(d.w, d.h, "V1", false);
			if (!d.mlx)
				exit(EXIT_FAILURE);
			ft_initialize_textures(&d);
			ft_draw_map(&d);
			mlx_key_hook(d.mlx, &ft_keys, &d);
			mlx_loop(d.mlx);
			ft_delete_all(&d);
		}
	}
	else
		printf("ERROR\nNUMERO DE PARAMETROS O ARCHIVO ERRONEO\n");
	return (EXIT_SUCCESS);
}

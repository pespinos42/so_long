/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:46:12 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/05 19:09:45 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			if (l[p2 + 1] == '\0')
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
	ft_control_char_count(content, rows, columns, &tc);
	//printf("C->%i\t\tE->%i\t\tP->%i\n", tc.n_c, tc.n_e, tc.n_p);
	if (tc.n_c <= 0 || tc.n_e <= 0 || tc.n_p <= 0)
	{
		printf("ERROR\nPARAMETROS INCORRECTOS\n");
		return (0);
	}
	return (1);
}
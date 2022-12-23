/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 13:21:32 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 15:45:52 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	ft_conditions_columns(int *c1, int *cn, int *control, char *str)
{
	if (*c1 == 0)
		*c1 = ft_strlen_n(str);
	else
		*cn = ft_strlen_n(str);
	if (*c1 != *cn && *cn != 0)
		*control = 0;
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
		ft_conditions_columns(&column1, &columnn, &control, str);
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
		return (column1);
	}
}

void	ft_conditions_walls(int r, int c, int *walls_ok, t_all data)
{
	if (r != 0 && r != data.rs - 1)
	{
		if (c == 0 || c == data.cs - 1)
		{
			if (data.con[r][c] != '1')
				walls_ok = 0;
		}
	}
	else if (r == 0 || r == data.rs - 1)
	{
		if (data.con[r][c] != '1')
			walls_ok = 0;
	}
}

int	ft_check_walls(t_all data)
{
	int	r;
	int	c;
	int	walls_ok;

	r = 0;
	c = 0;
	walls_ok = 1;
	while (r < data.rs && walls_ok == 1)
	{
		c = 0;
		while (c < data.cs && walls_ok == 1)
		{
			ft_conditions_walls(r, c, &walls_ok, data);
			c++;
		}
		r++;
	}
	if (walls_ok)
		return (1);
	else
	{
		printf("ERROR\nMUROS ERRONEOS\n");
		return (0);
	}
}

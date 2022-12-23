/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:45:22 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 15:46:14 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	return (rows);
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

void	ft_control_char_count(t_all *data)
{	
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (row < data->rs)
	{
		column = 0;
		while (column < data->cs)
		{
			if (data->con[row][column] == 'C')
				data->n_c += 1;
			else if (data->con[row][column] == 'E')
				data->n_e += 1;
			else if (data->con[row][column] == 'P')
				data->n_p += 1;
			column++;
		}
		row++;
	}
}

int	ft_control_char(t_all *data)
{
	data->n_c = 0;
	data->n_e = 0;
	data->n_p = 0;
	ft_control_char_count(data);
	if (data->n_c <= 0 || data->n_e <= 0 || data->n_p <= 0 || data->n_p > 1)
	{
		printf("ERROR\nPARAMETROS INCORRECTOS\n");
		return (0);
	}
	return (1);
}

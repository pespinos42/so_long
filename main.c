/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:30:10 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/06 19:11:24 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	mlx_t	*mlx;
	char	**content;
	int		rows;
	int		columns;
	int		fd;
	int r = 0;
	int	width = 0;
	int height = 0;

	fd = 0;
	rows = 0;
	columns = 0;
	if (argc == 2 && ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
	{
		fd = open(argv[1], O_RDONLY);
		rows = ft_number_rows(fd);
		fd = open(argv[1], O_RDONLY);
		columns = ft_number_columns(fd);
		
		width = columns * 32;
		height = rows * 32;
		mlx = mlx_init(width, height, "PRUEBA SPRITES", false);
		
		fd = open(argv[1], O_RDONLY);
		content = ft_create_content(fd, rows);
		if (ft_control_char(content, rows, columns))
		{
			while (r < rows)
				printf("%s\n", content[r++]);
			ft_check_walls(content, rows, columns);
		}
		ft_create_map(content, rows, columns, mlx);
	}
	else if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		write(1, "ERROR\nEXTENSION DE ARCHIVO INVALIDA\n", 36);
	return (0);
}
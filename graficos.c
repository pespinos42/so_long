/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graficos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:37:05 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/04 14:01:12 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data_window
{
	int		width;
	int		height;
	mlx_t	*mlx;
}	t_data_window;

typedef struct s_data_img
{
	int			width;
	int			height;
	mlx_image_t	*img;
	int			position_x;
	int			position_y;
}	t_data_img;

void	ft_fill_image(mlx_image_t *img, int width, int height, int color)
{
	int	px;
	int	py;

	px = 0;
	py = 0;
	while (px < width)
	{
		py = 0;
		while (py < height)
		{
			mlx_put_pixel(img ,px, py, color);
			py++;
		}
		px++;
	}
}

int main()
{
	int px = 0;
	int py = 0;

	t_data_window dw;
	t_data_img *di;

	dw.width = 500;
	dw.height = 500;

	di = malloc (3 * sizeof (*di));
	if (!di)
		exit(EXIT_FAILURE);
		
	dw.mlx = mlx_init(dw.width, dw.height, "VENTANA", false);
	if (!dw.mlx)
		exit(EXIT_FAILURE);
		
	di[0].width = 32;
	di[0].height = 32;
	di[0].position_x = 0;
	di[0].position_y = 0;
	di[0].img = mlx_new_image(dw.mlx, di[0].width, di[0].height);
	mlx_image_to_window(dw.mlx, di[0].img, di[0].position_x, di[0].position_y);
	ft_fill_image(di[0].img, di[0].width, di[0].height, 0xFF0000FF);

	di[1].width = 32;
	di[1].height = 32;
	di[1].position_x = 32;
	di[1].position_y = 0;
	di[1].img = mlx_new_image(dw.mlx, di[1].width, di[1].height);
	mlx_image_to_window(dw.mlx, di[1].img, di[1].position_x, di[1].position_y);
	ft_fill_image(di[1].img, di[1].width, di[1].height, 0x00FF00FF);

	di[2].width = 32;
	di[2].height = 32;
	di[2].position_x = 64;
	di[2].position_y = 0;
	di[2].img = mlx_new_image(dw.mlx, di[2].width, di[2].height);
	mlx_image_to_window(dw.mlx, di[2].img, di[2].position_x, di[2].position_y);
	ft_fill_image(di[2].img, di[2].width, di[2].height, 0x0000FFFF);
	
	mlx_loop(dw.mlx);
	mlx_delete_image(dw.mlx, di[0].img);
	mlx_delete_image(dw.mlx, di[1].img);
	mlx_delete_image(dw.mlx, di[2].img);
	mlx_terminate(dw.mlx);
	return (EXIT_SUCCESS);
}
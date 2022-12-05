/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graficos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:37:05 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/05 18:40:25 by pespinos         ###   ########.fr       */
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
	mlx_t			*mlx;
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				width;
	int				height;

	width = 500;
	height = 500;
	mlx = mlx_init(width, height, "TEXTURAS", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	texture = mlx_load_png("./sprite_prueba.png");
	if (!texture)
		exit(EXIT_FAILURE);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		exit(EXIT_FAILURE);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img, 32, 0);
	img->instances[0].x += 100;
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
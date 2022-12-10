/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graficos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 12:37:05 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/10 13:20:47 by pespinos         ###   ########.fr       */
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

typedef struct s_t_i
{
	mlx_texture_t	*t_collectable;
	mlx_texture_t	*t_empty_space;
	mlx_texture_t	*t_exit;
	mlx_texture_t	*t_player;
	mlx_texture_t	*t_wall;
	mlx_texture_t	*t_enemy;
	mlx_image_t		*i_collectable;
	mlx_image_t		*i_empty_space;
	mlx_image_t		*i_exit;
	mlx_image_t		*i_player;
	mlx_image_t		*i_wall;
	mlx_image_t		*i_enemy;
}	t_t_i;

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

void	ft_initialize_textures(t_t_i *t_i, mlx_t *mlx)
{
	t_i->t_collectable = mlx_load_png("./sprites/collectable.png");
	t_i->t_empty_space = mlx_load_png("./sprites/empty_space.png");
	t_i->t_exit = mlx_load_png("./sprites/exit.png");
	t_i->t_player = mlx_load_png("./sprites/player.png");
	t_i->t_wall = mlx_load_png("./sprites/wall.png");
	t_i->t_enemy = mlx_load_png("./sprites/enemy.png");
	if (!t_i->t_collectable || !t_i->t_empty_space || !t_i->t_exit)
		exit(EXIT_FAILURE);
	if (!t_i->t_player || !t_i->t_wall || !t_i->t_enemy)
		exit(EXIT_FAILURE);
	t_i->i_collectable = mlx_texture_to_image(mlx, t_i->t_collectable);
	t_i->i_empty_space = mlx_texture_to_image(mlx, t_i->t_empty_space);
	t_i->i_exit = mlx_texture_to_image(mlx, t_i->t_exit);
	t_i->i_player = mlx_texture_to_image(mlx, t_i->t_player);
	t_i->i_wall = mlx_texture_to_image(mlx, t_i->t_wall);
	t_i->i_enemy = mlx_texture_to_image(mlx, t_i->t_enemy);
	if (!t_i->i_collectable || !t_i->i_empty_space || !t_i->i_exit)
		exit(EXIT_FAILURE);
	if (!t_i->i_player || !t_i->i_wall || !t_i->i_enemy)
		exit(EXIT_FAILURE);
}

void	ft_delete_all(mlx_t *mlx, t_t_i t_i)
{
	mlx_delete_image(mlx, t_i.i_collectable);
	mlx_delete_image(mlx, t_i.i_empty_space);
	mlx_delete_image(mlx, t_i.i_exit);
	mlx_delete_image(mlx, t_i.i_player);
	mlx_delete_image(mlx, t_i.i_wall);
	mlx_delete_image(mlx, t_i.i_enemy);
	mlx_delete_texture(t_i.t_collectable);
	mlx_delete_texture(t_i.t_empty_space);
	mlx_delete_texture(t_i.t_exit);
	mlx_delete_texture(t_i.t_player);
	mlx_delete_texture(t_i.t_wall);
	mlx_delete_texture(t_i.t_enemy);
	mlx_terminate(mlx);
}

int main()
{
	mlx_t			*mlx;
	t_t_i			t_i;
	int				width;
	int				height;
	
	width = 500;
	height = 500;
	mlx = mlx_init(width, height, "TEXTURAS", false);
	if (!mlx)
		exit(EXIT_FAILURE);
	// texture = mlx_load_png("./sprites/wall.png");
	// if (!texture)
	// 	exit(EXIT_FAILURE);
	// img = mlx_texture_to_image(mlx, texture);
	// if (!img)
	// 	exit(EXIT_FAILURE);
	ft_initialize_textures(&t_i, mlx);
	mlx_image_to_window(mlx, t_i.i_collectable, 0, 0);
	mlx_image_to_window(mlx, t_i.i_empty_space, 32, 0);
	mlx_image_to_window(mlx, t_i.i_exit, 64, 0);
	mlx_image_to_window(mlx, t_i.i_player, 96, 0);
	mlx_image_to_window(mlx, t_i.i_wall, 128, 0);
	mlx_image_to_window(mlx, t_i.i_enemy, 160, 0);
	mlx_loop(mlx);
	ft_delete_all(mlx, t_i);
	return (EXIT_SUCCESS);
}
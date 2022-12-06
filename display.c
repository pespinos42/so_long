/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:07:04 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/06 19:26:59 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_texture
{
	mlx_texture_t	*collectable;
	mlx_texture_t	*empty_space;
	mlx_texture_t	*ex;
	mlx_texture_t	*player;
	mlx_texture_t	*wall;
	mlx_image_t		*img_collectable;
	mlx_image_t		*img_empty_space;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_player;
	mlx_image_t		*img_wall;
	int				r;
	int				c;
}	t_texture;

static void	ft_create_textures(mlx_t *mlx, t_texture *t)
{
	t->collectable = mlx_load_png("./sprites/collectable.png");
	t->empty_space = mlx_load_png("./sprites/empty_space.png");
	t->ex = mlx_load_png("./sprites/exit->png");
	t->player = mlx_load_png("./sprites/player.png");
	t->wall = mlx_load_png("./sprites/wall.png");
	if (!t->collectable || !t->empty_space || !t->ex || !t->player || !t->wall)
		exit(EXIT_FAILURE);
	t->img_collectable = mlx_texture_to_image(mlx, t->collectable);
	t->img_empty_space = mlx_texture_to_image(mlx, t->empty_space);
	t->img_exit = mlx_texture_to_image(mlx, t->ex);
	t->img_player = mlx_texture_to_image(mlx, t->player);
	t->img_wall = mlx_texture_to_image(mlx, t->wall);
	if (!t->img_collectable || !t->img_empty_space || !t->img_exit)
		exit(EXIT_FAILURE);
	if (!t->img_player || !t->img_wall)
		exit(EXIT_FAILURE);
}

static void	ft_fill_display(mlx_t *mlx, t_texture t, int rows, int columns, char **content)
{
	int	r;
	int	c;

	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < columns)
		{
			if (content[r][c] == 'C')
				mlx_image_to_window(mlx, t.img_collectable, 32 * r, 32 * c);
			else if (content[r][c] == '0')
				mlx_image_to_window(mlx, t.img_empty_space, 32 * r, 32 * c);
			else if (content[r][c] == 'E')
				mlx_image_to_window(mlx, t.img_exit, 32 * r, 32 * c);
			else if (content[r][c] == 'P')
				mlx_image_to_window(mlx, t.img_player, 32 * r, 32 * c);
			else if (content[r][c] == '1')
				mlx_image_to_window(mlx, t.img_wall, 32 * r, 32 * c);
			c++;
		}
		r++;
	}
}

void	ft_create_map(char **content, int rows, int columns, mlx_t *mlx)
{
	t_texture t;
	
	ft_create_textures(mlx, &t);
	ft_fill_display(mlx, t, rows, columns, content);
	mlx_loop(mlx);
	mlx_delete_image(mlx, t.img_collectable);
	mlx_delete_image(mlx, t.img_empty_space);
	mlx_delete_image(mlx, t.img_exit);
	mlx_delete_image(mlx, t.img_player);
	mlx_delete_image(mlx, t.img_wall);
	mlx_delete_texture(t.collectable);	
	mlx_delete_texture(t.empty_space);	
	mlx_delete_texture(t.ex);	
	mlx_delete_texture(t.player);	
	mlx_delete_texture(t.wall);
	mlx_terminate(mlx);
}
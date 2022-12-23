/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graficos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:30:28 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 16:32:37 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_initialize_textures(t_all *d)
{
	d->t_co = mlx_load_png("./sprites/collectable.png");
	d->t_es = mlx_load_png("./sprites/empty_space.png");
	d->t_c_ex = mlx_load_png("./sprites/closed_door.png");
	d->t_pl = mlx_load_png("./sprites/player.png");
	d->t_wa = mlx_load_png("./sprites/wall.png");
	d->t_en = mlx_load_png("./sprites/enemy.png");
	if (!d->t_co || !d->t_es || !d->t_c_ex)
		exit (EXIT_FAILURE);
	if (!d->t_pl || !d->t_wa || !d->t_en)
		exit (EXIT_FAILURE);
	d->i_co = mlx_texture_to_image(d->mlx, d->t_co);
	d->i_es = mlx_texture_to_image(d->mlx, d->t_es);
	d->i_c_ex = mlx_texture_to_image(d->mlx, d->t_c_ex);
	d->i_pl = mlx_texture_to_image(d->mlx, d->t_pl);
	d->i_wa = mlx_texture_to_image(d->mlx, d->t_wa);
	d->i_en = mlx_texture_to_image(d->mlx, d->t_en);
	if (!d->i_co || !d->i_es || !d->i_c_ex)
		exit (EXIT_FAILURE);
	if (!d->i_pl || !d->i_wa || !d->i_en)
		exit (EXIT_FAILURE);
}

void	ft_delete_all(t_all *d)
{
	mlx_delete_image(d->mlx, d->i_co);
	mlx_delete_image(d->mlx, d->i_es);
	mlx_delete_image(d->mlx, d->i_c_ex);
	mlx_delete_image(d->mlx, d->i_pl);
	mlx_delete_image(d->mlx, d->i_wa);
	mlx_delete_image(d->mlx, d->i_en);
	mlx_delete_texture(d->t_co);
	mlx_delete_texture(d->t_es);
	mlx_delete_texture(d->t_c_ex);
	mlx_delete_texture(d->t_pl);
	mlx_delete_texture(d->t_wa);
	mlx_delete_texture(d->t_en);
	mlx_terminate(d->mlx);
}

void	ft_draw_conditions(t_all *d, int c, int r)
{
	if (d->con[r][c] == '1')
		mlx_image_to_window(d->mlx, d->i_wa, 32 * c, 32 * r);
	else if (d->con[r][c] == '0')
		mlx_image_to_window(d->mlx, d->i_es, 32 * c, 32 * r);
	else if (d->con[r][c] == 'P')
		mlx_image_to_window(d->mlx, d->i_pl, 32 * c, 32 * r);
	else if (d->con[r][c] == 'E')
		mlx_image_to_window(d->mlx, d->i_c_ex, 32 * c, 32 * r);
	else if (d->con[r][c] == 'C')
		mlx_image_to_window(d->mlx, d->i_co, 32 * c, 32 * r);
	else if (d->con[r][c] == 'X')
		mlx_image_to_window(d->mlx, d->i_en, 32 * c, 32 * r);
}

void	ft_draw_map(t_all *d)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < d->rs)
	{
		c = 0;
		while (c < d->cs)
		{
			ft_draw_conditions(d, c, r);
			c++;
		}
		r++;
	}
}

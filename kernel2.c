/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:05:00 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 16:24:22 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_loop_row_ene(t_all *d, t_row_column rc, t_point_enemy *e, int *n_e)
{
	while (rc.c < d->cs)
	{
		if (d->con[rc.r][rc.c] == 'X')
		{
			e[*n_e].e_r = rc.r;
			e[*n_e].e_c = rc.c;
			*n_e += 1;
		}
		rc.c++;
	}
}

t_point_enemy	*ft_configure_enemies(t_all *d)
{
	int				count_enemies;
	t_row_column	rc;
	int				n_enemy;
	t_point_enemy	*enemies;

	count_enemies = 0;
	rc.r = 0;
	n_enemy = 0;
	ft_count_positions(d, &count_enemies, 'E');
	enemies = malloc (count_enemies * sizeof (*enemies));
	if (!enemies)
		return (NULL);
	enemies[0].c_e = count_enemies;
	while (rc.r < d->rs)
	{
		rc.c = 0;
		ft_loop_row_ene(d, rc, enemies, &n_enemy);
		rc.r++;
	}
	return (enemies);
}

void	ft_player_position(t_all *d)
{
	int	find;

	find = 0;
	while (d->con[d->p_r] && find == 0)
	{
		d->p_c = 0;
		while (d->con[d->p_r][d->p_c] && find == 0)
		{
			if (d->con[d->p_r][d->p_c] == 'P')
				find = 1;
			if (find == 0)
				d->p_c += 1;
		}
		if (find == 0)
			d->p_r += 1;
	}
}

int	ft_check_prev_position(t_point_exit *exits, int row, int column)
{
	int	prev_exit;
	int	index;

	prev_exit = 0;
	index = 0;
	while (index < exits[0].c_e && prev_exit == 0)
	{
		if (exits[index].e_c == column && exits[index].e_r == row)
				prev_exit = 1;
		index++;
	}
	return (prev_exit);
}

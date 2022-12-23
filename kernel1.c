/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:53:49 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 16:19:50 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_enemy(t_all *d)
{
	int	index;
	int	find;

	index = 0;
	find = 0;
	while (index < d->ens[0].c_e)
	{
		if (d->p_r == d->ens[index].e_r && d->p_c == d->ens[index].e_c)
			find = 1;
		index++;
	}
	return (find);
}

int	ft_check_finish(t_all *d)
{
	int	index;
	int	find;

	index = 0;
	find = 0;
	while (index < d->exs[0].c_e)
	{
		if (d->p_r == d->exs[index].e_r && d->p_c == d->exs[index].e_c)
			find = 1;
		index++;
	}
	return (find);
}

void	ft_count_positions(t_all *d, int *c_p, char l)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	*c_p = 0;
	while (r < d->rs)
	{
		c = 0;
		while (c < d->cs)
		{
			if (d->con[r][c] == l)
				*c_p += 1;
			c++;
		}
		r++;
	}
}

void	ft_loop_row_exits(t_all *d, t_row_column rc, t_point_exit *e, int *n_e)
{
	while (rc.c < d->cs)
	{
		if (d->con[rc.r][rc.c] == 'E')
		{
			e[*n_e].e_r = rc.r;
			e[*n_e].e_c = rc.c;
			*n_e += 1;
		}
		rc.c++;
	}
}

t_point_exit	*ft_configure_exits(t_all *d)
{
	t_row_column	rc;
	int				count_exit;
	int				n_exit;
	t_point_exit	*exits;

	count_exit = 0;
	rc.r = 0;
	n_exit = 0;
	ft_count_positions(d, &count_exit, 'E');
	exits = malloc (count_exit * sizeof (*exits));
	if (!exits)
		return (NULL);
	exits[0].c_e = count_exit;
	while (rc.r < d->rs)
	{
		rc.c = 0;
		ft_loop_row_exits(d, rc, exits, &n_exit);
		rc.r++;
	}
	return (exits);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pespinos <pespinos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:25:06 by pespinos          #+#    #+#             */
/*   Updated: 2022/12/23 16:28:19 by pespinos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_op_conditions(t_all *d, int *ok_d)
{
	if (d->o_r < 0 || d->o_r >= d->rs)
	{
		printf("ERROR\nFILA INVALIDA\n");
		*ok_d = 0;
	}
	if (d->o_c < 0 || d->o_c >= d->cs)
	{
		printf("ERROR\nCOLUMNA INVALIDA");
		*ok_d = 0;
	}
}

int	ft_check_other_position(t_all *d)
{
	int		ok_d;
	char	str;

	ok_d = 1;
	ft_op_conditions(d, &ok_d);
	if (ok_d == 1)
	{
		if (d->con[d->o_r][d->o_c] != '1')
		{
			d->con[d->o_r][d->o_c] = 'P';
			if (ft_check_prev_position(d->exs, d->p_r, d->p_c))
				d->con[d->p_r][d->p_c] = 'E';
			else
				d->con[d->p_r][d->p_c] = '0';
			d->p_r = d->o_r;
			d->p_c = d->o_c;
			d->t_m += 1;
			return (1);
		}
		else
			return (0);
	}
	else
		return (0);
}

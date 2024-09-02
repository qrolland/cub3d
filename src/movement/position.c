/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:19:35 by qrolland          #+#    #+#             */
/*   Updated: 2023/07/26 14:58:08 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_position(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->max_x - 0.25)
		return (0);
	if (y < 0.25 || y >= data->max_y -0.25)
		return (0);
	if (data->map[(int)y][(int)x] == '1')
		return (0);
	return (1);
}

int	position(t_data *data, double x, double y)
{
	int	moved;

	moved = 0;
	if (check_position(data, x, data->player.pos_y))
	{
		data->player.pos_x = x;
		moved = 1;
	}
	if (check_position(data, data->player.pos_x, y))
	{
		data->player.pos_y = y;
		moved = 1;
	}
	return (moved);
}

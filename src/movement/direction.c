/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:19:42 by qrolland          #+#    #+#             */
/*   Updated: 2023/07/26 14:57:41 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_ns(t_player *player)
{
	if (player->chr == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
	else if (player->chr == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else
		return ;
}

static void	set_player_ew(t_player *player)
{
	if (player->chr == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (player->chr == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else
		return ;
}

static void	set_player_direction(t_player *player)
{
	set_player_ns(player);
	set_player_ew(player);
}

void	init_player(t_player *player, int x, int y, char chr)
{
	player->chr = chr;
	player->pos_x = x;
	player->pos_y = y;
	set_player_direction(player);
	player->has_moved = 0;
	player->move_x = 0;
	player->move_y = 0;
	player->rotate = 0;
}

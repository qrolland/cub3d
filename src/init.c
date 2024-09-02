/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:11:14 by afelten           #+#    #+#             */
/*   Updated: 2023/07/26 14:56:24 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->camera_x = 0;
	ray->dir_x = 0;
	ray->dir_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->sidedist_x = 0;
	ray->sidedist_y = 0;
	ray->deltadist_x = 0;
	ray->deltadist_y = 0;
	ray->perp_walldist = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->hit = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_x = 0;
	ray->side = 0;
}

static int	create_texture_pixels(t_data *data)
{
	int	i;
	int	j;

	data->texture_pixels = malloc(sizeof(int *) * (data->win_height + 1));
	if (!data->texture_pixels)
		return (0);
	data->texture_pixels[data->win_height] = 0;
	i = 0;
	while (i < data->win_height)
	{
		data->texture_pixels[i] = malloc(sizeof(int) * (data->win_width + 1));
		if (!data->texture_pixels[i])
			return (0);
		j = -1;
		while (++j < data->win_width)
			data->texture_pixels[i][j] = 0;
		i++;
	}
	return (1);
}

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->mlx_win = mlx_new_window(
			data->mlx, data->win_width, data->win_height, "cub3d");
	if (!data->mlx_win)
	{
		free_data(data);
		return (0);
	}
	return (create_texture_pixels(data));
}

static void	init_tex(t_tex *tex)
{
	int	i;

	tex->index = 0;
	tex->pos = 0;
	tex->step = 0;
	tex->x = 0;
	tex->y = 0;
	i = -1;
	while (++i < TEX_NBR)
	{
		tex->size[i] = TEX_SIZE;
	}
}

int	init_data(t_data *data)
{
	int	i;

	data->mlx = 0;
	data->mlx_win = 0;
	data->win_height = RES_HEIGHT;
	data->win_width = RES_WIDTH;
	data->texture_pixels = 0;
	data->map = 0;
	data->max_x = 0;
	data->max_y = 0;
	data->c_color = -1;
	data->f_color = -1;
	i = -1;
	while (++i < TEX_NBR)
	{
		data->f_imgs[i].img.img = 0;
		data->f_imgs[i].img.addr = 0;
	}
	init_tex(&data->tex);
	return (init_mlx(data));
}

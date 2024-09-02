/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:40:13 by afelten           #+#    #+#             */
/*   Updated: 2023/07/26 13:40:14 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"

int	check_parse_map(char **map, t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_isinlist(map[i][j], "0NSEW")
				&& (i == 0 || i == data->max_y - 1 || j == 0
				|| j == (int)ft_strlen(map[i]) - 1
				|| map[i - 1][j] == ' ' || map[i + 1][j] == ' '
				|| map[i][j - 1] == ' ' || map[i][j + 1] == ' '))
				return (0);
			if (ft_isinlist(map[i][j], "NSEW"))
				player++;
		}
	}
	if (player == 0 || player > 1)
		return (0);
	return (1);
}

int	check_parse_info(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_NBR)
		if (!data->f_imgs[i].img.img || !data->f_imgs[i].img.addr)
			return (0);
	if (data->c_color == -1 || data->f_color == -1)
		return (0);
	return (1);
}

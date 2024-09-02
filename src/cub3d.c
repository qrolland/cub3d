/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:39:34 by afelten           #+#    #+#             */
/*   Updated: 2023/07/26 13:39:38 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3d.h"
#include <stdlib.h>
#include <stdio.h>

int	print_error(char *str)
{
	if (write(2, str, ft_strlen(str)))
		return (0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (!print_error("Incorrect number of arguments\n"));
	if (!init_data(&data))
		return (!print_error("Initialisation unsuccessful\n"));
	if (!parse_file(&data, argv[1]))
	{
		free_data(&data);
		return (1);
	}
	display(&data);
	mlx_hook(data.mlx_win, 33, 0L, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}

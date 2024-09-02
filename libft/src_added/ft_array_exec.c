/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <afelten@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:59:41 by afelten           #+#    #+#             */
/*   Updated: 2023/07/26 14:59:41 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_array_exec(void **array, int len, void funct(void *))
{
	int		i;

	if (!array)
		return ;
	i = 0;
	while (i < len)
	{
		funct(array[i]);
		i++;
	}
}

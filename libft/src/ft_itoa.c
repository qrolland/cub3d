/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afelten <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:17:03 by afelten           #+#    #+#             */
/*   Updated: 2022/05/04 13:01:59 by afelten          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	get_len_nbr(int n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (1);
	while (n > 9 || n < -9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*nbr;

	neg = 0;
	if (n < 0)
		neg = 1;
	len = get_len_nbr(n) + neg;
	nbr = malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (0);
	if (neg)
		nbr[0] = '-';
	if (n == 0)
		nbr[0] = '0';
	nbr[len] = 0;
	while (n != 0 && --len != -1)
	{
		if (neg)
			nbr[len] = (n % 10) * -1 + 48;
		else
			nbr[len] = n % 10 + 48;
		n /= 10;
	}
	return (nbr);
}

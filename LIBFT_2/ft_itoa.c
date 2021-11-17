/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsaturn <wsaturn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:10:10 by wsaturn           #+#    #+#             */
/*   Updated: 2021/10/18 19:53:45 by wsaturn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int static	dlnbr(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		i;

	i = dlnbr(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	arr = (char *)malloc(sizeof(char) * (i + 1));
	if (arr == NULL)
		return (NULL);
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		arr[0] = '-';
	}
	arr[i--] = '\0';
	while (n / 10 > 0 && n != -2147483648)
	{
		arr[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	arr[i] = (n % 10) + '0';
	return (arr);
}

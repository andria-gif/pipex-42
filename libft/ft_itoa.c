/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iota.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 20:05:36 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/04 19:38:45 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	while (n / 10 != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long		num;
	int			sign;

	num = n;
	sign = (num < 0);
	if (sign)
		num = -num;
	len = ft_numlen(num) + sign;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > sign)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

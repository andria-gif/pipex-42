/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:53:25 by arosa-di          #+#    #+#             */
/*   Updated: 2024/10/23 19:36:40 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*str;
	unsigned char		carc;
	size_t				i;

	str = (unsigned char *) s;
	carc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == carc)
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	return (0);
}

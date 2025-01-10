/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:40:18 by arosa-di          #+#    #+#             */
/*   Updated: 2024/10/19 22:12:20 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*j;

	i = 0;
	j = (unsigned char *) b;
	while (i < len)
	{
		j[i++] = (unsigned char )c;
	}
	return (b);
}

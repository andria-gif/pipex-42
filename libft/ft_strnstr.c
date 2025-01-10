/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:47:42 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/06 18:51:36 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		count;

	i = 0;
	j = 0;
	count = 0;
	if (!*little)
		return ((char *) big);
	while (big[count] && count < len)
	{
		while (big[i] == little[j] && (i < len))
		{
			i++;
			j++;
			if (j == (size_t) ft_strlen(little))
				return ((char *) &big[i - j]);
		}
		j = 0;
		count++;
		i = count;
	}
	return (NULL);
}

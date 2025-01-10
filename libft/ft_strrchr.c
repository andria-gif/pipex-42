/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:01:19 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/06 18:33:42 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = NULL;
	while (*s != '\0')
	{
		if (*s == (char) c)
			end = ((char *)s);
		s++;
	}
	if ((unsigned char)c == 0)
		return ((char *)s);
	return (end);
}

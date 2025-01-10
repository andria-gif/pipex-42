/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 23:47:01 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/04 19:43:59 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (s[size])
		size++;
	new = (char *)malloc(sizeof(*new) * size + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new [i] = s[i];
		i++;
	}
	new [i] = '\0';
	return (new);
}

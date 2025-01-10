/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:31:14 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/07 20:35:38 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			str_len;

	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
	{
		len = str_len - start;
	}
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	ft_strlcpy(substring, s + start, len + 1);
	return (substring);
}

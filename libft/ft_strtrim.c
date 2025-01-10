/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:37:03 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/11 17:50:30 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			s1_start;
	size_t			s1_size;
	size_t			s1_end;
	char			*result;

	s1_start = 0;
	s1_size = ft_strlen(s1);
	s1_end = s1_size - 1;
	if (!s1 || !set)
		return (NULL);
	while (s1[s1_start] && ft_strchr(set, s1[s1_start]))
		s1_start++;
	while (s1_end > s1_start && ft_strchr(set, s1[s1_end]))
		s1_end--;
	if (s1_start > s1_end)
		return (ft_strdup(""));
	result = (char *) malloc(s1_end - s1_start +2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + s1_start, s1_end - s1_start + 2);
	return (result);
}

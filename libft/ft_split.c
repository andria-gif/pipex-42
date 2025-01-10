/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosa-di <arosa-di@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:09:42 by arosa-di          #+#    #+#             */
/*   Updated: 2024/11/06 18:27:57 by arosa-di         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter_word(const char *str, char c)
{
	int		i;
	int		number_of_words;
	int		in_word;

	i = 0;
	number_of_words = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] != c && (in_word == 0))
		{
			in_word = 1;
			number_of_words++;
			i++;
		}
		if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (number_of_words);
}

static char	*word_dup(const char *start, const char *end)
{
	size_t		len;
	char		*new_str;

	len = end - start;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	ft_strlcpy (new_str, start, len + 1);
	return (new_str);
}

static void	ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char					**split;
	int						i;
	const char				*start;

	i = 0;
	split = (char **)malloc((ft_counter_word(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			split[i] = word_dup(start, s);
			if (!split[i++])
			{
				return (ft_free_split(split), NULL);
			}
		}
		else
			s++;
	}
	return (split[i] = NULL, split);
}

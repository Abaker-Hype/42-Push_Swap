/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:24:10 by abaker            #+#    #+#             */
/*   Updated: 2021/09/07 14:24:10 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (i == 0)
				count++;
			else if (s[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

static char	*getsubstring(char const *s, char c, int index)
{
	unsigned int	start;
	size_t			len;

	start = 0;
	len = 0;
	while (s[start] == c)
		start++;
	while (index > 0)
	{
		start++;
		if (s[start] != c && s[start - 1] == c)
			index--;
	}
	while ((s[start + len] != '\0') && (s[start + len] != c))
		len++;
	return (ft_substr(s, start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		splits;
	int		i;

	i = 0;
	splits = splitcount(s, c);
	array = (char **)malloc(sizeof(char **) * (splits + 1));
	if (!array)
		return (NULL);
	while (i < splits)
	{
		array[i] = getsubstring(s, c, i);
		i++;
	}
	array[splits] = 0;
	return (array);
}

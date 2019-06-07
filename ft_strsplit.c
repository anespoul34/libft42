/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anespoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:08:36 by anespoul          #+#    #+#             */
/*   Updated: 2015/12/05 11:20:23 by anespoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_wordlen(char *s, char c, int n)
{
	int		i;

	i = 0;
	while (s[n + i] != c && s[n + i])
	{
		i++;
	}
	return (i);
}

static int		ft_wordnbr(char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = -1;
	while (s[i])
	{
		i++;
		if (s[i + k] != c)
		{
			while (s[i + k] != c && s[i])
			{
				i++;
			}
			j++;
		}
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc((ft_wordnbr(s, c) + 1) * sizeof(char*));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
		{
			str[j] = 0;
			return (str);
		}
		str[j] = ft_strsub((char*)s, i, ft_wordlen((char*)s, c, i));
		i = i + ft_wordlen((char*)s, c, i);
		j++;
	}
	str[j] = 0;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:28:11 by tle               #+#    #+#             */
/*   Updated: 2021/04/01 17:25:40 by tle              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	size_m(char const *s, char c)
{
	int	res;
	int	n;

	if (!*s)
		return (1);
	n = 0;
	res = 0;
	while (s[n] == c)
		n++;
	while (s[n])
	{
		if (s[n] != c && (s[n + 1] == c || s[n + 1] == '\0'))
			res += 1;
		n++;
	}
	return (res + 1);
}

int	cell_size(char const *s, char c, int count)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (s[i] == c)
		i++;
	while (count)
	{
		if (s[i] == c && s[i + 1] != c)
			count--;
		i++;
	}
	while (s[i + res] != c && s[i + res])
		res++;
	return (res + 1);
}

void	error_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

char	*cell(char const *s, char c, int count)
{
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * cell_size(s, c, count));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (count)
	{
		if (s[i] == c && s[i + 1] != c)
			count--;
		i++;
	}
	while (s[i + j] != c)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		size;
	char	**str;

	if (!s)
		return (NULL);
	size = size_m(s, c);
	str = (char **)malloc(sizeof(char *) * size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		str[i] = cell(s, c, i);
		if (!str[i])
		{
			error_free(str);
			free(str);
			return (NULL);
		}
		i++;
	}
	str[i] = NULL;
	return (str);
}

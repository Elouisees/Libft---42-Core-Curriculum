/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:05:12 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/29 16:48:39 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_count(const char *s, char c)
{
	int	sign;
	int	count;
	int	i;

	sign = 0;
	count = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && sign == 0)
		{
			sign = 1;
			count++;
		}
		else if (*s == c)
			sign = 0;
		s++;
	}
	return (count);
}

static int	get_word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static char	**fill_arr(const char *s, char c, char **arr)
{
	int	j;
	int	size_word;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		size_word = get_word_len(s, c);
		arr[j] = malloc((size_word + 1) * sizeof(char));
		if (!arr[j])
		{
			free_arr(arr);
			return (NULL);
		}
		ft_memcpy(arr[j], s, size_word);
		arr[j][size_word] = '\0';
		j++;
		s += size_word;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(const char *s, char c)
{
	char	**arr;
	int		word_count;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		arr = malloc(sizeof(char *));
		if (!arr)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	word_count = get_word_count(s, c);
	arr = malloc((word_count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	arr = fill_arr(s, c, arr);
	if (!arr)
	{
		free_arr(arr);
		return (NULL);
	}
	return (arr);
}

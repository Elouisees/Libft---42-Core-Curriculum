/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:16:59 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/28 12:43:47 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cpy_str(char *substr, const char *s, unsigned int start,
		size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(char *)(substr + i) = *(char *)(s + start + i);
		i++;
	}
	substr[len] = '\0';
	return (substr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*empty;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
	{
		empty = malloc(1 * sizeof(char));
		if (!empty)
			return (NULL);
		empty[0] = '\0';
		return (empty);
	}
	substr = malloc(len + 1 * sizeof(char));
	if (!substr)
		return (NULL);
	cpy_str(substr, s, start, len);
	return (substr);
}

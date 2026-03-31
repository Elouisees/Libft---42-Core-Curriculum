/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:34:06 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/26 00:54:01 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimstr;
	size_t	s1_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	trimstr = ft_substr(s1, i, s1_len - i);
	return (trimstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:05:24 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/25 08:43:59 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*newstr;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	newstr = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		newstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < s2_len)
	{
		newstr[i + j] = s2[j];
		j++;
	}
	newstr[s1_len + s2_len] = '\0';
	return (newstr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 11:07:41 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/26 06:47:56 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	str_len;
	char	*newstr;
	int		j;

	str_len = ft_strlen(string) + 1;
	if (string == NULL)
		return (NULL);
	newstr = malloc(str_len * sizeof(char));
	if (!newstr)
		return (NULL);
	j = 0;
	while (string[j])
	{
		newstr[j] = string[j];
		j++;
	}
	newstr[j] = '\0';
	return (&newstr[0]);
}

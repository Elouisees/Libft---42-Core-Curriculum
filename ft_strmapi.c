/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:45:02 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/24 16:47:25 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	newstr_len;
	char	*newstr;
	size_t	i;

	newstr_len = ft_strlen(s);
	newstr = malloc((newstr_len + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < newstr_len)
	{
		newstr[i] = (*f)(i, s[i]);
		i++;
	}
	newstr[i] = '\0';
	return (&newstr[0]);
}

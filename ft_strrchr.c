/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:17:36 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/26 19:02:08 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	str_len;

	str_len = ft_strlen(str);
	if (c == '\0')
		return ((char *)(str + str_len));
	while (str_len > 0)
	{
		if (str[str_len - 1] == (char)c)
			return ((char *)(str + str_len - 1));
		str_len--;
	}
	return (NULL);
}

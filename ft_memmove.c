/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:12:13 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/25 16:53:44 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	size_t	i;

	i = 0;
	if (dest_str < src_str)
	{
		while (i < numBytes)
		{
			*(char *)(dest_str + i) = *(char *)(src_str + i);
			i++;
		}
	}
	else if (dest_str > src_str)
	{
		while (numBytes > 0)
		{
			*(char *)(dest_str + numBytes - 1) = *(char *)(src_str + numBytes
					- 1);
			numBytes--;
		}
	}
	return (dest_str);
}

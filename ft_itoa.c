/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:06:33 by eschloss          #+#    #+#             */
/*   Updated: 2026/03/26 06:54:57 by eschloss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	get_size(long nb)
{
	if (nb < 10)
		return (1);
	return (count_digits(nb));
}

static void	neg_num_str(char *s, int s_len, long nb, int sign)
{
	int	j;

	j = s_len - 1;
	s[s_len] = '\0';
	while (j >= sign)
	{
		s[j] = (nb % 10) + '0';
		nb /= 10;
		j--;
	}
	if (sign == 1)
		s[0] = '-';
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	long	nb;
	char	*newstr;

	sign = 0;
	size = 0;
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		size = 1;
		nb = -nb;
	}
	size += get_size(nb);
	newstr = malloc((size + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	neg_num_str(newstr, size, nb, sign);
	newstr[size] = '\0';
	return (&newstr[0]);
}

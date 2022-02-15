/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <faustino.adr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 00:48:12 by afaustin          #+#    #+#             */
/*   Updated: 2021/09/08 20:53:05 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nelements(long num)
{
	int	c;

	c = 0;
	if (num == 0)
		c += 1;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		el;
	int		flag;
	char	*str;
	long	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	el = ft_nelements(num) + flag;
	str = (char *)malloc(el + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (flag > 0)
		str[0] = '-';
	str[el] = '\0';
	while (el-- > flag)
	{
		str[el] = ((num % 10) + '0');
		num = num / 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <faustino.adr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 21:08:46 by afaustin          #+#    #+#             */
/*   Updated: 2021/09/14 13:44:45 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*b;

	b = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			b = ((char *) s);
		s++;
	}
	if (!c)
		return ((char *) s);
	else if (c)
		return (b);
	return (NULL);
}

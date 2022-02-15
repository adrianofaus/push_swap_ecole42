/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <faustino.adr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 18:13:22 by afaustin          #+#    #+#             */
/*   Updated: 2021/09/07 19:07:47 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	find;

	ptr = (unsigned char *) s;
	find = (unsigned char) c;
	while (n)
	{
		if (*ptr == find)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}

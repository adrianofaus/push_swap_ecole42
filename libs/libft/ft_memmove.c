/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <faustino.adr@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:53:11 by afaustin          #+#    #+#             */
/*   Updated: 2021/09/14 15:58:28 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*new;
	const unsigned char		*origin;
	size_t					i;

	new = (unsigned char *)dest;
	origin = (unsigned char *)src;
	i = 0;
	if (!new && !origin)
		return (NULL);
	if (origin < new)
		while (++i <= n)
			new[n - i] = origin [n - i];
	else
		while (n--)
			*new++ = *origin++;
	return (dest);
}

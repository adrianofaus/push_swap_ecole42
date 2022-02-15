/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:37 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:39 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	normalize(t_stacks *stacks)
{
	t_doubly_list	*pivot;
	t_doubly_list	*pivot_aux;

	pivot = stacks->stack_a;
	while (pivot->next)
	{
		pivot_aux = pivot->next;
		while (pivot_aux)
		{
			if (pivot->content > pivot_aux->content)
				pivot->index++;
			else
				pivot_aux->index++;
			pivot_aux = pivot_aux->next;
		}
		pivot = pivot->next;
	}
	return ;
}

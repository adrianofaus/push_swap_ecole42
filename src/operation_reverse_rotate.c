/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:43 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:45 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stacks *stacks, int flag)
{
	t_doubly_list	*last_element;

	if (stacks->stack_a->next == NULL)
		return ;
	last_element = ft_doubly_lstlast(stacks->stack_a);
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	ft_doubly_lstadd_front(&(stacks->stack_a), last_element);
	if (flag == 1)
		ft_putendl_fd("rra", 1);
	return ;
}

void	rrb(t_stacks *stacks, int flag)
{
	t_doubly_list	*last_element;

	if (stacks->stack_b->next == NULL)
		return ;
	last_element = ft_doubly_lstlast(stacks->stack_b);
	last_element->prev->next = NULL;
	last_element->prev = NULL;
	ft_doubly_lstadd_front(&(stacks->stack_b), last_element);
	if (flag == 1)
		ft_putendl_fd("rrb", 1);
	return ;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	ft_putendl_fd("rrr", 1);
	return ;
}

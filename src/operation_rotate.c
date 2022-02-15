/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:46 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:48 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks *stacks, int flag)
{
	t_doubly_list	*temp;

	if (!stacks->stack_a->next)
		return ;
	temp = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->prev = NULL;
	ft_doubly_lstadd_back(&(stacks->stack_a), temp);
	if (flag == 1)
		ft_putendl_fd("ra", 1);
	return ;
}

void	rb(t_stacks *stacks, int flag)
{
	t_doubly_list	*temp;

	if (stacks->stack_b->next == NULL)
		return ;
	temp = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->prev = NULL;
	ft_doubly_lstadd_back(&(stacks->stack_b), temp);
	if (flag == 1)
		ft_putendl_fd("rb", 1);
	return ;
}

void	rr(t_stacks *stacks)
{
	ra(stacks, 0);
	rb(stacks, 0);
	ft_putendl_fd("rr", 1);
	return ;
}

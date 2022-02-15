/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:49 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:51 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stacks *stacks, int flag)
{
	t_doubly_list	*new_second;
	t_doubly_list	*third;

	if (ft_doubly_lstsize(stacks->stack_a) < 2)
		return ;
	new_second = stacks->stack_a;
	third = stacks->stack_a->next->next;
	stacks->stack_a = stacks->stack_a->next;
	stacks->stack_a->prev = NULL;
	stacks->stack_a->next = new_second;
	new_second->next = third;
	new_second->prev = stacks->stack_a;
	if (third)
		third->prev = stacks->stack_a->next;
	if (flag == 1)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stacks *stacks, int flag)
{
	t_doubly_list	*new_second;
	t_doubly_list	*third;

	if (ft_doubly_lstsize(stacks->stack_b) < 2)
		return ;
	new_second = stacks->stack_b;
	third = stacks->stack_b->next->next;
	stacks->stack_b = stacks->stack_b->next;
	stacks->stack_b->prev = NULL;
	new_second->prev = stacks->stack_b;
	new_second->next = third;
	stacks->stack_b->next = new_second;
	if (third)
		third->prev = new_second;
	if (flag == 1)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stacks *stacks)
{
	sa(stacks, 0);
	sb(stacks, 0);
	ft_putendl_fd("ss", 1);
}

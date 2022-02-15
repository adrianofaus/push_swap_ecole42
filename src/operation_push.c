/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:41 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:42 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stacks *stacks)
{
	t_doubly_list	*first_element_stack_b;
	t_doubly_list	*old_stack_a;

	if (!stacks->stack_b)
		return ;
	first_element_stack_b = stacks->stack_b;
	stacks->stack_b = stacks->stack_b->next;
	if (ft_doubly_lstsize(stacks->stack_b) > 0)
		stacks->stack_b->prev = NULL;
	if (!stacks->stack_a)
	{
		stacks->stack_a = first_element_stack_b;
		stacks->stack_a->next = NULL;
		stacks->stack_a->prev = NULL;
	}
	else
	{
		old_stack_a = stacks->stack_a;
		stacks->stack_a = first_element_stack_b;
		stacks->stack_a->next = old_stack_a;
		old_stack_a->prev = stacks->stack_a;
	}
	ft_putendl_fd("pa", 1);
}

void	pb(t_stacks *stacks)
{
	t_doubly_list	*first_element_stack_a;
	t_doubly_list	*old_stack_b;

	if (!stacks->stack_a)
		return ;
	first_element_stack_a = stacks->stack_a;
	stacks->stack_a = stacks->stack_a->next;
	if (ft_doubly_lstsize(stacks->stack_a) > 0)
		stacks->stack_a->prev = NULL;
	if (!stacks->stack_b)
	{
		stacks->stack_b = first_element_stack_a;
		stacks->stack_b->next = NULL;
		stacks->stack_b->prev = NULL;
	}
	else
	{
		old_stack_b = stacks->stack_b;
		stacks->stack_b = first_element_stack_a;
		stacks->stack_b->next = old_stack_b;
		old_stack_b->prev = stacks->stack_b;
	}
	ft_putendl_fd("pb", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:35:00 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 22:34:18 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include "stdio.h"

int	rotate_stack_a(int count_rbs, t_stacks *stacks)
{
	if (count_rbs > 0)
	{
		rr(stacks);
		count_rbs--;
	}
	else
		ra(stacks, 1);
	return (count_rbs);
}

int	send_small_element_to_b(int count_rbs, t_stacks *stacks)
{
	while (count_rbs > 0)
	{
		rb(stacks, 1);
		count_rbs--;
	}
	pb(stacks);
	return (count_rbs);
}

static int	should_it_stay_or_should_it_go(t_stacks *stacks, t_doubly_list *current)
{
	int				count;
	int				i;
	t_doubly_list	*tmp;
	t_doubly_list	*next_curr;

	count = 1;
	i = 0;
	tmp = current->next;
	next_curr = current;
	while (i < stacks->stack_size)
	{
		if (tmp == NULL)
			tmp = stacks->stack_a;
		if (next_curr->index - tmp->index == -1)
		{
			count++;
			next_curr = tmp;
		}
		i++;
		tmp = tmp->next;
	}
	return (count);
}

static void	mark_initialize(t_stacks *stacks)
{
	t_doubly_list	*start;

	start = stacks->stack_a;
	while (stacks->stack_a != NULL)
	{
		stacks->stack_a->stay = 0;
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a = start;
}

static void	put_mark(t_stacks *stacks, t_marks mark_up)
{
	int			i;
	t_doubly_list	*start;
	t_doubly_list	*tmp;

	mark_initialize(stacks);
	i = 0;
	start = stacks->stack_a;
	stacks->stack_a = mark_up.node;
	stacks->stack_a->stay = 1;
	tmp = mark_up.node->next;
	while (i < stacks->stack_size)
	{
		if (tmp == NULL)
			tmp = start;
		if (stacks->stack_a->index - tmp->index == -1)
		{
			stacks->stack_a = tmp;
			stacks->stack_a->stay = 1;
		}
		i++;
		tmp = tmp->next;
	}
	stacks->stack_a = start;
}

void	get_mark(t_stacks *stacks)
{
	int				mark_ups[stacks->stack_size];
	int				i;
	t_marks			current_mark;
	t_doubly_list	*tmp;

	i = 0;
	tmp = stacks->stack_a;
	current_mark.staying = 0;
	current_mark.node = NULL;
	while (i < stacks->stack_size)
	{
		mark_ups[i] = should_it_stay_or_should_it_go(stacks, tmp);
		if (!i || (mark_ups[i] > current_mark.staying))
		{
			current_mark.staying = mark_ups[i];
			current_mark.node = tmp;
		}
		else if (mark_ups[i] == current_mark.staying && current_mark.node->index > tmp->index)
			current_mark.node = tmp;
		i++;
		tmp = tmp->next;
	}
	stacks->min_base = current_mark.staying;
	put_mark(stacks, current_mark);
}
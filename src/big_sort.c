/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:15 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/15 02:03:26 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

static void	split_in_groups(t_stacks *stacks)
{
	int	max_index;
	int	counter;

	if (stacks->stack_size >= 500)
		stacks->groups = 12;
	else if (stacks->stack_size < 500 && stacks->stack_size > 5)
		stacks->groups = 5;
	if (stacks->stack_size % stacks->groups)
		stacks->groups++;
	stacks->max_values = (int *)malloc(sizeof(int) * stacks->groups);
	max_index = stacks->stack_size / stacks->groups;
	counter = 0;
	while (max_index <= stacks->stack_size)
	{
		if (stacks->stack_size % stacks->groups != 0
			&& counter == stacks->groups - 1)
			max_index = stacks->stack_size;
		stacks->max_values[counter] = max_index - 1;
		counter++;
		max_index += stacks->stack_size / stacks->groups;
	}
}

static void	sorting_groups(t_stacks *stacks)
{
	t_counts	count;
	int			total_elements;

	total_elements = 0;
	initialise_counts(&count, stacks);
	while (total_elements < (stacks->stack_size - stacks->min_base))
	{
		if (stacks->stack_a->index <= stacks->max_values[count.small_group] && stacks->stack_a->stay == FALSE)
		{
			count.rbs = send_small_element_to_b(count.rbs, stacks);
			count.small_elements++;
			total_elements++;
		}
		else if (stacks->stack_a->index <= stacks->max_values[count.big_group]
			&& stacks->stack_a->index > stacks->max_values[count.big_group - 1] && stacks->stack_a->stay == FALSE)
		{
			pb(stacks);
			count.big_elements--;
			count.rbs++;
			total_elements++;
		}
		else
			count.rbs = rotate_stack_a(count.rbs, stacks);
		if (count.small_elements == stacks->max_values[count.small_group])
			count.small_group++;
		if (count.big_group > 0
			&& count.big_elements == stacks->max_values[count.big_group - 1])
			count.big_group--;
	}
}

static void	sort_and_push_back_to_a(t_stacks *stacks)
{
	int	index;
	int	stop;
	int	count;

	count = 0;
	stop = stacks->stack_a->index + stacks->min_base;
	if ((stacks->stack_a->index + stacks->min_base) != stacks->stack_size)
	{
		index = stacks->stack_a->index;
	}
	else
	{
		index = stacks->stack_size;
	}
	while (--index >= 0)
	{
		send_to_top_b(stacks, index);
		pa(stacks);
		count++;
	}
	if (count < stacks->stack_size - stacks->min_base)
	{
		index = stacks->stack_size;
		while (--index >= stop)
		{
			send_to_top_b(stacks, index);
			pa(stacks);
		}
	}
	return ;
}

static void	put_at_first(t_stacks *stacks)
{
	int	i;
	int	flag;
	t_doubly_list	*tmp;

	i = 1;
	flag = 0;
	tmp = stacks->stack_a;
	while (tmp != NULL && !flag)
	{
		if (tmp->next != NULL && tmp->index < tmp->next->index)
			i++;
		if (tmp->next != NULL && tmp->index > tmp->next->index)
			flag = 1;
		tmp = tmp->next;
	}
	while (i > 0 && flag)
	{
		ra(stacks, 1);
		i--;
	}
}

void	big_sort(t_stacks *stacks)
{
	get_mark(stacks);
	split_in_groups(stacks);
	sorting_groups(stacks);
	put_at_first(stacks);
	sort_and_push_back_to_a(stacks);
	put_at_first(stacks);
	return ;
}

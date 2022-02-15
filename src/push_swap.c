/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:55 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/15 01:20:45 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	sort(t_stacks *stacks)
{
	int	list_size;

	list_size = ft_doubly_lstsize(stacks->stack_a);
	if (list_size <= 3)
		sort_three(stacks);
	else if (list_size <= 5)
		sort_five(stacks);
	else
		big_sort(stacks);
	return ;
}

void	push_swap(t_stacks *stacks)
{
	sort(stacks);
	return ;
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc >= 2)
	{
		if (validate_input(&stacks, argc, argv) == 1)
		{
			if (!is_sorted_asc(stacks.stack_a))
			{
				push_swap(&stacks);
				for (t_doubly_list	*tmp = stacks.stack_a; tmp != NULL; tmp = tmp->next)
				{
					printf("%d ", tmp->content);
				}

			}
			free_stacks(&stacks);
		}
	}
	return (0);
}

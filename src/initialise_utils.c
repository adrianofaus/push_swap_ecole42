/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:34:31 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:34:33 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialise_counts(t_counts *counts, t_stacks *stacks)
{
	counts->small_group = 0;
	counts->small_elements = 0;
	counts->big_group = stacks->groups - 1;
	counts->big_elements = stacks->max_values[stacks->groups - 1];
	counts->rbs = 0;
	return ;
}

void	initialise(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->max_values = NULL;
	stacks->stack_size = 0;
	stacks->groups = 0;
	return ;
}

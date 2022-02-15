/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaustin <afaustin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:35:00 by afaustin          #+#    #+#             */
/*   Updated: 2022/02/14 12:35:02 by afaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

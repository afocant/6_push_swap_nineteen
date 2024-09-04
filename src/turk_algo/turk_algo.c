/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:47:58 by afocant           #+#    #+#             */
/*   Updated: 2024/09/04 14:05:45 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	fn_find_position(t_node *node, t_node *stack)
{
	unsigned int	pos;
	t_node			*ptr;

	pos = 0;
	ptr = stack;
	while (ptr && ptr != node)
	{
		pos++;
		ptr = ptr->next;
	}
	return (pos);
}

int	ft_is_above_median(t_node *node, t_node *stack)
{
	unsigned int	len;
	unsigned int	median;
	unsigned int	position;

	len = fn_stacklen(stack);
	median = len / 2;
	position = fn_find_position(node, stack);
	if (position <= median)
		return (TRUE);
	else
		return (FALSE);
}

void	ft_last_rotate(t_node **stack_a)
{
	t_node	*min;

	min = fn_find_min(*stack_a);
	while (*stack_a != min)
	{
		if (ft_is_above_median(min, *stack_a))
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	ft_turk_algo(t_node **stack_a, t_node **stack_b)
{
	int	n;
	int	len;

	n = 2;
	len = fn_stacklen(*stack_a);
	while (len > 3 && n--)
	{
		pb(stack_a, stack_b);
		len--;
	}
	while (len-- > 3)
	{
		ft_set_targets_smaller(stack_a, stack_b);
		ft_set_costs(stack_a, stack_b);
		ft_push_cheapest(stack_a, stack_b, A, B);
	}
	fn_sort_three(stack_a);
	len = fn_stacklen(*stack_b);
	while (len--)
	{
		ft_set_targets_bigger(stack_b, stack_a);
		ft_set_costs(stack_b, stack_a);
		ft_push_cheapest(stack_b, stack_a, B, A);
	}
	ft_last_rotate(stack_a);
}

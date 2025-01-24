/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:04:00 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/24 14:05:01 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_all(t_stack **stack_a, t_stack **stack_b)
{
	assign_target_b(&(*stack_a), &(*stack_b));
	index_assign(&(*stack_a), &(*stack_b));
	median_assign(&(*stack_a), &(*stack_b));
	cost_of_push(&(*stack_a), &(*stack_b));
	find_cheapest(&(*stack_a));
}

void	assign_all2(t_stack **stack_a, t_stack **stack_b)
{
	assign_target_a(&(*stack_a), &(*stack_b));
	index_assign(&(*stack_a), &(*stack_b));
	median_assign(&(*stack_a), &(*stack_b));
	cost_of_push(&(*stack_b), &(*stack_a));
	find_cheapest(&(*stack_b));
}

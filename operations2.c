/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:12:08 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/28 14:44:44 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(&(*stack_a));
	swap(&(*stack_b));
	ft_printf("ss\n");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(&(*stack_a));
	rotate(&(*stack_b));
	ft_printf("rr\n");
}

void	rotate_down_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(&(*stack_a));
	rotate_down(&(*stack_b));
	ft_printf("rrr\n");
}

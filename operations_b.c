/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:50:04 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/29 11:45:26 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **give, t_stack **receive)
{
	t_stack	*temp;

	if (!*give)
		return ;
	if ((*give)->next == NULL)
	{
		(*give)->next = *receive;
		(*receive)->prev = *give;
		*receive = *give;
		*give = NULL;
		ft_printf("pa\n");
		return ;
	}
	else
	{
		temp = (*give)->next;
		(*give)->next = *receive;
		if (*receive != NULL)
			(*receive)->prev = *give;
		*receive = *give;
		*give = temp;
		(*give)->prev = NULL;
	}
	ft_printf("pa\n");
}

void	swap_b(t_stack **list)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (!*list)
		return ;
	if (!(*list)->next)
		return ;
	temp_a = *list;
	temp_b = *list;
	temp_b = temp_b->next;
	temp_a->next = temp_b->next;
	temp_a->prev = temp_b;
	temp_b->next = temp_a;
	temp_b->prev = NULL;
	*list = temp_b;
	ft_printf("sb\n");
}

void	rotate_b(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	ft_printf("rb\n");
}

void	rotate_down_b(t_stack **stack)
{
	t_stack	*last;
	t_stack	*b4last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	b4last = ft_lst_before_last(*stack);
	b4last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
	ft_printf("rrb\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:15 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/22 19:19:18 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **give, t_stack **receive)
{
	t_stack	*temp;

	if (!*give)
			return;
	if ((*give)->next == NULL)
	{
		(*give)->next = *receive;
		(*receive)->prev = *give;
		*receive = *give;
		
		return;
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
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	swap(t_stack **list)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	    
	if (!*list)
		return;
	if (!(*list)->next)
		return;
	temp_a = *list;
	temp_b = *list;
	temp_b = temp_b->next;
	
	temp_a->next = temp_b->next;
	temp_a->prev = temp_b;
	temp_b->next = temp_a;
	temp_b->prev = NULL;
	*list = temp_b;
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap(&(*stack_a));
	swap(&(*stack_b));
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return;
	if (!(*stack)->next)
		return;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	write(1, "ra", 2);
	write(1, "\n", 1);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(&(*stack_a));
	rotate(&(*stack_b));
}

void	rotate_down(t_stack **stack)
{
	t_stack	*last;
	t_stack	*b4last;

	if (!*stack)
		return;
	if (!(*stack)->next)
		return;
	last = ft_lstlast(*stack);
	b4last = ft_lst_before_last(*stack);
	b4last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	rotate_down_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_down(&(*stack_a));
	rotate_down(&(*stack_b));
}


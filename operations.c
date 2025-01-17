/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:28:15 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/19 01:09:09 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(s_list **give, s_list **receive)
{
	s_list	*temp;

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

void	swap(s_list **list)
{
	s_list	*temp_a;
	s_list	*temp_b;
	    
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

void	swap_both(s_list **stack_a, s_list **stack_b)
{
	swap(&(*stack_a));
	swap(&(*stack_b));
}

void	rotate(s_list **stack)
{
	s_list	*first;
	s_list	*last;

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

void	rotate_both(s_list **stack_a, s_list **stack_b)
{
	rotate(&(*stack_a));
	rotate(&(*stack_b));
}

void	rotate_down(s_list **stack)
{
	s_list	*last;
	s_list	*b4last;

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

void	rotate_down_both(s_list **stack_a, s_list **stack_b)
{
	rotate_down(&(*stack_a));
	rotate_down(&(*stack_b));
}


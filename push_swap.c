/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/14 14:54:03 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(s_list **stack_a, s_list **stack_b)
{
	if (stack_length(*stack_a) == 3)
		return (sort_3(&(*stack_a)));
	if (stack_length(*stack_a) == 2)
		return (sort_2(&(*stack_a)));
	sort_a_to_b(&(*stack_a), &(*stack_b));
	
}
void	sort_a_to_b(s_list **stack_a, s_list **stack_b)
{
	if (stack_length(*stack_a) == 4)
		push(&(*stack_a), &(*stack_b));
	if (stack_length(*stack_a) > 4)
	{
		push(&(*stack_a), &(*stack_b));
		push(&(*stack_a), &(*stack_b));
	}
}
void	individual_cost(s_list **stack)
{
	s_list	*temp;
	int		i;

	temp = *stack;
	i = 1;
	while (temp->above_median != 0)
	{
		temp->cost = temp->index - 1;
		temp = temp->next;
	}
	temp = ft_lstlast(*stack);
	while (temp->above_median != 1)
	{
		temp->cost = i;
		i++;
		temp = temp->prev;
	}
}

void	cost_of_push(s_list **give, s_list **receive)
{
	s_list	*temp;
	
	individual_cost(&(*give));
	individual_cost(&(*receive));
	temp = *give;
	while (temp != NULL)
	{
		temp->cost = (temp->cost) + (temp->target->cost);
		temp = temp->next;
	}
}

int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	// getBit(5, 10);
	// printbin(5);
	// bin(7);
	int	tab[] = {2, 3, 1, 7, 4, 19};
	int	tab2[] = {2, 13, 5, 6};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*test = NULL;
	stack_a = assign_list(tab, 6);
	stack_b = assign_list(tab2, 4);
	
	// push_swap(&stack_a, &stack_b);
	index_assign(&stack_a, &stack_b);
	median_assign(&stack_a, &stack_b);
	// individual_cost(&stack_b);
	cost_of_push(&stack_a, &stack_b);

	while (stack_a != NULL)
	{
		printf("%d\n", stack_a->cost);
		stack_a = stack_a->next;
	}
	
	// print_list(stack_a);
	// printf("\n");
	// print_list(stack_b);
}
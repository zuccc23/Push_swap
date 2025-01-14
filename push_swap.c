/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/14 19:37:35 by dahmane          ###   ########.fr       */
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
	// while (stack_length(*stack_a) > 3)
	// {
	// 	assign_all(&(*stack_a), &(*stack_b));
	// 	printf("test");
	// }

	
	
	return (sort_3(&(*stack_a)));
}

void	push_cheapest_to_b(s_list **stack_a, s_list **stack_b)
{
	s_list	*temp;

	temp = *stack_a;
	while (temp->cheapest != 1)
		temp = temp->next;
	if (temp->above_median = 1)
	{
		while (temp->index != 1)
		{
			rotate();
		}
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
	int	tab[] = {3, 2, 1, 7, 4, 19};
	int	tab2[] = {2, 3, 5, 8, 9};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*test = NULL;
	stack_a = assign_list(tab, 4);
	// stack_b = assign_list(tab2, 4);
	
	push_swap(&stack_a, &stack_b);
	// assign_all(&stack_a, &stack_b);

	// while (stack_a != NULL)
	// {
	// 	printf("index : %d value : %d target(value) : %d cost : %d cheapest : %d\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest);
	// 	stack_a = stack_a->next;
	// }
	
	print_list(stack_a);
	printf("\n");
	print_list(stack_b);
}
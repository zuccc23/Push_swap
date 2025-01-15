/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/15 12:32:38 by dahmane          ###   ########.fr       */
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

	
}

void	move_b(s_list *stack_a, s_list **stack_b)
{
	s_list	*a_temp;
	s_list	*b_temp;

	a_temp = stack_a;
	b_temp = *stack_b;
	while (a_temp->cheapest != 1)
		a_temp = a_temp->next;
	if (a_temp->target->above_median == 1)
	{
		while (a_temp->target->index != 1)
		{
			rotate(&b_temp);
			index_assign(&a_temp, &b_temp);
		}
	}
	if (a_temp->target->above_median == 0)
	{
		while (a_temp->target->index != 1)
		{
			rotate_down(&b_temp);
			index_assign(&a_temp, &b_temp);
		}
	}
	*stack_b = b_temp;
	// printf("%d\n", b_temp->data);
	// printf("%d\n", b_temp->next->data);
}

void	move_a(s_list **stack_a, s_list **stack_b)
{
	s_list	*a_temp;
	s_list	*b_temp;

	a_temp = *stack_a;
	b_temp = *stack_b;
	while (a_temp->cheapest != 1)
		a_temp = a_temp->next;
	if (a_temp->above_median == 1)
	{
		while (a_temp->index != 1)
		{
			rotate(&(*stack_a));
			index_assign(&(*stack_a), &(*stack_b));
		}
	}
	if (a_temp->above_median == 0)
	{
		while (a_temp->index != 1)
		{
			rotate_down(&(*stack_a));
			index_assign(&(*stack_a), &(*stack_b));
		}
	}
	// *stack_a = a_temp;
	// printf("%d\n", b_temp->data);
	// printf("%d\n", b_temp->next->data);
}

int main(int argc, char **argv)
{
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	// getBit(5, 10);
	// printbin(5);
	// bin(7);
	int	tab[] = {15, 3, 1, 7, 4, 19};
	int	tab2[] = {2, 3, 5, 14, 8, 9};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*test = NULL;
	stack_a = assign_list(tab, 6);
	stack_b = assign_list(tab2, 6);
	
	// push_swap(&stack_a, &stack_b);
	assign_all(&stack_a, &stack_b);
	
	move_a(&stack_a, &stack_b);
	// printf("%d\n", stack_a->data);
	// printf("%d\n", stack_a->next->data);
	assign_all(&stack_a, &stack_b);

	while (stack_a != NULL)
	{
		printf("index : %d value : %d target(value) : %d cost : %d cheapest : %d median : %d\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest, stack_a->above_median);
		stack_a = stack_a->next;
	}
	
	// cost_of_push(&stack_a, &stack_b);
	// while (stack_a != NULL)
	// {
	// 	printf("cost : %d\n", stack_a->cost);
	// 	stack_a = stack_a->next;
	// }
	// printf("\n");
	// while (stack_b != NULL)
	// {
	// 	printf("cost : %d\n", stack_b->cost);
	// 	stack_b = stack_b->next;
	// }
	
	// print_list(stack_a);
	// printf("\n");
	// print_list(stack_b);
}
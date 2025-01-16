/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/16 12:11:26 by dahmane          ###   ########.fr       */
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
	// sort_b_to_a(&(*stack_a), &(*stack_b));
	// sort_final(&(*stack_a));
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
	while (stack_length(*stack_a) > 3)
	{
		assign_all(&(*stack_a), &(*stack_b));
		push_cheapest_to_b(&(*stack_a), &(*stack_b));
	}
	return (sort_3(&(*stack_a)));
}

void	sort_b_to_a(s_list **stack_a, s_list **stack_b)
{
	// int i = 0;
	// while (i < 2)
	// {
	// 	// printf("test\n");
	// 	// assign_all2(&(*stack_a), &(*stack_b));
	// 	// printf("bob\n");
	// 	push_cheapest_to_a(&(*stack_a), &(*stack_b));
	// 	i++;
	// }
	// printf("boby");
	// push(&(*stack_b), &(*stack_a));
	push_cheapest_to_a(&(*stack_a), &(*stack_b));
	// push_cheapest_to_a(&(*stack_a), &(*stack_b));
}
void	sort_final(s_list **stack)
{
	s_list	*temp;

	index_assign(&(*stack), &(*stack));
	median_assign(&(*stack), &(*stack));
	temp = max_node(*stack);
	if (temp->index != stack_length(*stack))
	{
		if (temp->above_median == 1)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate(&(*stack));
				index_assign(&(*stack), &(*stack));
				return;
			}
		}
		if (temp->above_median == 0)
		{
			while (temp->index != stack_length(*stack))
			{
				rotate_down(&(*stack));
				index_assign(&(*stack), &(*stack));
			}
		}
	}
}

void	individual_cost2(s_list **stack)
{
	s_list	*temp;
	int		i;

	temp = *stack;
	
	temp = ft_lstlast(*stack);
	while (temp != NULL)
	{
		temp = temp->prev;
	}
	
	// i = 1;
	// // printf("%d\n", temp->above_median);
	// // printf("%d\n", temp->next->above_median);
	// // printf("%d\n", temp->next->next->above_median);
	// // printf("%d\n", temp->next->next->next->above_median);
	// while (temp->above_median != 0)
	// {
	// 	temp->cost = temp->index - 1;
	// 	temp = temp->next;
	// }
	// // printf("%d\n", temp->data);
	// // printf("%d\n", temp->next->data);
	// // temp = ft_lstlast(*stack);
	// temp = temp->next;
	// // temp = temp->next;
	// printf("%d\n", temp->data);
	// printf("%d\n", temp->prev->data);
	// printf("%d\n", temp->prev->prev->data);
	// while (temp->above_median != 1)
	// {
	// 	temp->cost = i;
	// 	i++;
	// 	temp = temp->prev;
	// }
}

int main(int argc, char **argv)
{
	// PARSING //////////////////////////////////////////////////////////////
	// if (argc < 2)
	// 	return (0);
	// printf("%d", valid_param(argv));
	
	// INIT //////////////////////////////////////////////////////////////////
	int	tab[] = {39, 201, 11, 28, 1, 97, 44};
	int	tab2[] = {49, 54, 5, 112, 91, 882};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	s_list	*temp = NULL;
	stack_a = assign_list(tab, 7);
	// stack_b = assign_list(tab2, 6);
	

	push_swap(&stack_a, &stack_b);
	temp = ft_lstlast(stack_a);
	// printf("%d\n", temp->data);
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->prev;
	}
	
	
	
	
	// sort_b_to_a(&stack_a, &stack_b);
	
	// assign_target_a(&stack_a, &stack_b);
	// push_cheapest_to_a(&stack_a, &stack_b);
	// index_assign(&stack_a, &stack_b);
	// median_assign(&stack_a, &stack_b);
	// // assign_target_a(&stack_a, &stack_b);
	// // // cost_of_push(&stack_a, &stack_b);
	// individual_cost2(&stack_a);
	// find_cheapest(&stack_a);


	// TEST OF ALL VARIABLES ////////////////////////////////////////////////////
	// assign_all(&stack_a, &stack_b);
	// assign_all2(&stack_a, &stack_b);
	// while (stack_a != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_a->index, stack_a->data, stack_a->target->data, stack_a->cost, stack_a->cheapest, stack_a->above_median);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b != NULL)
	// {
	// 	printf("|| index : %d || value : %d || target(value) : %d || cost : %d || cheapest : %d || median : %d ||\n", stack_b->index, stack_b->data, stack_b->target->data, stack_b->cost, stack_b->cheapest, stack_b->above_median);
	// 	stack_b = stack_b->next;
	// }
	
	// TEST OF 1 VARIABLE /////////////////////////////////////////////////////////
	// while (stack_a != NULL)
	// {
	// 	printf("index : %d\n", stack_a->index);
	// 	stack_a = stack_a->next;
	// }
	// printf("\n");
	
	// PRINT LISTS ///////////////////////////////////////////////////////////////////
	// print_list(stack_a);
	// printf("\n");
	// print_list(stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/09 17:31:55 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// doubles, not an int, 

int	valid_param(char **strs)
{
	int	i;

	i = 1;
	while(strs[i])
	{
		if (valid_char(strs[i]) == 1)
			return (1);
		if (repeat_char(strs[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

void getBit(int num, int i)
{
	if ((num & (1 << i)) != 0)
		printf("1");
	else 
		printf("0");
}
void printbin(int n)
{
	if (n > 1)
		printbin(n / 2);
	printf("%d", n % 2);
}
void	bin(int n)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (((n >> i) & 1) != 0)
			printf("1");
		else
			printf("0");
		i++;
	}
}

s_list	*create_node(int data)
{
	s_list *newNode;

	newNode = NULL;
	newNode = malloc(sizeof(s_list));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return (newNode);
}

s_list	*assign_list(int *tab, int size)
{
	s_list *list;
	s_list *temp;
	s_list	*prev_temp;
	int 	i;
	
	i = 1;
	list = create_node(tab[0]);
	if (!list)
		return (NULL);
	temp = list;
	while (i < size)
	{
		temp->next = create_node(tab[i]);
		if (!temp->next)
			return (NULL);
		prev_temp = temp;
		temp = temp->next;
		temp->prev = prev_temp;
		i++;
	}
	return (list);
}
void	print_list(s_list *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
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
	int	tab[] = {2, 13, 3, 7};
	int	tab2[] = {8, 29, 4, 12};
	s_list	*stack_a = NULL;
	s_list	*stack_b = NULL;
	
	stack_a = assign_list(tab, 4);
	stack_b = assign_list(tab2, 4);
	
	// swap(&stack_a);
	// swap(&stack_b);
	// swap_both(&stack_a, &stack_b);
	// push(&stack_a, &stack_b);
	// rotate(&stack_b);
	// rotate_both(&stack_a, &stack_b);
	// stack_b = ft_lst_before_last(stack_a);
	// rotate_down(&stack_b);
	rotate_down_both(&stack_a, &stack_b);
	
	// stack_b = stack_b->next;
	// // stack_b = stack_b->prev;
	// // stack_b = stack_b->prev;
	// printf("%d\n", stack_b->data);
	
	print_list(stack_a);
	printf("\n");
	print_list(stack_b);

}
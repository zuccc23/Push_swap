/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:19:03 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/06 16:42:44 by dahmane          ###   ########.fr       */
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

s_list	*assign_list(int *tab)
{
	s_list *list;
	s_list *temp;
	s_list	*prev_temp;
	int 	i;
	
	i = 1;
	list = create_node(tab[0]);
	temp = list;
	while (tab[i])
	{
		temp->next = create_node(tab[i]);
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
	int	tab[] = {2, 3, 5, 4};
	s_list *list;
	
	list = assign_list(tab);
	// list = list->prev;
	// list = list->next;
	list = list->next;
	list = list->next;
	list = list->next;
	list->next = NULL;
	list = list->next;
	printf("%d\n", list->data);
	// print_list(list);
}
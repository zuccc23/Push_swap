/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:57:55 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/12 15:20:57 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


s_list	*ft_lstlast(s_list *lst)
{
	s_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

s_list	*ft_lst_before_last(s_list *lst)
{
	s_list	*tmp;
	s_list	*tmptmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
	{
		tmptmp = tmp;
		tmp = tmp->next;
	}
	return (tmptmp);
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
	newNode->target = NULL;
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

int	stack_length(s_list *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

s_list	*max_node(s_list *stack)
{
	s_list	*max;
	s_list	*temp;

	if (!stack || !stack->next)
		return (NULL);
	max = stack;
	temp = max->next;
	while (temp != NULL)
	{
		if (max->data < temp->data)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

s_list	*min_node(s_list *stack)
{
	s_list	*min;
	s_list	*temp;

	if (!stack || !stack->next)
		return (NULL);
	min = stack;
	temp = min->next;
	while (temp != NULL)
	{
		if (min->data > temp->data)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

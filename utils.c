/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dahmane <dahmane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:57:55 by dahmane           #+#    #+#             */
/*   Updated: 2025/01/22 19:19:18 by dahmane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*ft_lst_before_last(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*tmptmp;

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

t_stack	*create_node(int data)
{
	t_stack *newNode;

	newNode = NULL;
	newNode = malloc(sizeof(t_stack));
	if (!newNode)
		return (NULL);
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->target = NULL;
	return (newNode);
}

t_stack	*assign_list(int *tab, int size)
{
	t_stack *list;
	t_stack *temp;
	t_stack	*prev_temp;
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
void	print_list(t_stack *list)
{
	while (list != NULL)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
}

int	stack_length(t_stack *stack)
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



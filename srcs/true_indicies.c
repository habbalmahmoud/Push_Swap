/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_indicies.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:11:29 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 00:06:11 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*merge(t_list *left, t_list *right)
{
	t_list	*result;

	if (!left)
		return (right);
	if (!right)
		return (left);
	if (left->content <= right->content)
	{
		result = left;
		result->next = merge(left->next, right);
	}
	else
	{
		result = right;
		result->next = merge(left, right->next);
	}
	return (result);
}

void	list_split(t_list *head, t_list **left, t_list **right)
{
	t_list	*slow;
	t_list	*fast;

	if (!head || !head->next)
	{
		(*left) = head;
		(*right) = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while (fast)
		{
			fast = fast->next;
			if (fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		(*left) = head;
		(*right) = slow->next;
		slow->next = NULL;
	}
}

void	assign_equivalent_index(t_list **a, t_list **copy_a)
{
	t_list	*temp_a;
	t_list	*temp_cpy;

	temp_a = *a;
	while (temp_a)
	{
		temp_cpy = *copy_a;
		while (temp_cpy)
		{
			if (temp_a->content == temp_cpy->content)
			{
				temp_a->index = temp_cpy->index;
				break ;
			}
			temp_cpy = temp_cpy->next;
		}
		temp_a = temp_a->next;
	}
}

void	merge_sort(t_list **a)
{
	t_list	*temp;
	t_list	*left;
	t_list	*right;

	if (!(*a) || !(*a)->next)
		return ;
	temp = *a;
	list_split(temp, &left, &right);
	merge_sort(&left);
	merge_sort(&right);
	(*a) = merge(left, right);
}

void	assign_true_indicies(t_list **a)
{
	t_list	**copy_a;
	t_list	*temp;

	temp = ft_lstcpy(a);
	copy_a = &temp;
	merge_sort(copy_a);
	give_new_index(copy_a);
	assign_equivalent_index(a, copy_a);
	ft_lstclear(copy_a, del);
}

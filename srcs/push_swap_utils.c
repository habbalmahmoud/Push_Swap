/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:54:23 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/06 14:33:17 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*find_smallest_node(t_list **a)
{
	t_list	*small;
	t_list	*temp;

	small = *a;
	temp = (*a)->next;
	while (temp)
	{
		if (small->content > temp->content)
			small = temp;
		temp = temp->next;
	}
	return (small);
}

int	is_sorted(t_list **a)
{
	t_list	*temp;

	temp = *a;
	while (temp && temp->next)
	{
		if (temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	give_new_index(t_list **a)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *a;
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
}

t_list	*ft_lstcpy(t_list **a)
{
	t_list	*temp;
	t_list	*cpy;

	temp = (*a);
	cpy = NULL;
	while (temp)
	{
		ft_lstadd_back(&cpy, ft_lstnew(temp->content));
		temp = temp->next;
	}
	return (cpy);
}

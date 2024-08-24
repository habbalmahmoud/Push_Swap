/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:07:08 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/03 13:09:56 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate_a(t_list **a)
{
	t_list	*temp;
	t_list	*node;

	node = *a;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = NULL;
	temp->next = *a;
	(*a) = temp;
	ft_printf("rra\n");
}

void	rev_rotate_b(t_list **b)
{
	t_list	*temp;
	t_list	*node;

	node = *b;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = NULL;
	temp->next = *b;
	(*b) = temp;
	ft_printf("rrb\n");
}

void	rev_r_rotate(t_list **a, t_list **b)
{
	rev_rotate_a(a);
	rev_rotate_b(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:16:41 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/05 09:59:29 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*a || !(*a)->next)
		return ;
	temp1 = *a;
	temp2 = (*a)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	(*a) = temp2;
	ft_printf("sa\n");
}

void	swap_b(t_list **b)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*b || !(*b)->next)
		return ;
	temp1 = *b;
	temp2 = (*b)->next;
	temp1->next = temp2->next;
	temp2->next = temp1;
	*b = temp2;
	ft_printf("sb\n");
}

void	swap_s(t_list **a, t_list **b)
{
	swap_a(a);
	swap_b(b);
}

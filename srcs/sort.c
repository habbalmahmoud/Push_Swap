/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 02:10:53 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 09:26:07 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_stack(t_list **a)
{
	if ((*a)->next->content > (*a)->content
		&& (*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content > (*a)->content)
	{
		rev_rotate_a(a);
		swap_a(a);
	}
	else if ((*a)->next->content > (*a)->content
		&& (*a)->next->content > (*a)->next->next->content
		&& (*a)->content > (*a)->next->next->content)
		rev_rotate_a(a);
	else if ((*a)->next->content < (*a)->content
		&& (*a)->next->content < (*a)->next->next->content
		&& (*a)->content > (*a)->next->next->content)
		rotate_a(a);
	else if ((*a)->next->content < (*a)->content
		&& (*a)->next->content > (*a)->next->next->content
		&& (*a)->next->next->content < (*a)->content)
	{
		swap_a(a);
		rev_rotate_a(a);
	}
	else if ((*a)->next->content < (*a)->content
		&& (*a)->next->next->content > (*a)->content)
		swap_a(a);
}

void	sort_four_stack(t_list **a, t_list **b)
{
	t_list	*small;

	small = find_smallest_node(a);
	if (small->index == 0 || small->index == 1 || small->index == 2
		|| small->index == 3)
	{
		if (small->index == 3)
			rev_rotate_a(a);
		if (small->index == 2)
		{
			rotate_a(a);
			swap_a(a);
		}
		if (small->index == 1)
			swap_a(a);
		push_b(b, a);
		sort_three_stack(a);
		push_a(a, b);
	}
}

void	sort_five_stack(t_list **a, t_list **b)
{
	t_list	*small;

	small = find_smallest_node(a);
	if (small->index == 0 || small->index == 1 || small->index == 2
		|| small->index == 3 || small->index == 4)
	{
		if (small->index == 4)
			rev_rotate_a(a);
		if (small->index == 3)
		{
			rev_rotate_a(a);
			rev_rotate_a(a);
		}
		if (small->index == 2)
		{
			rotate_a(a);
			swap_a(a);
		}
		if (small->index == 1)
			swap_a(a);
		push_b(b, a);
		give_new_index(a);
		sort_four_stack(a, b);
		push_a(a, b);
	}
}

void	sort_big_stack(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	assign_true_indicies(a);
	radix(a, b, &i);
}

void	handle_sort(t_list **a, t_list**b)
{
	if (ft_lstsize(*a) == 2)
		swap_a(a);
	else if (ft_lstsize(*a) == 3)
		sort_three_stack(a);
	else if (ft_lstsize(*a) == 4)
		sort_four_stack(a, b);
	else if (ft_lstsize(*a) == 5)
		sort_five_stack(a, b);
	else if (ft_lstsize(*a) > 5)
		sort_big_stack(a, b);
}

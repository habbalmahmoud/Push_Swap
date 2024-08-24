/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhabbal <mhabbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 09:12:47 by mhabbal           #+#    #+#             */
/*   Updated: 2024/07/08 09:40:50 by mhabbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"

t_list	*parse(char **argv);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_s(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **b, t_list **a);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	r_rotate(t_list **a, t_list **b);
void	rev_rotate_a(t_list **a);
void	rev_rotate_b(t_list **b);
void	rev_r_rotate(t_list **a, t_list **b);
void	del(int content);
int		is_sorted(t_list **a);
void	sort_three_stack(t_list **a);
void	handle_sort(t_list **a, t_list **b);
void	sort_four_stack(t_list **a, t_list **b);
t_list	*find_smallest_node(t_list **a);
void	give_new_index(t_list **a);
void	sort_big_stack(t_list **a, t_list **b);
void	assign_true_indicies(t_list **a);
t_list	*ft_lstcpy(t_list **a);
void	assign_equivalent_index(t_list **a, t_list **copy_a);
void	radix(t_list **a, t_list **b, int *i);

#endif
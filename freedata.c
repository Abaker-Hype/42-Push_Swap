/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:18:01 by abaker            #+#    #+#             */
/*   Updated: 2021/09/30 17:49:30 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freestack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*next;

	if (!stack)
		return ;
	curr = stack;
	while (true)
	{
		next = curr->next;
		free(curr);
		if (next == stack)
			break ;
		curr = next;
	}
}

void	freedata(t_data *data)
{
	freestack(data->stacka);
	freestack(data->stackb);
	freestack(data->moves);
}

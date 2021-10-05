/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:48:48 by abaker            #+#    #+#             */
/*   Updated: 2021/09/30 14:48:50 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	chksort(t_data *data)
{
	t_stack	*curr;

	if (data->sizeb != 0)
		return (false);
	curr = data->stacka;
	while (curr->next != data->stacka)
	{
		if (curr->num > curr->next->num)
			return (false);
		curr = curr->next;
	}
	return (true);
}

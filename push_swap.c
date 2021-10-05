/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 14:52:37 by abaker            #+#    #+#             */
/*   Updated: 2021/10/05 15:31:08 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initdata(t_data *data)
{
	data->stacka = NULL;
	data->stackb = NULL;
	data->sizea = 0;
	data->sizeb = 0;
	data->moves = NULL;
	data->movenum = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	initdata(&data);
	if (!loadargs(&data, argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!chksort(&data))
	{
		if (data.sizea < 7)
			recursionsort(&data, 1, -1, (data.sizea * data.sizea) / 3);
		else
			groupsort(&data);
	}
	printmoves(data.moves);
	freedata(&data);
	return (0);
}

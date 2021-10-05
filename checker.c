/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 09:49:15 by abaker            #+#    #+#             */
/*   Updated: 2021/10/05 14:55:35 by abaker           ###   ########.fr       */
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

static void	chkmoves(int argc, char **argv, t_stack *moves)
{
	t_data	data;
	t_stack	*curr;

	initdata(&data);
	loadargs(&data, argc, argv);
	if (moves != NULL)
	{
		curr = moves;
		while (true)
		{
			operation(&data, curr->num, true);
			if (curr->next == moves)
				break ;
			curr = curr->next;
		}
	}
	if (chksort(&data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	freedata(&data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
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
	chkmoves(argc, argv, data.moves);
	freedata(&data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 15:21:20 by abaker            #+#    #+#             */
/*   Updated: 2021/10/05 15:45:28 by abaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*getmove(int move)
{
	char	*moves[11];

	moves[0] = "sa\n";
	moves[1] = "sb\n";
	moves[2] = "ss\n";
	moves[3] = "pa\n";
	moves[4] = "pb\n";
	moves[5] = "ra\n";
	moves[6] = "rb\n";
	moves[7] = "rr\n";
	moves[8] = "rra\n";
	moves[9] = "rrb\n";
	moves[10] = "rrr\n";
	return (moves[move]);
}

void	printmoves(t_stack *moves)
{
	t_stack	*curr;
	char	*str;

	if (!moves)
		return ;
	curr = moves;
	while (true)
	{
		str = getmove(curr->num);
		write(1, str, ft_strlen(str));
		if (curr->next == moves)
			break ;
		curr = curr->next;
	}
}
/* Special function for showing both stacks (NOT USED)
void	printstacks(t_data *data)
{
	t_stack	*curra;
	t_stack	*currb;
	int		i;

	curra = data->stacka;
	currb = data->stackb;
	i = 0;
	printf("Stacks\nA B\n---\n");
	while (true)
	{
		if (i < data->sizea)
			printf("%i ", curra->num);
		else
			printf("  ");
		if (i < data->sizeb)
			printf("%i\n", currb->num);
		else
			printf(" \n");
		i++;
		if (i >= data->sizea && i >= data->sizeb)
			break ;
		if (curra)
			curra = curra->next;
		if (currb)
			currb = currb->next;
	}
	printf("---\n%i-%i\n", data->sizea, data->sizeb);
}*/

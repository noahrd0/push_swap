/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:08:11 by nradal            #+#    #+#             */
/*   Updated: 2022/09/01 12:19:30 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_to_a(int *arrayB, int to_b)
{
	if (to_b == 2)
	{
		if (arrayB[0] > arrayB[1])
			ft_putstr_fd("rb\npa\npa\n", 1);
		else
			ft_putstr_fd("pa\npa\n", 1);
	}
	else
		ft_putstr_fd("pa\n", 1);
}

void	sort_less3(int *arrayA)
{
	if (arrayA[0] == 0 && arrayA[1] == 2)
		ft_putstr_fd("sa\nra\n", 1);
	if (arrayA[0] == 1 && arrayA[1] == 0)
		ft_putstr_fd("sa\n", 1);
	if (arrayA[0] == 1 && arrayA[1] == 2)
		ft_putstr_fd("rra\n", 1);
	if (arrayA[0] == 2 && arrayA[1] == 0)
		ft_putstr_fd("ra\n", 1);
	if (arrayA[0] == 2 && arrayA[1] == 1)
		ft_putstr_fd("sa\nrra\n", 1);
}

void	organize_array_a(int *arrayA, int *array_cpy, int array_size, int to_b)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < array_size)
	{
		if (arrayA[i] == 0 || (to_b == 2 && arrayA[i] == 1))
			j++;
		else
		{
			temp = arrayA[i];
			arrayA[i - j] = temp;
			array_cpy[i - j] = temp;
		}
		i++;
	}
}

void	sort_less5(int *arrayA, int *arrayB, int array_size)
{
	int	to_b;
	int	*array_cpy;
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	array_cpy = malloc(array_size * sizeof(array_cpy));
	if (!array_cpy)
		exit(1);
	to_b = array_size - 3;
	while (i < array_size)
	{
		if (arrayA[i] == 0 || (to_b == 2 && arrayA[i] == 1))
		{
			arrayB[pos++] = arrayA[i];
			ft_putstr_fd("pb\n", 1);
		}
		else
			ft_putstr_fd("ra\n", 1);
		i++;
	}
	organize_array_a(arrayA, array_cpy, array_size, to_b);
	bubble_sort(array_cpy, 3);
	simplify_array(arrayA, array_cpy, 3);
	free (array_cpy);
	sort_less3(arrayA);
	push_to_a(arrayB, to_b);
}

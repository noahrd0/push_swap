/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:59:24 by nradal            #+#    #+#             */
/*   Updated: 2022/09/01 14:51:13 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pars_error(int *array, int *array_cpy)
{
	free(array);
	free(array_cpy);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	pars_atoi(char *str, int *array, int *array_cpy)
{
	int			i;
	long long	nbr;
	int			negative;

	i = 0;
	nbr = 0;
	negative = 1;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			nbr = nbr * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	nbr *= negative;
	if (nbr <= -2147483648 && nbr >= 2147483647)
		pars_error(array, array_cpy);
	return (nbr);
}

int	pars_correct_arg(char *str, int *array, int *array_cpy)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] == ' ') || (str[i] == '-'))
		{
			if (str[i] == '-' && !ft_isdigit(str[i + 1]))
				pars_error(array, array_cpy);
			i++;
		}
		else
			pars_error(array, array_cpy);
	}
	return (0);
}

void	pars_no_duplicates(int *array, int *array_cpy, int array_size)
{
	int	i;

	i = 0;
	bubble_sort (array_cpy, array_size);
	while (i < array_size - 1)
	{
		if (array_cpy[i] == array_cpy[i + 1])
			pars_error(array, array_cpy);
		i++;
	}
}

void	pars_sorted(int *array, int *array_cpy, int array_size)
{
	int	i;

	i = 0;
	while (array[i] < array[i + 1])
	{
		if (i == array_size - 2)
		{
			free(array);
			free(array_cpy);
			exit(1);
		}
		i++;
	}
}

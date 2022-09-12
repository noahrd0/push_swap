/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:07:22 by nradal            #+#    #+#             */
/*   Updated: 2022/09/01 13:36:35 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void pb(int *arrayA, int *arrayB, int j)
{
    int i;

    i = 0;
    j -= 2;
    while (j >= 0)
    {
        write(1, "pa\n", 3);
        arrayA[j] = arrayB[i];
        i++;
        j--;
    }
}

void divide(int *arrayA, int array_size)
{
    int i;

    i = 0;
    while (i < array_size)
    {
        arrayA[i] /= 10;
        i++;
    }
}

int tab_cleaner(int *arrayA, int *arrayB, int array_size)
{
    int i;
    int j;
    int temp;

    i = array_size - 1;
    j = 0;
    temp = 0;
    while (array_size-- >= 0)
    {
        if (arrayA[i] % 2 == 0)
            arrayB[j++] = arrayA[i];
        else
        {
            temp = arrayA[i];
            arrayA[i + j] = temp;
        }
        i--;
    }
    return (j);
}

void sort(int *arrayA, int *arrayB, int array_size)
{
    int i;
    int arrayB_size;

    i = 0;
    while (i < array_size)
    {
        if (arrayA[i] % 2 == 0)
            write(1, "pb\n", 3);
        else
            write(1, "ra\n", 3);
        i++;
    }
    arrayB_size = tab_cleaner(arrayA, arrayB, array_size);
    pb(arrayA, arrayB, arrayB_size);
    divide(arrayA, array_size);
}

int array_is_sorted(int *arrayA, int array_size)
{
    int i;

    i = 0;
    while (i < array_size)
    {
        if (arrayA[i] >= 1)
            return (1);
        i++;
    }
    return (0);
}
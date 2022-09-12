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

void rb(int *arrayB)
{
    int temp;

    temp = 0;
    ft_putstr_fd("rb\n", 1);
    temp = arrayB[0];
    arrayB[0] = arrayB[1];
    arrayB[1] = temp;
}

void pa_less5(int *arrayB, int toB)
{
    int i;

    i = 0;
    if (toB == 2 && (arrayB[0] > arrayB[1]))
        rb(arrayB);
    while (i < toB)
    {
        if (arrayB[i] == 0)
            ft_putstr_fd("pa\n", 1);
        if (arrayB[i] == 1)
            ft_putstr_fd("pa\nsa\n", 1);
        if (arrayB[i] == 2)
            ft_putstr_fd("pa\nsa\npb\nsa\npa\n", 1);
        if (arrayB[i] == 3 && i == 0)
            ft_putstr_fd("pa\nra\n", 1);
        if (arrayB[i] == 3 && i == 1)
            ft_putstr_fd("rra\npa\nra\nra\n", 1);
        if (arrayB[i] == 4)
            ft_putstr_fd("pa\nra\n", 1);
        i++;
    } 
}

void sort_less3(int *arrayA)
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

void sort_less5(int *arrayA, int *arrayB, int array_size)
{
    int i;
    int toB;
    int array_cpy[array_size];

    toB = array_size - 3;
    i = toB;
    ft_putstr_fd("pb\n", 1);
    if (toB == 1)
        arrayB[0] = arrayA[0];
    if (toB == 2)
    {
        ft_putstr_fd("pb\n", 1);
        arrayB[0] = arrayA[1];
        arrayB[1] = arrayA[0];
    }
    while (i < array_size)
    {
        array_cpy[i - toB] = arrayA[i];
        arrayA[i - toB] = arrayA[i];
        i++;
    }
    bubble_sort(array_cpy, 3);
    simplify_array(arrayA, array_cpy, 3);
    sort_less3(arrayA);
    pa_less5(arrayB, toB);
}
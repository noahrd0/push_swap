/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:12:52 by nradal            #+#    #+#             */
/*   Updated: 2022/09/02 15:27:22 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void bubble_sort(int *array, int array_size)
{
    int temp;
    int i;
    int j;

    temp = 0;
    i = 0;
    j = 0;
    
    while (i < array_size - 1)
    {
        j = i + 1;
        while (j < array_size)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            j++;
        }
        i++;
    }
}

void initalize_array(int *array, int *array_cpy, int array_size, char **av)
{
    char **strs;
    int i;
    
    i = 0;
    pars_correct_arg(av[1], array, array_cpy);
    strs = ft_split(av[1], ' ');
    while (i != array_size)
    {
        array[i] = pars_atoi(strs[i], array, array_cpy);
        free(strs[i]);
        array_cpy[i] = array[i];
        i++;
    }
    free(strs);
    pars_no_duplicates(array, array_cpy, array_size);
    pars_sorted(array, array_cpy, array_size);
}


void simplify_array(int *array, int *array_cpy, int array_size)
{
    int i;
    int j;
    int array_simp[array_size];

    i = 0;
    j = 0;
    while (i < array_size)
    {
        if (array_cpy[i] == array[j])
        {
            array_simp[j] = i;
            i++;
            j = -1;
        }
        j++;
    }
    i = 0;
    while (i < array_size)
    {
        array[i] = array_simp[i];
        i++;
    } 
}

int decimal_to_binary(int n) 
{
  long long bin;
  int rem; 
  int i = 1;

  bin = 0;
  i = 1;
  while (n!=0) {
    rem = n % 2;
    n /= 2;
    bin += rem * i;
    i *= 10;
  }
  return (bin);
}

void binary_array(int *array, int array_size)
{
    int i;
    
    i = 0;
    while (i < array_size)
    {
        array[i] = decimal_to_binary(array[i]);
        i++;
    }
}
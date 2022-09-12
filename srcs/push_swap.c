/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:34:54 by nradal            #+#    #+#             */
/*   Updated: 2022/09/02 14:26:59 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void small_array(int *array, int *array_cpy, int array_size)
{
    if (array_size <= 3)
        sort_less3(array);
    else if (array_size <= 5)
        sort_less5(array, array_cpy, array_size);
}

int main(int ac, char **av)
{
    int     array_size;
    int     *array;
    int     *array_cpy;

    if (ac <= 1)
        exit(1);
    array_size = ft_nbr_str(av[1], ' ');
    array = malloc(array_size * sizeof(array));
    array_cpy = malloc(array_size * sizeof(array_cpy));
    if (!array || !array_cpy)
        return (0);
    initalize_array(array, array_cpy, array_size, av);
    simplify_array(array, array_cpy, array_size);
    small_array(array, array_cpy, array_size);
    if (array_size > 5)
    {
        binary_array(array, array_size);
        while (1)
        {
            if (!array_is_sorted(array, array_size))
                break;
            sort(array, array_cpy, array_size);
        }
    }
    free (array);
    free (array_cpy);

    
    //}
    // AFFICHAGE 
    
    /*int i = 0;
    printf("        arrayA\n");
    while (i != array_size)
    {
        printf("%d\n", array[i]);
        i++;
    }
    i = 0;
    printf("\n      arrayB\n");
    while (i != array_size)
    {
        printf("%d\n", array_cpy[i]);
        i++;
    }*/
}

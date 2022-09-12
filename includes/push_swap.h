/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nradal <nradal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:44:22 by nradal            #+#    #+#             */
/*   Updated: 2022/09/01 12:18:29 by nradal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* libraries */
# include "../libft/includes/libft.h"

/* parsing */
void pars_error(int *array, int *array_cpy);
void pars_no_duplicates(int *array, int *array_cpy, int array_size);
void pars_sorted(int *array, int *array_cpy, int array_size);
int pars_atoi(char *str, int *array, int *array_cpy);
int pars_correct_arg(char *str, int *array, int *array_cpy);

/* array management */
void initalize_array(int *array, int *array_cpy, int array_size, char **av);
void bubble_sort(int *array, int array_size);
void simplify_array(int *array, int *array_cpy, int array_size);
void binary_array(int *array, int array_size);
int decimal_to_binary(int n);

/* sorting */
void pa_less5(int *arrayB, int toB);
void sort_less3(int *arrayA);
void sort_less5(int *arrayA, int *arrayB, int array_size);
void sort(int *arrayA, int *arrayB, int array_size);
int array_is_sorted(int *arrayA, int array_size);

/* operations */
void pb(int *arrayA, int *arrayB, int j);
void divide(int *arrayA, int array_size);

#endif
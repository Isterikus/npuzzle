/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 10:02:05 by dkovalen          #+#    #+#             */
/*   Updated: 2017/04/19 16:32:51 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include <sys/time.h>
#include <stdio.h>
#include "libft/printf_functions/includes/header.h"

typedef struct		s_state
{
	int				*field;
	int				h;
	int				g;
	struct s_state	*parent;				
}					t_state;

void	set_range();
int		abs(int x);
int		getH(int *field);
int		getManhattan(int *field);
int		getLinearConflict(int *field);
int		getPatternDatabaseMine(int *field);
int		getPatternDatabase(int *field);
int		compare_array(int *field1, int *field2);
int		ansver(int *field);
void	print_way(t_state *node);
int		elemInArray(int elem, int arr_num);
int		*copyField(int *field);
int		*swap(int *field, int num1, int num2);
t_state	*find_neighbor(int num, int *field);
int		search(t_state *node, int g, int bound);
void	solve(int *initial_field);

#endif

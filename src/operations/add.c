/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:14:10 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/31 13:01:56 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_add(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	(void)vm;
	prc->reg[cmp->arg[2]] = prc->reg[cmp->arg[0]] + prc->reg[cmp->arg[1]];
	prc->carry = prc->reg[cmp->arg[2]] == 0;
}

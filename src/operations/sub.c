/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:41:46 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/28 01:22:58 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"
void op_sub(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	(void)vm;
	prc->reg[cmp->arg[2]] = prc->reg[cmp->arg[0]] - prc->reg[cmp->arg[1]];
	prc->carry = prc->reg[cmp->arg[2]] == 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:11:32 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/28 01:23:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void op_zjmp(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	(void)vm;
	if (prc->carry)
		prc->cur_addr = (prc->cur_addr) + idx_mod(cmp->arg[0]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:28:06 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/31 13:18:26 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_ldi(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	const int arg1_is_register = get_arg_code(cmp->arg_code, 0) == T_REG;
	const int arg2_is_register = get_arg_code(cmp->arg_code, 1) == T_REG;

	cmp->arg[0] = arg1_is_register ? prc->reg[cmp->arg[0]] : cmp->arg[0];
	cmp->arg[1] = arg2_is_register ? prc->reg[cmp->arg[1]] : cmp->arg[1];
	prc->reg[cmp->arg[2]] = get_mem(vm->colosseum,
			idx_mod(cmp->arg[0] + cmp->arg[1]) + prc->cur_addr, 4);
}

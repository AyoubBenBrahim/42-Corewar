/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:28:14 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/31 13:21:26 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_sti(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	const int arg2_is_register = get_arg_code(cmp->arg_code, 1) == T_REG;
	const int arg3_is_register = get_arg_code(cmp->arg_code, 2) == T_REG;
	const int val = prc->reg[cmp->arg[0]];

	cmp->arg[1] = arg2_is_register ? prc->reg[cmp->arg[1]] : cmp->arg[1];
	cmp->arg[2] = arg3_is_register ? prc->reg[cmp->arg[2]] : cmp->arg[2];
	set_mem(vm->colosseum, prc->cur_addr + idx_mod(cmp->arg[1] + cmp->arg[2]),
				val, 4);
}

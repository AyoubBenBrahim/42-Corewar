/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:48:32 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/31 13:20:33 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_st(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	const int value = prc->reg[cmp->arg[0]];

	if (get_arg_code(cmp->arg_code, 1) == T_IND)
		set_mem(vm->colosseum, prc->cur_addr + idx_mod(cmp->arg[1]), value, 4);
	else
		prc->reg[cmp->arg[1]] = value;
}

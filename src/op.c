/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2021/03/28 01:18:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	init_op_tab(t_op *op)
{
	op[1] = (t_op){1, "live", 1, {T_DIR}, 10, 0, 4, 0, op_live};
	op[2] = (t_op){2, "ld", 2, {T_DIR | T_IND, T_REG}, 5, 1, 4, 1, op_ld};
	op[3] = (t_op){3, "st", 2, {T_REG, T_IND | T_REG}, 5, 1, 4, 1, op_st};
	op[4] = (t_op){4, "add", 3, {T_REG, T_REG, T_REG}, 10, 1, 4, 1, op_add};
	op[5] = (t_op){5, "sub", 3, {T_REG, T_REG, T_REG}, 10, 1, 4, 1, op_sub};
	op[6] = (t_op){6, "and", 3, {T_REG | T_DIR | T_IND,
							T_REG | T_IND | T_DIR, T_REG}, 6, 1, 4, 1, op_and};
	op[7] = (t_op){7, "or", 3, {T_REG | T_IND | T_DIR,
							T_REG | T_IND | T_DIR, T_REG}, 6, 1, 4, 1, op_or};
	op[8] = (t_op){8, "xor", 3, {T_REG | T_IND | T_DIR,
							T_REG | T_IND | T_DIR, T_REG}, 6, 1, 4, 1, op_xor};
	op[9] = (t_op){9, "zjmp", 1, {T_DIR}, 20, 0, 2, 1, op_zjmp};
	op[10] = (t_op){10, "ldi", 3, {T_REG | T_DIR | T_IND,
									T_DIR | T_REG, T_REG}, 25, 1, 2, 1, op_ldi};
	op[11] = (t_op){11, "sti", 3, {T_REG, T_REG | T_DIR | T_IND,
										T_DIR | T_REG}, 25, 1, 2, 1, op_sti};
	op[12] = (t_op){12, "fork", 1, {T_DIR}, 800, 0, 2, 1, op_fork};
	op[13] = (t_op){13, "lld", 2, {T_DIR | T_IND, T_REG}, 10, 1, 4, 0, op_lld};
	op[14] = (t_op){14, "lldi", 3, {T_REG | T_DIR | T_IND,
								T_DIR | T_REG, T_REG}, 50, 1, 2, 1, op_lldi};
	op[15] = (t_op){15, "lfork", 1, {T_DIR}, 1000, 0, 2, 0, op_fork};
	op[16] = (t_op){16, "aff", 1, {T_REG}, 2, 1, 4, 0, op_aff};
}

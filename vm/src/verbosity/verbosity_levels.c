/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity_levels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:25:26 by ayb*****          #+#    #+#             */
/*   Updated: 2021/04/01 09:50:14 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	print_operation(t_cursor *prc, t_op_component *cmp)
{
	const t_op op = g_op_tab[cmp->code];

	ft_printf("P %4d | %s", prc->id, op.name);
	print_args(prc, cmp);
	if (cmp->code == OP_ZJMP)
		ft_printf(" %s", prc->carry ? "OK" : "FAILED");
	else if (cmp->code == OP_FORK)
		ft_printf(" (%d)", prc->cur_addr + idx_mod(cmp->arg[0]));
	else if (cmp->code == OP_LFORK)
		ft_printf(" (%d)", prc->cur_addr + cmp->arg[0]);
	ft_printf("\n");
	print_addr_details(prc, cmp);
}

void	print_pc(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	int i;

	i = 0;
	if (cmp->code == OP_ZJMP && prc->carry)
		return ;
	ft_printf("ADV %d (%s%#.4x -> %#.4x) ",
									cmp->step, prc->cur_addr ? "" : "0x",
									prc->cur_addr, prc->cur_addr + cmp->step);
	while (i < cmp->step)
	{
		ft_printf("%.2x ", (unsigned char)get_mem(vm->colosseum,
														prc->cur_addr + i, 1));
		i++;
	}
	ft_printf("\n");
}

void	print_lives(t_gladiator *gldtor)
{
	ft_printf("Player %d (%s) is said to be alive\n",
										gldtor->id, gldtor->prog_name);
}

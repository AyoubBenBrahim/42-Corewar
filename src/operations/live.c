/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:45:03 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/28 01:28:37 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	op_live(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	t_gladiator *gladiator;

	(void)cmp;
	vm->lives_counter++;
	prc->is_alive = TRUE;
	prc->last_live = vm->total_cycles;
	if (between(prc->cmp.arg[0], -4, -1))
	{
		gladiator = get_gldtor_by_id(vm->gladiators, prc->cmp.arg[0] * (-1));
		if (gladiator)
		{
			gladiator->last_live = vm->cycles + 1;
			gladiator->lives++;
			vm->the_conqueror = gladiator;
			vm->total_lives++;
			if (vm->verbo_flag && vm->verbo & SHOW_LIVE)
				print_lives(gladiator);
		}
	}
}

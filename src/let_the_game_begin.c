/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_game_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:23:32 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/15 11:24:00 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	exec_operation()
{

}

void loop_through_cursors(t_vm *vm)
{
	t_cursor	*cursor;
	int			opcode;

	cursor = vm->cursors;
	while (cursor)
	{
		opcode = vm->colosseum[cursor->op_code];
		if (opcode && opcode <= REG_NUMBER)
		{
			if (cursor->wait_cycles != -1)
				cursor->wait_cycles = op_tab[opcode].cycles_to_wait;
			if (!cursor->wait_cycles)
				exec_operation();
			else
				cursor->wait_cycles--;
		}
		else
			cursor->wait_cycles++;


		cursor = cursor->next;
	}
}

void	performe_check(t_vm *vm)
{
	if (vm.cycle == vm.cycle_last_check + vm.cycle_die OR cycles_to_die <= 0) //all carriages are considered dead :
	{
		vm.cycle_last_check = vm.cycle // always store the last value of process cycle when the last check performed
		vm.count_max_chek++
		check_who_is_alive() // if process->live == 0: kill else  process->live = 0
		if vm.nbr_live_one_die >= 21 or vm.count_max_chek = 10
		{
			vm.count_max_chek = 0
			vm.nbr_live_one_die = 0
			vm.cycle_to_die -= 50 //CYCLE_DELTA
		}
	}
}

void let_the_game_begin(t_vm *vm)
{
	while (++vm->cycles)
	{
		loop_through_cursors(vm);

		if (vm->cycles == 100)
		{
			printf("100 cycles \n");
			exit(0);
		}
		performe_check(vm);

	}
}

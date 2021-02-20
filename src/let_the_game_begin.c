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
	}
}

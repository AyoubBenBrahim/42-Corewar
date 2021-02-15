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

void	loop_through_cursors()
{

}

void	let_the_game_begin(t_vm *vm)
{
	t_cursor *cursors;
	int		op;

	while (++vm->cycles)
	{

		cursors = vm->cursors;
		while (cursors)
		{

			op = vm->colosseum[cursors->op_code];

			// if (proc->opcode && proc->opcode <= REG_NUMBER)
			// if instruct > 0 and instruct < 17


			cursors = cursors->next;
		}

		if (vm->cycles == 10)
		{
			printf("100 cycles \n");
			exit(0);
		}
	}
}

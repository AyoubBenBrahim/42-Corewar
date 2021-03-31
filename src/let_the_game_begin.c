/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_game_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:23:32 by aybouras          #+#    #+#             */
/*   Updated: 2021/03/29 19:56:26 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	exec_operation(t_vm *vm, t_cursor *prc)
{
	if(vm->total_cycles == 24985 && prc->id == 307)
	{
		printf("hhhhhh chditk\n");
	}

	if (!parse_operation(vm, prc))
		prc->cmp.step = get_op_size(prc);
	else if(prc->cmp.code != OP_AFF)
	{
		op_tab[prc->cmp.code].op(prc, &prc->cmp, vm);
		if (vm->verbo_flag && vm->verbo & SHOW_OPERATION)
			print_operation(prc, &prc->cmp);
	}
	if (vm->verbo_flag && vm->verbo & SHOW_PC)
		print_pc(prc, &prc->cmp, vm);
	prc->cur_addr = addr_overlap(prc->cur_addr + prc->cmp.step);
}

void	check_who_is_alive(t_vm *vm)
{
	t_cursor *this;
	t_cursor *prev;

	this = vm->cursors;
	prev = NULL;
	while (this)
	{
		if (!this->is_alive)
			this = kill_cursor(vm, this, prev);
		else
		{
			this->is_alive = FALSE;
			prev = this;
			this = this->next;
		}
	}
}

void	loop_through_cursors(t_vm *vm)
{
	t_cursor	*cursor;

	cursor = vm->cursors;
	while (cursor)
	{
		cursor->cur_addr = addr_overlap(cursor->cur_addr);
		if (cursor->wait_cycles == 0)
			set_op_code(cursor, vm);
		if (cursor->wait_cycles > 0)
			cursor->wait_cycles--;
		if (cursor->wait_cycles == 0)
		{
			if (between(cursor->cmp.code, 1, 16))
				exec_operation(vm, cursor);
			else
				cursor->cur_addr = addr_overlap(cursor->cur_addr + 1);
		}
		cursor = cursor->next;
	}
	vm->cycles++;
	vm->total_cycles++;
}

void	performe_check(t_vm *vm)
{
	if (vm->cycles == vm->cycles_to_die)
	{

		vm->count_live_checks++;
		check_who_is_alive(vm);

		if (vm->lives_counter >= NBR_LIVE
							|| vm->count_live_checks == MAX_CHECKS)
		{
			vm->count_live_checks = 0;
			vm->cycles_to_die -= CYCLE_DELTA;
			if (vm->verbo_flag && vm->verbo & SHOW_CYCLE)
				printf("Cycle to die is now %d\n", vm->cycles_to_die);
		}
		vm->lives_counter = 0;
		vm->cycles = 0;
	}
}

void	let_the_game_begin(t_vm *vm)
{
	while (vm->cycles_to_die > 0 && vm->cursors_counter > 0)
	{	
		performe_check(vm);
		if (vm->verbo_flag && vm->verbo & SHOW_CYCLE)
		{
			printf("It is now cycle %d\n", vm->total_cycles + 1);
			// printf("Cycle to die is now %d\n", vm->cycles_to_die);
		}
		loop_through_cursors(vm);
		if (vm->dump_flag && vm->dump == vm->cycles)
		{
			dump_arena(vm->colosseum, MEM_SIZE);
			free_nd_exit(vm, NULL);
		}
	}
	if (!vm->the_conqueror)
		vm->the_conqueror =
				get_gldtor_by_id(vm->gladiators, vm->nbr_of_gldtors);
	printf("Contestant %d, \"%s\", has won !\n", vm->the_conqueror->id,
								vm->the_conqueror->prog_name);
	free_nd_exit(vm, NULL);
}

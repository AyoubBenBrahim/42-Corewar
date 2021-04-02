/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_the_game_begin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitihia <aaitihia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:23:32 by aybouras          #+#    #+#             */
/*   Updated: 2021/03/31 13:44:48 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void		exec_operation(t_vm *vm, t_cursor *prc)
{
	if (!parse_operation(vm, prc))
		prc->cmp.step = get_op_size(prc);
	else if (prc->cmp.code != OP_AFF || vm->is_aff)
	{
		g_op_tab[prc->cmp.code].op(prc, &prc->cmp, vm);
		if (vm->verbo_flag && vm->verbo & SHOW_OPERATION)
			print_operation(prc, &prc->cmp);
	}
	if (vm->verbo_flag && vm->verbo & SHOW_PC)
		print_pc(prc, &prc->cmp, vm);
	prc->cur_addr = addr_overlap(prc->cur_addr + prc->cmp.step);
}

void		remove_inactive_proc(t_vm *vm)
{
	t_cursor **this;
	t_cursor *to_free;

	this = &vm->cursors;
	while (*this)
	{
		if (!(*this)->is_alive || vm->cycles_to_die <= 0)
		{
			if (vm->verbo_flag && vm->verbo & SHOW_DEATHS)
				ft_printf("Process %d hasn't lived for %ld cycles (CTD %d)\n",
	(*this)->id, vm->total_cycles - (*this)->last_live - 1, vm->cycles_to_die);
			to_free = *this;
			*this = to_free->next;
			free(to_free);
			vm->cursors_counter--;
		}
		else
		{
			(*this)->is_alive = FALSE;
			this = &(*this)->next;
		}
	}
}

void		loop_through_cursors(t_vm *vm)
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

t_boolean	performe_check(t_vm *vm)
{
	if (vm->cycles == vm->cycles_to_die || vm->cycles_to_die <= 0)
	{
		vm->count_live_checks++;
		remove_inactive_proc(vm);
		if (vm->lives_counter >= NBR_LIVE
							|| vm->count_live_checks == MAX_CHECKS)
		{
			vm->count_live_checks = 0;
			vm->cycles_to_die -= CYCLE_DELTA;
			if (vm->verbo_flag && vm->verbo & SHOW_CYCLE)
				ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
		}
		vm->lives_counter = 0;
		vm->cycles = 0;
	}
	return (TRUE);
}

void		let_the_game_begin(t_vm *vm)
{
	while (performe_check(vm) && vm->cursors)
	{
		if (vm->verbo_flag && vm->verbo & SHOW_CYCLE)
			ft_printf("It is now cycle %d\n", vm->total_cycles + 1);
		loop_through_cursors(vm);
		if (vm->dump_flag && vm->dump <= vm->total_cycles)
		{
			dump_arena(vm->colosseum, MEM_SIZE);
			vm->dump_times--;
			if (vm->dump_times < 0)
				free_nd_exit(vm, NULL);
		}
	}
	if (!vm->the_conqueror)
		vm->the_conqueror =
				get_gldtor_by_id(vm->gladiators, vm->nbr_of_gldtors);
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->the_conqueror->id,
								vm->the_conqueror->prog_name);
	free_nd_exit(vm, NULL);
}

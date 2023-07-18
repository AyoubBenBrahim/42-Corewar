/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:54:26 by ayb*****          #+#    #+#             */
/*   Updated: 2021/03/31 13:35:29 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

t_cursor	*kill_cursor(t_vm *vm, t_cursor *this, t_cursor *prev)
{
	t_cursor *temp;

	if (vm->verbo_flag && vm->verbo & SHOW_DEATHS)
		ft_printf("Process %d hasn't lived for %ld cycles (CTD %d)\n",
				this->id, vm->total_cycles - this->last_live - 1,
				vm->cycles_to_die);
	if (prev == NULL)
		vm->cursors = this->next;
	else
		prev->next = this->next;
	temp = this->next;
	free(this);
	vm->cursors_counter--;
	return (temp);
}

void		load_cursor(t_cursor **curs_list, t_cursor *new_curs)
{
	if (new_curs)
		new_curs->next = *curs_list;
	*curs_list = new_curs;
}

t_cursor	*init_cursor(t_vm *vm, int id, int mem_zone)
{
	t_cursor	*cursor;
	t_gladiator *gldtor;

	if (!(gldtor = get_gldtor_by_id(vm->gladiators, id)))
		free_nd_exit(vm, "Gladiator doesn't exist");
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
		free_nd_exit(vm, "Failled Creating the Cursor");
	ft_bzero(cursor, sizeof(t_cursor));
	ft_memcpy(&(vm->colosseum[mem_zone]), gldtor->exec_code,
										gldtor->exec_code_size);
	cursor->id = vm->last_cursor_id++;
	cursor->carry = FALSE;
	cursor->cur_addr = mem_zone;
	vm->cursors_counter++;
	cursor->wait_cycles = 0;
	cursor->jump = 0;
	cursor->reg[1] = id * (-1);
	cursor->is_alive = FALSE;
	return (cursor);
}

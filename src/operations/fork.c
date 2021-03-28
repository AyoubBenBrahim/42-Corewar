/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:28:19 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/27 17:01:41 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"
void op_fork(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	t_cursor	*new;
	int			cur_addr;

	if (prc->cmp.code == 12)
		cur_addr = addr_overlap(prc->cur_addr + cmp->arg[0] % IDX_MOD);
	else
		cur_addr = addr_overlap(prc->cur_addr + cmp->arg[0]);
	if (!(new = (t_cursor *)malloc(sizeof(t_cursor))))
		free_nd_exit(vm, "Error while forking new cursor.");
	ft_memcpy(new, prc, sizeof(t_cursor));
	new->cur_addr = cur_addr;
	new->id = vm->last_cursor_id++;
	new->wait_cycles = 0;
	new->next = vm->cursors;
	vm->cursors = new;
	vm->cursors_counter++;
}
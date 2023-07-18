/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:55:44 by ayb*****          #+#    #+#             */
/*   Updated: 2021/03/28 16:26:20 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

int		idx_mod(long n)
{
	int mod;

	mod = n % IDX_MOD;
	return (mod);
}

int		get_op_size(t_cursor *prc)
{
	int ret;
	int i;
	int argc;
	int shift;

	ret = 1 + g_op_tab[prc->cmp.code].arg_code;
	i = 0;
	if (!g_op_tab[prc->cmp.code].arg_code)
		ret += g_op_tab[prc->cmp.code].size_dir;
	else
	{
		shift = 8 - (g_op_tab[prc->cmp.code].arg_num * 2);
		while (i < g_op_tab[prc->cmp.code].arg_num)
		{
			argc = prc->cmp.arg_code >> (i * 2 + shift) & 3;
			if (argc == REG_CODE)
				ret += 1;
			else if (argc == DIR_CODE)
				ret += g_op_tab[prc->cmp.code].size_dir;
			else if (argc == IND_CODE)
				ret += 2;
			i++;
		}
	}
	return (ret);
}

void	set_op_code(t_cursor *prc, t_vm *vm)
{
	prc->cmp.code = vm->colosseum[prc->cur_addr];
	if (between(vm->colosseum[prc->cur_addr], 1, 16))
		prc->wait_cycles = g_op_tab[prc->cmp.code].waiting_cycle;
}

void	show_gladiators(t_gladiator *gldtors)
{
	ft_printf("Introducing contestants...\n");
	while (gldtors)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				gldtors->id,
				gldtors->exec_code_size,
				gldtors->prog_name,
				gldtors->comment);
		gldtors = gldtors->next;
	}
}

void	parse_helper(t_vm *vm)
{
	t_gladiator	*gldtor;

	gldtor = vm->gladiators;
	vm->last_id_gld = 1;
	while (gldtor)
	{
		if (gldtor->id > vm->nbr_of_gldtors)
			free_nd_exit(vm, " Error: invalid id");
		if (gldtor->id == -1)
			gldtor->id = get_non_exist_id(vm->gladiators);
		gldtor = gldtor->next;
	}
}

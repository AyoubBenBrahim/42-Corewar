/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_related_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 14:09:46 by ayb*****          #+#    #+#             */
/*   Updated: 2021/03/31 14:09:52 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

t_boolean	is_valide(int n)
{
	return (n == 0 || n == 1 || n == 2 || n == 4 || n == 8 || n == 16);
}

void		parse_arg_dump(int *ac, int argc, char **argv, t_vm *vm)
{
	if (argc >= 4)
	{
		if (!is_number(argv[*ac + 1]))
			free_nd_exit(vm, "Error: invalid parameter");
		vm->dump = ft_atoi(argv[*ac + 1]);
		vm->dump_flag = TRUE;
		if (vm->dump < 0)
			free_nd_exit(vm, "Error: invalid number");
		*ac = *ac + 1;
		return ;
	}
	free_nd_exit(vm, "Error: invalid parameters");
}

void		parse_dump_time(int *ac, int argc, char **argv, t_vm *vm)
{
	if (*ac + 1 <= argc)
	{
		if (!is_number(argv[*ac + 1]))
			free_nd_exit(vm, "Error: invalid parameter");
		vm->dump_times = ft_atoi(argv[*ac + 1]);
		if (vm->dump_times < 0)
			free_nd_exit(vm, "Error: invalid dump_times.");
		*ac = *ac + 1;
		return ;
	}
	free_nd_exit(vm, "Error: invalid parameters");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:35:05 by aybouras          #+#    #+#             */
/*   Updated: 2021/03/31 13:37:06 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	print_manual(void)
{
	ft_printf("Usage: ./corewar [-dump N -v N | -n N ");
	ft_printf("[-a] <champion1.cor> <...>\n");
	ft_printf("\t-a\t: Prints output from \"aff\" (Default is to hide it)\n");
	ft_printf("\t-dump N\t: Dumps memory after N cycles then exits.\n");
	ft_printf("\t-dump N -dt M : Dumps memory after N cycles ");
	ft_printf("for M more cycles then exits.\n");
	ft_printf("\t-v N\t: Verbosity levels: \n");
	ft_printf("\t\t- 0 : Show only essentials.\n");
	ft_printf("\t\t- 1 : Show lives.\n");
	ft_printf("\t\t- 2 : Show cycles.\n");
	ft_printf("\t\t- 4 : Show operations (Params are NOT litteral ...)\n");
	ft_printf("\t\t- 8 : Show deaths.\n");
	ft_printf("\t\t- 16 : Show PC movements (Except for jumps).\n");
}

int		main(int ac, char **av)
{
	t_vm vm;

	if (ac == 1)
	{
		print_manual();
		return (0);
	}
	vm_init(&vm);
	parse_args(ac, av, &vm);
	prepare_battleground(&vm);
	show_gladiators(vm.gladiators);
	let_the_game_begin(&vm);
	return (0);
}

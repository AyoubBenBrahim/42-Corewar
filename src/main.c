/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:35:05 by aybouras          #+#    #+#             */
/*   Updated: 2021/03/25 09:21:16 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

int			main(int ac, char **av)
{
	t_vm vm;

	vm_init(&vm);
	parse_args(ac, av, &vm);
	prepare_battleground(&vm);
	show_gladiators(vm.gladiators);
	let_the_game_begin(&vm);
	return (0);
}

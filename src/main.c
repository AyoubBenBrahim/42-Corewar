/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:35:05 by aybouras          #+#    #+#             */
/*   Updated: 2021/01/12 11:35:09 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../inc/cor.h"



int			main(int ac, char **av)
{
	t_vm vm;

	vm_init(&vm);
	parse_args(ac, av, &vm);
	prepare_battleground(&vm);
	// print_colosseum(&vm);

	// let_the_game_begin();

	// t_gladiator *pl;
	// pl = vm.gladiators;
	// while (pl)
	// {
	// 	printf("id = %d\n", pl->id);
	// 	printf("file = %s\n", pl->associated_file);
	// 	printf("name = %s\n", pl->prog_name);
	// 	printf("comment = %s\n", pl->comment);
	// 	printf("exec = %s\n", pl->exec_code);
	// 	printf("==================\n");
	// 	pl = pl->next;
	// }


	return (0);
}


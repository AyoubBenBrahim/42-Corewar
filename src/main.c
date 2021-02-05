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


// t_cor  *get_cor(t_cor *oo)
// {
// 	static t_cor *p

// 	if (oo)
// 		p = oo
// 	return p
// }

// int main()
// {

// 	t_cor  *ll

// 	malloc
// 	get_cor(ll)
// }

// void jj()
// (
// 	t_cor *temp = get_cor(0)
// 	tmp->nex = optopt
// 	get_cor(0)->arrray[0]=65
// )


int			main(int ac, char **av)
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm));
	vm_init(&vm);
	parse_args(ac, av, &vm);
	prepare_battleground(&vm);
	// let_the_game_begin();

	// print the arena

printf("hi im done\n");

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


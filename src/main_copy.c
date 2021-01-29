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

#include <fcntl.h>
#include <stdio.h> // ************* delete
#include <unistd.h>

# include "../inc/cor.h"

#define HEADER_SIZ (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

/*

// master 4 ======================

void	get_player(char **argv, int i, t_vm *v)
{
	int j;
	int num;
	int doublon;

	doublon = 0;
	num = -v->nplayer - 1;
	j = 0;
	while (j < v->nplayer)
	{
		if (v->p[j++].nplayer == num)
			doublon = 1;
		num -= doublon ? 1 : 0;
		doublon = 0;
	}
	if (is_valid_player(argv[i]))
	{
		if (v->nplayer < MAX_PLAYERS)
			save_player(argv[i], v, v->nplayer, num);
		else
			xerror("Error: too many players", -1);
		v->nplayer++;
	}
	else
		xerror("Error: invalid champion", -1);
}



int		main(int argc, char **argv)
{
	t_vm		vm;
	t_viewer	v;

	vm_init(&vm);
	parse_opt(argc, argv, &vm);
	if (!vm.nplayer)
		print_help();
	load_arena(&vm);
	run_game(&vm);
	return (0);
}
// ============================

*/

// 7
void		get_player(t_player *player, const char *file, int id)
{
	int		fd;
	ssize_t	size;
	uint8_t	buf[4096];

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		// vm_exit(EXIT_FAILURE, "%s: %m\n", file);
		exit(0);
	}
	if (read(fd, &buf, HEADER_SIZ) < HEADER_SIZ)
	{
		// vm_exit(EXIT_FAILURE, "%s: Invalid header.\n", file);
		exit(0);
	}
	if (*(uint32_t *)buf != little_to_big_endian(COREWAR_EXEC_MAGIC))
	{
		// vm_exit(EXIT_FAILURE, "%s: Wrong file: magic number.\n", file);
		exit(0);
	}
	ft_memcpy((void *)(player->magic_header), buf, 8);

	printf("done\n");
	// ft_bzero(player, sizeof(t_player));
	// ft_memcpy((void*)(player->prog_name), buf + sizeof(uint32_t), PROG_NAME_LENGTH);
	// ft_memcpy((void*)(player->comment), buf + sizeof(uint32_t) + PROG_NAME_LENGTH + 8, COMMENT_LENGTH + 1);
	// if ((size = read(fd, &buf, CHAMP_MAX_SIZE + 1)) <= 0)
	// 	vm_exit(EXIT_FAILURE, "%s: %m: Void champion.\n", file);
	// if (size > CHAMP_MAX_SIZE)
	// 	vm_exit(EXIT_FAILURE, "%s: Champion exceeding size: %d\n", file, size);
	// if (close(fd) < 0)
	// 	vm_exit(EXIT_FAILURE, "%s: %m\n", file);
	player->id = id;
	// player->source_code_size = (size_t)size;
// ft_memcpy(player->bin, buf, player->source_code_len);
}



void	parse_args(int argc, char **argv, t_vm *vm)
{
	int			ac;
	char		*cor;
	int			nbr_of_players;
	// t_player	players;


	ac = 1;
	nbr_of_players = 0;
	vm->file = (char **)malloc(sizeof(char *) * MAX_PLAYERS);
	while (ac < argc)
	{
		if (!ft_strcmp("-v", argv[ac]))
		{
			printf("flag -v\n");
			// parse_arg_verbose(argc, argv, vm, &ac);
		}
		else if (!ft_strcmp("-dump", argv[ac]))
		{
			printf("flag -dump\n");
			// parse_arg_dump(argc, argv, vm, &ac);// pass ac + 1
		}
		else if ((cor = ft_strstr(argv[ac], ".cor")) && cor != argv[ac] && !cor[4])
		{
			printf("%s \n", argv[ac]);
			vm->file[nbr_of_players] = (char *)malloc(sizeof(char) * ft_strlen(argv[ac] + 1));
			ft_strcpy(vm->file[nbr_of_players], argv[ac]);
			nbr_of_players++;
			if (nbr_of_players > MAX_PLAYERS)
			{
				ft_putstr("Error: MAX_PLAYERS EXCEEDED\n");
				exit(0);
			}
			// get_player(argv, ac, vm);
			get_player(vm->players, argv[ac], nbr_of_players);
		}
		else if (!ft_strcmp("-n", argv[ac]))
		{
			printf("flag -n\n");
			// parse_arg_n(argc, argv, vm, &ac);
		}
		else
		{
			// free
			ft_putstr("Error: invalid parameters \n");
			exit(0);
		}
		vm->file[nbr_of_players] = NULL;
		ac++;
	}

	//  while (*vm->file)
	// 	 printf("|%s|\n", *vm->file++);

}

int			main(int ac, char **av)
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm));

	// vm_init(&vm);
	parse_args(ac, av, &vm);
	// let_the_game_begin();

	return (0);
}

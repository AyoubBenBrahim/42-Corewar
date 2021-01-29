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



// ============================

*/

// 7
void		get_player(t_player *player, const char *file, int id)
{
	int		fd;
	uint32_t	size;
	// size_t	bytes_to_copy;
	uint8_t	buffer[4096];

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		printf("%s is an Invalid file.\n", file);
		exit(0);
	}
	if (read(fd, &buffer, HEADER_SIZ) < HEADER_SIZ)
	{
		printf("%s has an Invalid header.\n", file);
		exit(0);
	}
	if (*(uint32_t *)buffer != little_to_big_endian(COREWAR_EXEC_MAGIC))
	{
		printf("%s has an invalid magic Header.\n", file);
		exit(0);
	}
	// ft_bzero(player, sizeof(t_player));
	ft_memcpy((void*)(player->prog_name), buffer + sizeof(uint32_t), PROG_NAME_LENGTH);
	ft_memcpy((void*)(player->comment), buffer + 4 + PROG_NAME_LENGTH + 8, COMMENT_LENGTH + 1);
	if ((size = read(fd, &buffer, CHAMP_MAX_SIZE + 1)) <= 0)
	{
		printf("%s is a champion without executable code\n", file);
		exit(0);
	}
	if (size > CHAMP_MAX_SIZE)
	{
		printf("executable code size exceed\n");
		exit(0);
	}
	player->id = id;
	player->exec_code_size = size;
	ft_memcpy(player->exec_code , buffer, player->exec_code_size);
	close(fd);
	printf("done\n\n");
}



void	parse_args(int argc, char **argv, t_vm *vm)
{
	int			ac;
	char		*cor;
	int			nbr_of_players;
	// t_player	players;


	ac = 1;
	vm->nbr_of_players = 0;
	// vm->file = (char **)malloc(sizeof(char *) * MAX_PLAYERS);
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
			// vm->file[vm->nbr_of_players] = (char *)malloc(sizeof(char) * ft_strlen(argv[ac] + 1));
			ft_strcpy(vm->file[vm->nbr_of_players], argv[ac]);
			vm->nbr_of_players++;
			if (vm->nbr_of_players > MAX_PLAYERS)
			{
				ft_putstr("Error: MAX_PLAYERS EXCEEDED\n");
				exit(0);
			}
			// get_player(argv, ac, vm);
			vm->players = (t_player *)malloc(sizeof(t_player));
			get_player(vm->players, argv[ac], vm->nbr_of_players);
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
		vm->file[vm->nbr_of_players] = NULL;
		ac++;
	}

	//  while (*vm->file)
	// 	 printf("|%s|\n", *vm->file++);

}

int			main(int ac, char **av)
{
	t_vm vm;

	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(vm.players, sizeof(t_player));

	// vm_init(&vm);
	parse_args(ac, av, &vm);
	// let_the_game_begin();

	printf("nbr players = %d\n", vm.nbr_of_players);


	return (0);
}

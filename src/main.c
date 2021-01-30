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

#define HEADER_SIZE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH)

void		get_player(t_player *ply, int id)
{
	int		fd;
	uint32_t	size;
	// size_t	bytes_to_copy;
	uint8_t	buffer[4096];

	if ((fd = open(ply->associated_file, O_RDONLY)) < 0)
	{
		printf("%s is an Invalid file.\n", ply->associated_file);
		exit(0);
	}
	if (read(fd, &buffer, HEADER_SIZE) < HEADER_SIZE)
	{
		printf("%s has an Invalid header.\n", ply->associated_file);
		exit(0);
	}
	if (*(uint32_t *)buffer != little_to_big_endian(COREWAR_EXEC_MAGIC))
	{
		printf("%s has an invalid magic Header.\n", ply->associated_file);
		exit(0);
	}
	ft_memcpy((void*)(ply->prog_name), buffer + sizeof(uint32_t), PROG_NAME_LENGTH);
	ft_memcpy((void*)(ply->comment), buffer + 4 + PROG_NAME_LENGTH + 8, COMMENT_LENGTH + 1);
	if ((size = read(fd, &buffer, CHAMP_MAX_SIZE + 1)) <= 0)
	{
		printf("%s is a champion without executable code\n", ply->associated_file);
		exit(0);
	}
	if (size > CHAMP_MAX_SIZE)
	{
		printf("executable code size exceed\n");
		exit(0);
	}
	ply->id = id;
	ply->exec_code_size = size;
	ft_memcpy(ply->exec_code , buffer, ply->exec_code_size);
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
			// ft_strcpy(vm->file[vm->nbr_of_players], argv[ac]);
			vm->nbr_of_players++;
			if (vm->nbr_of_players > MAX_PLAYERS)
			{
				ft_putstr("Error: MAX_PLAYERS EXCEEDED\n");
				exit(0);
			}
			t_player	*pl;
			if (!(pl = (t_player *)malloc(sizeof(t_player))))
			{
				// free
				exit (0);
			}
			pl->associated_file = argv[ac];
			get_player(pl, vm->nbr_of_players);
			pl->next = NULL;
			if (!vm->players)
			{
				vm->players = pl;
				vm->tail = pl;
			}
			else
			{
				vm->tail->next = pl;
				vm->tail = pl;
			}
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
		// vm->file[vm->nbr_of_players] = NULL;
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

	printf("nbr players = %d\n", vm.nbr_of_players);

	t_player *pl;
	pl = vm.players;
	while (pl)
	{
		printf("file = %s\n", pl->associated_file);
		printf("name = %s\n", pl->prog_name);
		printf("comment = %s\n", pl->comment);
		printf("exec = %s\n", pl->exec_code);
		printf("==================\n");
		pl = pl->next;
	}





	return (0);
}

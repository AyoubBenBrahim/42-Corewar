/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_related.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybouras <aybouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:55:36 by aybouras          #+#    #+#             */
/*   Updated: 2021/02/08 12:55:40 by aybouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/cor.h"

t_gladiator *get_gldtor_by_id(t_gladiator *gldtor_lst, int id)
{
	while (gldtor_lst)
	{
		if (gldtor_lst->id == id)
			return (gldtor_lst);
		gldtor_lst = gldtor_lst->next;
	}
	return (NULL);
}

void		get_player(t_gladiator *gldtor, int id)
{
	int		fd;
	uint32_t	size;
	uint8_t	buffer[4096];

	if ((fd = open(gldtor->associated_file, O_RDONLY)) < 0)
	{
		printf("%s is an Invalid file.\n", gldtor->associated_file); // u may use perorr()
		exit(0);
	}
	if (read(fd, &buffer, HEADER_SIZE) < HEADER_SIZE)
	{
		printf("%s has an Invalid header.\n", gldtor->associated_file);
		exit(0);
	}
	if (*(uint32_t *)buffer != little_to_big_endian(COREWAR_EXEC_MAGIC))
	{
		printf("%s has an invalid magic Header.\n", gldtor->associated_file);
		exit(0);
	}
	ft_memcpy((void*)(gldtor->prog_name), buffer + sizeof(uint32_t), PROG_NAME_LENGTH);
	ft_memcpy((void*)(gldtor->comment), buffer + 4 + PROG_NAME_LENGTH + 8, COMMENT_LENGTH + 1);
	if ((size = read(fd, &buffer, CHAMP_MAX_SIZE + 1)) <= 0)
	{
		printf("%s is a champion without executable code\n", gldtor->associated_file);
		exit(0);
	}
	if (size > CHAMP_MAX_SIZE)
	{
		printf("executable code size exceed\n");
		exit(0);
	}
	gldtor->id = id;
	gldtor->exec_code_size = size;
	ft_memcpy(gldtor->exec_code , buffer, gldtor->exec_code_size);
	close(fd);
}

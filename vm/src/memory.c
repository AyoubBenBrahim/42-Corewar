/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <ayb*****@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:36:29 by ayb*****          #+#    #+#             */
/*   Updated: 2021/03/25 09:37:44 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

static void	dump_hex(unsigned char *memory)
{
	const char	*tab = "0123456789abcdef";
	int			i;

	i = 0;
	while (i < MAX_DUMP)
	{
		ft_printf("%c", tab[memory[i] / 16]);
		ft_printf("%c", tab[memory[i] % 16]);
		i < MAX_DUMP - 1 ? ft_printf(" ") : 0;
		i++;
	}
	ft_printf(" \n");
}

void		dump_arena(unsigned char *memory, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		i == 0 ? ft_printf("0x0000 : ") : ft_printf("%#.4x : ", i);
		dump_hex(memory + i);
		i += MAX_DUMP;
	}
}

int			addr_overlap(int addr)
{
	return ((MEM_SIZE + (addr)) % MEM_SIZE);
}

int			get_mem(unsigned char *mem, int addr, int oct)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (i < oct)
	{
		ret = (ret << 8) + mem[addr_overlap(addr + i)];
		i++;
	}
	if (oct == 1)
		return ((char)ret);
	if (oct == 2)
		return ((short)ret);
	return (ret);
}

void		set_mem(unsigned char *mem, int addr, int val, int oct)
{
	int	i;

	i = 0;
	if (val < 0)
		val = ((long)1 << (oct * 8)) + (long)val;
	while (i < oct)
	{
		mem[addr_overlap(addr + i)] = val >> ((oct - i - 1) * 8);
		i++;
	}
}

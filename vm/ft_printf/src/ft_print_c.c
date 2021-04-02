/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:44:27 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:44:05 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Treats '-', width and '0' flags for non supported specifiers
*/

void	non_spec_char(t_args *args, t_vars *var)
{
	static char	n[2];
	char		pad;
	char		side;
	char		*tmp;

	pf_memset(n, args->spec, 1);
	args->result = pf_strdup(n);
	pad = args->flag & MASK_ZERO ? '0' : ' ';
	side = args->flag & MASK_MINUS ? 'R' : 'L';
	if (args->width <= 0)
		var->counter += pf_putstr(args->result);
	else
	{
		tmp = args->result;
		args->result = padd(args->result, args->width - 1, pad, side);
		var->counter += pf_putstr(args->result);
		pf_strdel(&tmp);
	}
	pf_strdel(&args->result);
}

/*
**	Prints character with the given field width
*/

void	pf_print_c(t_args *args, t_vars *var)
{
	char	c;
	char	padd;

	c = args->spec == 'c' ? va_arg(var->types_list, int) : args->spec;
	if (pf_contains("%c", args->spec))
	{
		padd = args->flag & MASK_ZERO ? '0' : ' ';
		if (args->width <= 0)
			var->counter += pf_putchar(c);
		else
		{
			if (!(args->flag & MASK_MINUS))
				pf_putnchar(padd, args->width - 1);
			pf_putchar(c);
			if (args->flag & MASK_MINUS)
				pf_putnchar(padd, args->width - 1);
			var->counter += args->width;
		}
	}
	else
		non_spec_char(args, var);
}

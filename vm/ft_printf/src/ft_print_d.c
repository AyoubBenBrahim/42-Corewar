/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:55:22 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:41:35 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints signed decimal conversions (d, i)
*/

void	pf_print_d(t_args *args, t_vars *var)
{
	t_ll	x;
	char	*tmp;

	x = pf_signed(args, var);
	args->result = pf_ltoa(x);
	if (!args->flag && !args->width && args->precision == -1)
	{
		var->counter += pf_putstr(args->result);
		pf_strdel(&args->result);
	}
	else
	{
		if (!args->precision && !x)
		{
			tmp = args->result;
			args->result = pf_strdup("");
			pf_strdel(&tmp);
		}
		else
			pf_precision(args);
		pf_width(args);
		var->counter += pf_putstr(args->result);
		pf_strdel(&args->result);
	}
}

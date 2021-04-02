/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 19:41:44 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:41:49 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Prints string arguments
*/

void	pf_print_s(t_args *args, t_vars *var)
{
	args->result = pf_strdup(va_arg(var->types_list, char *));
	if (!args->result)
		args->result = pf_strdup("(null)");
	if (!args->flag && !args->width && args->precision == -1)
		var->counter += pf_putstr(args->result);
	else
	{
		pf_precision(args);
		pf_width(args);
		var->counter += pf_putstr(args->result);
	}
	pf_strdel(&args->result);
}

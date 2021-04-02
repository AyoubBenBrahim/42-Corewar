/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:55:29 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/20 12:34:42 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatcher.h"

/*
**	Width flag dispatcher
*/

void	pf_width(t_args *arg)
{
	int		i;

	i = 0;
	while (i < DISPATCHERS)
	{
		if (g_funcs[i].spec == arg->spec)
			g_funcs[i].width(arg);
		i++;
	}
}

/*
**	Handles width flag for numeric signed conversions (i, d, f);
*/

void	pf_numeric(t_args *arg)
{
	int		sign;
	int		len;
	int		pad;
	char	*tmp;

	sign = arg->result[0] == '-';
	sign = manage_sign(arg, sign);
	len = pf_strlen(arg->result);
	pad = arg->width - len;
	if (arg->width > len)
	{
		tmp = arg->result;
		if ((arg->flag & MASK_ZERO) && !is_nan(arg) && !is_inf(arg))
		{
			arg->result = padd(arg->result + sign, pad, '0', 'L');
			if (sign)
				arg->result = pf_strjoin_free(pf_strsub(tmp, 0, 1), \
						arg->result);
		}
		else if ((arg->flag & MASK_MINUS))
			arg->result = padd(arg->result, pad, ' ', 'R');
		else
			arg->result = padd(arg->result, pad, ' ', 'L');
		pf_strdel(&tmp);
	}
}

/*
**	Handles width flag for string conversion (s);
*/

void	pf_string(t_args *arg)
{
	int		len;
	int		pad;
	char	*tmp;

	len = pf_strlen(arg->result);
	pad = arg->width - len;
	tmp = arg->result;
	if (arg->width > len)
	{
		if (arg->flag & MASK_MINUS)
			arg->result = padd(arg->result, pad, ' ', 'R');
		else if (arg->flag & MASK_ZERO)
			arg->result = padd(arg->result, pad, '0', 'L');
		else
			arg->result = padd(arg->result, pad, ' ', 'L');
		pf_strdel(&tmp);
	}
}

/*
**	Gets the string prefix of each unsigned conversions (poxb)
**	According to the '#' flag.
*/

char	*get_prefix(t_args *arg)
{
	char	spec;

	spec = arg->spec;
	if (spec == 'p')
		return (pf_strdup("0x"));
	if (arg->flag & MASK_HASH)
	{
		if (arg->unsign_ed)
		{
			if (spec == 'x')
				return (pf_strdup("0x"));
			else if (spec == 'X')
				return (pf_strdup("0X"));
		}
		if (arg->spec == 'o' && arg->result[0] != '0')
			return (pf_strdup("0"));
		else if (spec == 'b')
			return (pf_strdup("0b"));
	}
	return (pf_strdup(""));
}

/*
**	Handles width flag for unsigned conversions (poubx);
*/

void	pf_alternate(t_args *arg)
{
	char	*prefix;
	int		flg;
	int		pad;
	char	*tmp;
	char	side;

	prefix = get_prefix(arg);
	flg = ((arg->flag & MASK_HASH) || arg->spec == 'p');
	pad = arg->width - (pf_strlen(arg->result) + pf_strlen(prefix));
	side = arg->flag & MASK_MINUS ? 'R' : 'L';
	if (arg->flag & MASK_ZERO)
	{
		tmp = arg->result;
		arg->result = padd(arg->result, pad, '0', side);
		pf_strdel(&tmp);
		arg->result = flg ? pf_strjoin_free(prefix, arg->result) : arg->result;
	}
	else
	{
		arg->result = flg ? pf_strjoin_free(prefix, arg->result) : arg->result;
		tmp = arg->result;
		arg->result = padd(arg->result, pad, ' ', side);
		pf_strdel(&tmp);
	}
	(!flg) ? pf_strdel(&prefix) : (void)flg;
}

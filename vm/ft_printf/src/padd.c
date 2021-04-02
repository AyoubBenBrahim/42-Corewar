/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:48:48 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:45:22 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Padds @rest characters @c to the @side side
**	@c: corresponds to the character to be padded
**	@rest: the number of occurences to be padded
**	@side: 'R' for right, 'L' for left.
*/

char	*padd(char *element, int rest, char c, char side)
{
	char	*str;
	char	*tmp;

	str = rest <= 0 ? NULL : pf_strnew(rest);
	if (rest <= 0)
		return (pf_strdup(element));
	pf_memset(str, c, rest);
	tmp = str;
	if (side == 'R')
		str = pf_strjoin(element, str);
	else
		str = pf_strjoin(str, element);
	pf_strdel(&tmp);
	return (str);
}

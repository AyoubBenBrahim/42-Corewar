/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:50:54 by ayb*****          #+#    #+#             */
/*   Updated: 2019/11/24 19:45:41 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Sums two string numbers.
*/

char	*sum_string(char *num1, char *num2)
{
	char	*str_sum;
	int		sum;
	char	*modulo;
	t_vars	var;

	var.n = pf_strlen(num1) - 1;
	var.m = pf_strlen(num2) - 1;
	var.carry = 0;
	str_sum = pf_strnew(0);
	while (var.n >= 0 || var.m >= 0 || var.carry != 0)
	{
		modulo = pf_strnew(1);
		sum = var.carry;
		if (var.n >= 0)
			sum += num1[var.n--] - '0';
		if (var.m >= 0)
			sum += num2[var.m--] - '0';
		var.carry = sum / 10;
		modulo[0] = (sum % 10) + '0';
		str_sum = pf_strjoin_free(modulo, str_sum);
	}
	pf_strdel(&num1);
	pf_strdel(&num2);
	return (str_sum);
}

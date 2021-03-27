/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youarzaz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:35:41 by youarzaz          #+#    #+#             */
/*   Updated: 2019/04/01 15:56:43 by youarzaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strindex(char *str, char c)
{
	int i;

	i = 0;
	if (!c)
		return (-1);
	while (str[i++])
		if (str[i] == c)
			return (i);
	return (-1);
}

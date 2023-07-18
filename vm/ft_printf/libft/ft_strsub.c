/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:55:06 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/14 16:40:34 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (start + len > pf_strlen(s) || sub == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < start + len)
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

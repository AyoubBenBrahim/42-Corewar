/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 21:20:35 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/17 15:03:41 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*pf_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*joined;

	if (!s1 || !s2)
		return (NULL);
	i = pf_strlen(s1) + pf_strlen(s2);
	if (!(joined = pf_strnew(i)))
		return (NULL);
	pf_strcpy(joined, s1);
	pf_strcat(joined, s2);
	return (joined);
}

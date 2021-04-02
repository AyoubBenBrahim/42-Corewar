/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:15:18 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/13 15:47:06 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*pf_strdup(const char *s1)
{
	char	*dup;

	if (!s1)
		return (NULL);
	if (!(dup = pf_strnew(pf_strlen(s1))))
		return (NULL);
	pf_strcpy(dup, s1);
	return (dup);
}

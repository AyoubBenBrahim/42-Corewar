/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayb***** <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 22:48:16 by ayb*****          #+#    #+#             */
/*   Updated: 2019/04/05 10:31:17 by ayb*****         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*pf_memalloc(size_t size)
{
	void *fresh_mem;

	fresh_mem = NULL;
	fresh_mem = (void *)malloc(size);
	if (fresh_mem == NULL)
		return (NULL);
	pf_bzero(fresh_mem, size);
	return (fresh_mem);
}

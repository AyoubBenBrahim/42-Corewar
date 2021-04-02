/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhossan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:48:46 by akhossan          #+#    #+#             */
/*   Updated: 2019/11/24 19:38:53 by akhossan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H
# include "ft_printf.h"

typedef void		(*t_width_func)(t_args *arg);

typedef struct		s_width_dispatch
{
	char			spec;
	t_width_func	width;
}					t_width_dispatch;

void				pf_alternate(t_args *args);
void				pf_string(t_args *args);
void				pf_numeric(t_args *args);

t_width_dispatch	g_funcs[] =
{
	{'d', pf_numeric},
	{'i', pf_numeric},
	{'u', pf_numeric},
	{'s', pf_string},
	{'p', pf_alternate},
	{'x', pf_alternate},
	{'X', pf_alternate},
	{'o', pf_alternate},
	{'b', pf_alternate},
	{'f', pf_numeric}
};

#endif

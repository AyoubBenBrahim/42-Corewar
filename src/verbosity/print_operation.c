/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:25:31 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/29 19:14:12 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	print_store_addr_details(t_cursor *prc, t_op_component *cmp)
{
	printf("%7s| -> store to %d + %d = %d (with pc and mod %d)\n",
			"",
			cmp->arg[1],
			cmp->arg[2],
			cmp->arg[2] + cmp->arg[1],
			prc->cur_addr + idx_mod((cmp->arg[1] + cmp->arg[2]))
		);
}

void	print_load_addr_details(t_cursor *prc, t_op_component *cmp)
{
	printf("%7s| -> load from %d + %d = %d (with pc and mod %d)\n",
			"",
			cmp->arg[0],
			cmp->arg[1],
			cmp->arg[1] + cmp->arg[0],
			prc->cur_addr + idx_mod((cmp->arg[0] + cmp->arg[1]))
		);
}

void print_addr_details(t_cursor *prc, t_op_component *cmp)
{
	if(cmp->code == OP_LDI || cmp->code == OP_LLDI)
		print_load_addr_details(prc, cmp);
	else if(cmp->code == OP_STI)
		print_store_addr_details(prc, cmp);
}

void print_args(t_cursor *prc, t_op_component *cmp)
{
	const t_op op = op_tab[cmp->code];
	int i;

	i = 0;
	if (op.arg_code)
		while(i < op.arg_num)
		{
			if(op.arg[i] == T_REG)
				printf(" r%d", prc->cmp.arg[i]);
			else
				printf(" %d", prc->cmp.arg[i]);
			i++;
		}
	else
		printf(" %d", prc->cmp.arg[0]);
}

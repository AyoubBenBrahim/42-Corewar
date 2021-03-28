/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbosity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 02:25:31 by aait-ihi          #+#    #+#             */
/*   Updated: 2021/03/28 16:03:57 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cor.h"

void	print_store_addr_details(t_cursor *prc, t_op_component *cmp)
{
	const int arg2_is_register = get_arg_code(cmp->arg_code, 1) == T_REG;
	const int arg3_is_register = get_arg_code(cmp->arg_code, 2) == T_REG;
	const int value1 = arg2_is_register ? prc->reg[cmp->arg[1]] : cmp->arg[1];
	const int value2 = arg3_is_register ? prc->reg[cmp->arg[2]] : cmp->arg[2];
	printf("%7s| -> store to %d + %d = %d (with pc and mod %d)\n",
			"",
			value1,
			value2,
			value2 + value1,
			prc->cur_addr + idx_mod((value1 + value2))
		);
}
void	print_load_addr_details(t_cursor *prc, t_op_component *cmp)
{
	const int arg2_is_register = get_arg_code(cmp->arg_code, 1) == T_REG;
	const int arg3_is_register = get_arg_code(cmp->arg_code, 2) == T_REG;
	const int value1 = arg2_is_register ? prc->reg[cmp->arg[1]] : cmp->arg[1];
	const int value2 = arg3_is_register ? prc->reg[cmp->arg[2]] : cmp->arg[2];
	printf("%7s| -> load from %d + %d = %d (with pc and mod %d)\n",
			"",
			value1,
			value2,
			value2 + value1,
			prc->cur_addr + idx_mod((value1 + value2))
		);
}

void print_addr_details(t_cursor *prc, t_op_component *cmp)
{
	if(cmp->code == 10 || cmp->code == 14)
		print_load_addr_details(prc, cmp);
	else if(cmp->code == 11)
		print_store_addr_details(prc, cmp);
}


void print_operation(t_cursor *prc, t_op_component *cmp)
{
	int i;
	const t_op op = op_tab[prc->cmp.code];

	printf("P%5d | %s", prc->id, op.name);
	i = 0;
	while(i <  op.arg_num)
	{
		if(get_arg_code(prc->cmp.arg_code, i) == T_REG)
			printf(" r%d", prc->cmp.arg[i]);
		else
			printf(" %d", prc->cmp.arg[i]);
		i++;
	}
	printf("\n");
	print_addr_details(prc, cmp);
}

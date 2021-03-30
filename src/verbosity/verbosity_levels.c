
#include "../inc/cor.h"

void print_operation(t_cursor *prc, t_op_component *cmp)
{
	const t_op op = op_tab[cmp->code];

	printf("P%5d | %s", prc->id, op.name);
	print_args(prc, cmp);
	if(cmp->code == OP_ZJMP)
		printf(" %s", prc->carry ? "OK" : "FAILED");
	else if(cmp->code == OP_FORK)
		printf(" (%d)",addr_overlap(prc->cur_addr + idx_mod(cmp->arg[0])));
	else if(cmp->code == OP_LFORK)
		printf(" (%d)",addr_overlap(prc->cur_addr + cmp->arg[0]));
	printf("\n");
	print_addr_details(prc, cmp);
}

void print_pc(t_cursor *prc, t_op_component *cmp, t_vm *vm)
{
	int i;

	i = 0;
	if(cmp->code == OP_ZJMP)
		return;
	printf("ADV %d (%s%#.4x -> %#.4x) ", cmp->step, prc->cur_addr ? "" : "0x",
									prc->cur_addr, prc->cur_addr + cmp->step);
	while(i < cmp->step)
	{
		printf("%.2x ", (unsigned char)get_mem(vm->colosseum,
														prc->cur_addr + i, 1));
		i++;
	}
	printf("\n");
}

void print_lives(t_gladiator *gldtor)
{
	printf("Player %d (%s) is said to be alive\n", gldtor->id, gldtor->prog_name);
}


# include "../inc/cor.h"

void	load_cursor(t_cursor **curs_list, t_cursor *new)
{
	if (new)
		new->next = *curs_list;
	*curs_list = new;
}

t_cursor	*init_cursor(t_vm *vm, int id, int mem_zone)
{
	t_cursor	*cursor;
	t_gladiator *gldtor;

	if (!(gldtor = get_gldtor_by_id(vm->gladiators, id)))
	{
		ft_putstr("gladiator doesn't exist\n");
		//free
		exit(0);
	}
	if (!(cursor = (t_cursor *)malloc(sizeof(t_cursor))))
	{
		// free
		exit(0);
	}
	ft_bzero(cursor, sizeof(t_cursor));
	// printf("%p mem_zone : %d size to write : %d\n\n",vm->colosseum, mem_zone ,gldtor->exec_code_size);
	ft_memcpy(&(vm->colosseum[mem_zone]), gldtor->exec_code, gldtor->exec_code_size);

	cursor->id = id;
	cursor->carry = FALSE;
	// cursor->op_code;
	cursor->last_live = 0;
	cursor->wait_cycles = 0;
	cursor->jump = 0;
	cursor->reg[0] = id * (-1); //
	return (cursor);
}


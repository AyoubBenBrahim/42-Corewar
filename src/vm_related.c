
# include "../inc/cor.h"


void vm_init(t_vm *vm)
{

	vm->colosseum = (uint8_t *)malloc(sizeof(uint8_t) * MEM_SIZE + 1);
	ft_bzero(&vm->colosseum, sizeof(vm->colosseum));




}

void	prepare_battleground(t_vm	*vm)
{
	int			id;
	int			mem_zone;
	int			size;
	t_cursor	*cursor;

	id = 1;
	mem_zone = 0;
	size = MEM_SIZE / vm->nbr_of_gldtors;
	while (id <= vm->nbr_of_gldtors)
	{
		cursor = init_cursor(vm, id, mem_zone);
		load_cursor(&(vm->cursors), cursor);
		vm->cursors_counter++;
		mem_zone += size;
		id++;
	}
}

// p1:  p = 0
// p2:  p = 0 + 1365
// p3:  p = 1365 + 1365 = 2730

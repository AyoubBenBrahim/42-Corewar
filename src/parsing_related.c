
# include "../inc/cor.h"

void parse_arg_dump()
{

}

void parse_arg_n()
{

}

void	parse_args(int argc, char **argv, t_vm *vm)
{
	int			ac;
	char		*cor;
	t_gladiator	*gldtor;

	ac = 1;
	vm->nbr_of_gldtors = 0;
	while (ac < argc)
	{
		if (!ft_strcmp("-v", argv[ac]))
		{
			printf("flag -v\n");
			// parse_arg_verbose();
		}
		else if (!ft_strcmp("-dump", argv[ac]))
		{
			printf("flag -dump\n");
			// parse_arg_dump();// pass ac + 1
		}
		else if ((cor = ft_strstr(argv[ac], ".cor")) && cor != argv[ac] && !cor[4])
		{
			vm->nbr_of_gldtors++;
			if (vm->nbr_of_gldtors > MAX_PLAYERS)
			{
				ft_putstr("Error: MAX_PLAYERS EXCEEDED\n");
				exit(0);
			}
			if (!(gldtor = (t_gladiator *)malloc(sizeof(t_gladiator))))
			{
				// free
				exit (0);
			}
			ft_bzero(gldtor, sizeof(t_gladiator));
			gldtor->associated_file = argv[ac];
			get_player(gldtor, vm->nbr_of_gldtors);
			gldtor->next = NULL;
			if (!vm->gladiators)
			{
				vm->gladiators = gldtor;
				vm->tail = gldtor;
			}
			else
			{
				vm->tail->next = gldtor;
				vm->tail = gldtor;
			}
		}
		else if (!ft_strcmp("-n", argv[ac]))
		{
			printf("flag -n\n");
			// parse_arg_n();
		}
		else
		{
			// free
			ft_putstr("Error: invalid parameters \n");
			exit(0);
		}
		ac++;
	}
}

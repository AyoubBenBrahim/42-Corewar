
#ifndef COR_H
# define COR_H

# include <stdlib.h>
# include "op.h"
# include "../libft/libft.h"


typedef enum			e_boolean
{
	FALSE,
	TRUE,
}						t_boolean;

typedef struct		s_player
{
	int					id;
	// unsigned int		magic_header;
	char				*associated_file;
	char				prog_name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				exec_code[MEM_SIZE];
	unsigned int		exec_code_size;
	struct s_player		*next;
}					t_player;

typedef struct	 s_cursors // s_process
{
	int				id;
	t_boolean		carry;
	int				op_code; // operation code
	int				last_live;
	int				wait_cycles;
	int				jump;
	t_player		*player;
	struct s_cursor		*next;
}		t_cursor;

typedef struct		s_vm
{
	unsigned char		colosseum[MEM_SIZE];
	t_player			*players;
	t_player			*tail;
	int					nbr_of_players;;
	t_player			*last_alive;
	t_cursor			*cursors;
	int					lives_num;
	int					cycles;
	int					cycles_to_die;
	int					cycles_after_check;

}					t_vm;

unsigned int little_to_big_endian(unsigned int x);

#endif

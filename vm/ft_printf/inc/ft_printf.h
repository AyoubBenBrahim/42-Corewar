/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:54:30 by akhossan          #+#    #+#             */
/*   Updated: 2021/04/01 11:42:50 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define DISPATCHERS	10
# define MASK_MINUS	1
# define MASK_PLUS	2
# define MASK_HASH	4
# define MASK_SPACE	8
# define MASK_ZERO	16
# define MASK_H		32
# define MASK_HH	64
# define MASK_L		128
# define MASK_LL	256
# define MASK_J		512
# define MASK_Z		1024
# define MASK_STAR	2048
# define MASK_UPL	4096
# define DIOUXXPB	"diouxXpb"

# include <stdarg.h>
# include <limits.h>
# include "../libft/libft.h"

typedef long double	t_lldb;
typedef long long	t_ll;

typedef struct	s_floatbits
{
	unsigned long	mantissa : 63;
	unsigned int	bit : 1;
	unsigned int	exponent : 15;
	unsigned int	sign : 1;
}				t_floatbits;

typedef union	u_float
{
	long double	ld;
	t_floatbits	floatbits;
}				t_float;

typedef struct	s_args
{
	int			spec_index;
	short		flag;
	int			width;
	int			precision;
	char		spec;
	int			modifier;
	char		*result;
	char		*mantiss;
	char		*fract;
	char		*decimal;
	t_ull		unsign_ed;
	t_float		u_nion;
}				t_args;

typedef struct	s_vars
{
	int			counter;
	va_list		types_list;
	char		*str;
	int			i;
	int			j;
	int			len1;
	int			len2;
	int			len;
	int			zeros;
	int			sign;
	char		*tmp;
	char		*elt;
	int			n;
	int			m;
	int			carry;
}				t_vars;

int				ft_printf(const char *format, ...);
int				get_specifier(t_args *args, t_vars *var);
void			get_flags(t_args *args, t_vars *var);
void			get_width(t_args *args, t_vars *var);
void			get_modifier(t_args *args, t_vars *var);
void			initialize_args(t_args *args);
void			pf_print_c(t_args *args, t_vars *var);
void			pf_print_d(t_args *args, t_vars *var);
void			pf_print_s(t_args *args, t_vars *var);
void			pf_print_f(t_args *args, t_vars *var);
void			pf_print_poubx(t_args *args, t_vars *var);
void			pf_width(t_args *args);
void			pf_precision(t_args *args);
char			*padd(char *element, int rest, char c, char side);
char			*pf_base(t_args *args);
char			*multiply_string(char *num1, char *num2, int c);
char			*pf_large_pow(t_ull power, char *radix);
char			*sum_string(char *num1, char *num2);
void			get_mantissa(t_args *args);
char			*is_roundable(t_args *args, int flen);
void			shipf_bits(char **conv, t_ull nbr, int mask, int shift);
void			split_float_parts(t_args *args);
void			join_dot_to_decimal(t_args *args);
int				manage_sign(t_args *args, int sign);
int				is_nan(t_args *args);
int				is_inf(t_args *args);
t_ull			pf_unsigned(t_args *args, t_vars *var);
t_ll			pf_signed(t_args *args, t_vars *var);
t_float			pf_float_length(t_args *args, t_vars *var);
char			*get_color(char *str, int begin, int end);
void			set_color(t_vars *var);

#endif

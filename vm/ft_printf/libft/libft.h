/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-men <ahel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 16:27:37 by aybouras          #+#    #+#             */
/*   Updated: 2021/04/01 11:35:42 by ahel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

typedef unsigned long long	t_ull;

int					pf_isdigit(int c);
size_t				pf_strlen(const char *s);
int					pf_strcmp(const char *s1, const char *s2);
char				*pf_strcpy(char *dst, const char *src);
char				*pf_strdup(const char *s1);
long long int		pf_atoll(const char *str);
int					pf_isspace(int c);
char				*pf_strcat(char *s1, const char *s2);
void				*pf_memset(void *b, int c, size_t len);
void				*pf_memcpy(void *dst, const void *src, size_t n);
void				pf_bzero(void *s, size_t n);
void				*pf_memalloc(size_t size);
void				pf_memdel(void **ap);
char				*pf_strnew(size_t size);
void				pf_strdel(char **as);
char				*pf_strsub(char const *s, unsigned int start, size_t len);
char				*pf_strjoin(const char *s1, const char *s2);
int					pf_putchar(char c);
int					pf_putstr(char const *s);
int					pf_islower(int c);
int					pf_isupper(int c);
char				*pf_ltoa(long long n);
void				pf_putnchar(char c, long n);
int					pf_contains(const char *set, char c);
char				*pf_strndup(const char *s, size_t times);
char				*pf_utoa(unsigned long long n);
int					pf_indexof(char *s, char c);
long				pf_abs(long nb);
char				*pf_strjoin_free(char *s1, char *s2);
void				pf_strupper(char *str);

#endif

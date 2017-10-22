/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:22:07 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/30 14:23:04 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "../../libft_functions/includes/libft.h"

# define TYPES "sSpdDiboOuUxXcCfFeEgG%RZm"
# define AN_SYS "bxXoO"
# define SINGLE "cCRZ%"
# define FLAGS " #0-+"
# define NL "(null)"

typedef struct	s_printf
{
	char		*flags;
	int			width;
	int			accuracy;
	char		modificator;
	char		type;
	void		*next;
}				t_printf;

int				abs(int d);
void			fill_type(t_printf **elem, int *i);
t_printf		*create_type(const char *type, int *i, va_list *ap);
int				flags(const char *type, int i, t_printf **elem, int flag);
int				int_w(const char *type, int i, t_printf **elem, va_list *ap);
int				int_a(const char *type, int i, t_printf **elem, va_list *ap);
int				help_modificators(const char *type, int i, t_printf **elem);
int				modificators(const char *type, int i, t_printf **elem);
char			*ft_encode(wchar_t c);
int				print_wchar(t_printf *elem, va_list *ap);
int				adress_acc(char *str, t_printf *elem);
int				print_adress(t_printf *elem, va_list *ap);
int				ft_putwchar(wchar_t c);
int				ft_putwchars(wchar_t *str);
int				first_str_wch(wchar_t *str, t_printf *elem, char c, int acc);
int				first_c_wch(wchar_t *str, t_printf *elem, char c, int acc);
int				create_spaces_wch(wchar_t *str, t_printf *elem);
void			first_str(char *str, t_printf *elem, char c, int acc);
void			first_c(char *str, t_printf *elem, char c, int acc);
void			create_spaces(char *str, t_printf *elem, char c, int flag);
int				print_string(t_printf *elem, va_list *ap);
int				print_char(t_printf *elem, va_list *ap, int flag);
int				ft_count(long long int value, int base);
int				ft_count_unsigned(unsigned long long int value, int base);
int				ft_count_test(intmax_t value, int base);
void			ft_putnbr_unsigned(unsigned long long int d);
char			*ft_itoa_base(long long int value, int base, int flag);
char			*ft_itoa_base_unsigned(unsigned long long int value,
									int base, int flag);
char			*ft_itoa_base_test(intmax_t value, int base, int flag);
int				print_hash(int d, t_printf *elem);
int				print_plus(int d, t_printf *elem);
int				count_plus(int d, t_printf *elem);
int				find_biggest(int len, int wid, int acc);
int				print_space(char **str, t_printf *elem, int wid, char c);
int				acc(t_printf *elem, char **str, int d);
void			help_int_width(t_printf *elem, char *str, int d, int len);
int				int_width(t_printf *elem, char *str, int d);
void			modific(long long int *d, t_printf *elem, va_list *ap);
int				print_int(t_printf *elem, va_list *ap);
char			*get_another_sys(t_printf *elem, unsigned long long int d);
int				print_another_system(t_printf *elem, va_list *ap);
void			modific_unsigned(unsigned long long int *d,
									t_printf *elem, va_list *ap);
int				print_int_unsigned(t_printf *elem, va_list *ap);
char			*ft_get_double(long double d, t_printf *elem);
char			*ft_get_double_e(long double d, t_printf *elem);
int				print_e(t_printf *elem, long double d, char *str, int ten);
int				print_double_e(t_printf *elem, va_list *ap);
int				print_double_short(t_printf *elem, va_list *ap);
int				ft_10pow(int d);
int				ft_intlen(long int d, int flag);
int				count_dig(char *str);
int				print_dob(char *str, t_printf *elem, long double d);
int				print_double(t_printf *elem, va_list *ap);
int				add_new(t_printf *elem, va_list *ap);
int				ft_find_per(va_list *ap, t_printf **elem, int *i, char *format);
int				ft_printf(const char *format, ...);
void			ft_putcolor(char *str);
int				ft_colors(char *str, int i);
void			text_example(void);
void			color_example(void);
void			usage(void);
void			free_elem(t_printf **elem, char **test);

void			print_memory1(t_printf *elem, va_list *ap);

#endif

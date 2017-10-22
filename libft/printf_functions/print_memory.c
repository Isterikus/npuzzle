/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:33:03 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/30 14:22:20 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_hex_byte(unsigned char b, int space, int space_after)
{
	char	octets[3];

	if (space)
		write(1, space_after ? "   " : "  ", space_after ? 3 : 2);
	else
	{
		if ((b >> 4) < 10)
			octets[0] = (b >> 4) + '0';
		else
			octets[0] = (b >> 4) + 'a' - 10;
		if ((b & 15) < 10)
			octets[1] = (b & 15) + '0';
		else
			octets[1] = (b & 15) + 'a' - 10;
		octets[2] = ' ';
		if (space_after == 1)
			write(1, octets, 3);
		else
			write(1, octets, 2);
	}
}

void	print_hex_bytes(const unsigned char *mem, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		print_hex_byte(mem[i], 0, i % 2);
		i++;
	}
	while (i < 16)
	{
		print_hex_byte(0, 1, i % 2);
		i++;
	}
}

void	print_memory(const void *addr, size_t size)
{
	size_t				i;
	size_t				count;
	const unsigned char	*mem;

	mem = (const unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			count = 16;
		else
			count = size - i;
		print_hex_bytes(mem + i, count);
		i += 16;
	}
}

void	print_memory1(t_printf *elem, va_list *ap)
{
	void	*adr;

	adr = va_arg(*ap, void *);
	print_memory(adr, elem->width);
}

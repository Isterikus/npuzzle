/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkovalen <dkovalen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 20:10:24 by dkovalen          #+#    #+#             */
/*   Updated: 2017/03/19 12:53:04 by dkovalen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putcolor(char *str)
{
	(ft_strcmp(str, "black") == 0) ? write(1, "\e[30m", 5) : 0;
	(ft_strcmp(str, "red") == 0) ? write(1, "\e[31m", 5) : 0;
	(ft_strcmp(str, "green") == 0) ? write(1, "\e[32m", 5) : 0;
	(ft_strcmp(str, "yellow") == 0) ? write(1, "\e[33m", 5) : 0;
	(ft_strcmp(str, "blue") == 0) ? write(1, "\e[34m", 5) : 0;
	(ft_strcmp(str, "magenta") == 0) ? write(1, "\e[35m", 5) : 0;
	(ft_strcmp(str, "cyan") == 0) ? write(1, "\e[36m", 5) : 0;
	(ft_strcmp(str, "d_gray") == 0) ? write(1, "\e[90m", 5) : 0;
	(ft_strcmp(str, "l_red") == 0) ? write(1, "\e[91m", 5) : 0;
	(ft_strcmp(str, "l_green") == 0) ? write(1, "\e[92m", 5) : 0;
	(ft_strcmp(str, "l_yellow") == 0) ? write(1, "\e[93m", 5) : 0;
	(ft_strcmp(str, "l_blue") == 0) ? write(1, "\e[94m", 5) : 0;
	(ft_strcmp(str, "bold") == 0) ? write(1, "\e[1m", 4) : 0;
	(ft_strcmp(str, "underlined") == 0) ? write(1, "\e[4m", 4) : 0;
	if (ft_strcmp(str, "eoc") == 0)
	{
		write(1, "\e[0m", 4);
		write(1, "\e[39m", 5);
		write(1, "\e[24m", 5);
	}
}

void	text_example(void)
{
	ft_putcolor("eoc");
	ft_putstr("\nAlso you can use such text decoration:\n");
	ft_putcolor("bold");
	ft_putstr("bold ");
	ft_putcolor("eoc");
	ft_putcolor("underlined");
	ft_putstr("underlined\n");
	ft_putcolor("eoc");
}

void	color_example(void)
{
	ft_putcolor("black");
	ft_putstr("black ");
	ft_putcolor("red");
	ft_putstr("red ");
	ft_putcolor("green");
	ft_putstr("green ");
	ft_putcolor("yellow");
	ft_putstr("yellow ");
	ft_putcolor("blue");
	ft_putstr("blue ");
	ft_putcolor("magenta");
	ft_putstr("magenta ");
	ft_putcolor("cyan");
	ft_putstr("cyan ");
	ft_putcolor("d_gray");
	ft_putstr("d_gray ");
	ft_putcolor("l_red");
	ft_putstr("l_red ");
	ft_putcolor("l_green");
	ft_putstr("l_green ");
	ft_putcolor("l_yellow");
	ft_putstr("l_yellow ");
	ft_putcolor("l_blue");
	ft_putstr("l_blue");
	text_example();
}

void	usage(void)
{
	ft_putcolor("bold");
	ft_putcolor("yellow");
	ft_putstr("ft_printf usage\n");
	ft_putcolor("eoc");
	ft_putstr("printf format [arguments ...]\n");
	ft_putstr("Everything as in printf man, exept of:\n");
	ft_putstr("You can't use conversions: ");
	ft_putcolor("red");
	ft_putstr("a A n");
	ft_putcolor("eoc");
	ft_putstr("\nYou can't use flags: ");
	ft_putcolor("red");
	ft_putstr("$ ’");
	ft_putcolor("eoc");
	ft_putstr("\nBut you can use conversation ");
	ft_putcolor("green");
	ft_putstr("%b");
	ft_putcolor("eoc");
	ft_putstr(" - to print binary.\nAlso you can use colors by using {}\n");
	ft_putstr("Example: {red}");
	ft_putcolor("red");
	ft_putstr("Red text");
	ft_putcolor("eoc");
	ft_putstr("{eoc}Colors that can be used:\n");
	color_example();
}

int		ft_colors(char *str, int i)
{
	char	*color;
	int		j;

	j = 0;
	while (str[i + j] != '}' && str[i + j] != '\0')
		j++;
	color = ft_strsub(str, i + 1, j - 1);
	if (ft_strcmp(color, "usage") == 0)
		usage();
	else
		ft_putcolor(color);
	ft_memdel((void **)&color);
	return (i + j + 1);
}

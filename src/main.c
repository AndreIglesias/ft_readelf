/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:32:16 by ciglesia          #+#    #+#             */
/*   Updated: 2021/07/01 18:15:26 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readelf.h"

static int	print_elf(t_elf *elf, char *obj)
{
	if (elf_header(elf, obj) == 0)
		return (0);
	print_header(*elf);
	if (elf_pheader(elf, obj) == 0)
		return (0);
	ft_printf("\n");
	print_pheader(*elf);
	return (1);
}

static void	ft_readelf(char *obj, int nparams)
{
	t_elf	elf;
	int		err;

	elf.obj = obj;
	err = elf_ident(&elf, obj);
	if (err > 0)
	{
		elf.class = elf.identifier[EI_CLASS];
		if (nparams)
			ft_printf(CEL"%s:\n"E0M, elf.obj);
		if (print_elf(&elf, obj))
			return ;
	}
	if (!err)
		ft_printf_fd(2, "ft_readelf: '%s': file format not recognized\n", obj);
}

/*
**	readelf -a --all options
*/
#include <stdio.h>
int	main(int ac, char **av)
{
	int		i;

	printf("%d\n", _Generic(1L, float :1, double :2, long double :3,
			default :0));
	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (av[i][0] != '-')
				ft_readelf(av[i], ac - 1);
			i++;
		}
	}
	else
	{
		ft_printf(CEL"Usage:"COLOR_E0M" readelf "GREEN"<elf-file(s)>\n"E0M);
		ft_printf("Display "BOLD"all"E0M" the information about the contents ");
		ft_printf("of ELF format files\n");
	}
	return (EXIT_SUCCESS);
}

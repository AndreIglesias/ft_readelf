/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:32:16 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 20:26:18 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readelf.h"

static void	print_elf(t_elf *elf)
{
	print_header(*elf);
}

static void	ft_readelf(char *obj, int nparams)
{
	t_elf	elf;
	int		err;

	elf.obj = obj;
	err = elf_ident(&elf, obj);
	if (!err)
		ft_printf_fd(2, "ft_readelf: '%s': file format not recognized\n", obj);
	else if (err < 0)
		ft_printf_fd(2, "ft_readelf: '%s': No such file\n", obj);
	else
	{
		elf.class = elf.identifier[EI_CLASS];
		if (nparams)
			ft_printf(CEL"%s:\n"E0M, elf.obj);
		err = elf_header(&elf, obj);
		if (!err)
			ft_printf_fd(2, "ft_readelf: '%s': file format not recognized\n", obj);
		else if (err < 0)
			ft_printf_fd(2, "ft_readelf: '%s': No such file\n", obj);
		else
			print_elf(&elf);
	}
}

/*
**	readelf -a --all options
*/

int	main(int ac, char **av)
{
	int		i;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 22:32:16 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 18:46:50 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readelf.h"

static int	elf_header(t_elf *elf)
{
	if ((elf->fd = open(elf->obj, O_RDONLY)) < 0)
	{
		ft_printf_fd(2, "ft_readelf: '%s': No such file\n", elf->obj);
		return (0);
	}
	if (elf->class == ELFCLASS32)
	{
		if (ft_read(elf->fd, &elf->elf_32, sizeof(elf->elf_32))
							< (ssize_t)sizeof(elf->elf_32))
		{
			close(elf->fd);
			return (0);
		}
	}
	else
	{
		if (ft_read(elf->fd, &elf->elf_64, sizeof(elf->elf_64))
							< (ssize_t)sizeof(elf->elf_64))
		{
			close(elf->fd);
			return (0);
		}
	}
	close(elf->fd);
	return (1);
}

static void	ft_readelf(char *obj, int nparams, int h)
{
	t_elf	elf;
	int		err;

	elf.obj = obj;
	err = elf_ident(&elf, obj);
	if (!err)
	{
		ft_printf_fd(2, "ft_readelf: '%s': file format not recognized\n", obj);
		return ;
	}
	else if (err < 0)
	{
		ft_printf_fd(2, "ft_readelf: '%s': No such file\n", obj);
		return ;
	}
	elf.class = elf.identifier[EI_CLASS];
	if (nparams)
		ft_printf("%s:\n", elf.obj);
	if (elf_header(&elf) && h)
		print_header(elf);
	else
		ft_printf("invalid header!!!!!\n");
}

int	main(int ac, char **av)
{
	char	*obj;
	int		i;
	int		h;

	h = 0;
	i = 1;
	while (i < ac)
		h += (ft_strcmp(av[i++], "-h") == 0);
	obj = (ac == 1) ? "a.out" : av[1];
	ft_readelf(obj, ac - 1, h > 0);
	i = 2;
	while (i < ac)
	{
		if (av[i][0] != '-')
			ft_readelf(av[i], ac - 1, h > 0);
		i++;
	}
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_program_header.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:35:00 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 01:30:26 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readelf.h"

void	print_pheader(t_elf elf)
{
	ft_printf("Program Headers:\n");
	ft_printf("  Type           Offset             VirtAddr           PhysAddr\n");
	ft_printf("                 FileSiz            MemSiz              Flags  Align\n");
	(void)elf;
}

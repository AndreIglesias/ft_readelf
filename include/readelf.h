/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readelf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:36:07 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 01:25:30 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READELF_H
# define READELF_H

# include "libelf.h"
# include "libstd.h"
# include "libstring.h"

/*
**	Display
*/

void		print_header(t_elf elf);
void		print_pheader(t_elf elf);

#endif

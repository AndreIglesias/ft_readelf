/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readelf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:36:07 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 18:45:48 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READELF_H
# define READELF_H

# include "libelf.h"
# include "libstd.h"
# include "libstring.h"
# include <stdio.h>
# include <stdlib.h>
# include <linux/elf.h>
# include <fcntl.h>

/*
**	Display
*/

void		print_header(t_elf elf);

#endif

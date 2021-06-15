#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 22:37:03 by ciglesia          #+#    #+#              #
#    Updated: 2021/06/15 15:09:45 by ciglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

DEPENDENCIES = Makefile libstring/Makefile libstd/Makefile libELF/Makefile

ECHO		=	/bin/echo -e

.SUFFIXES:

all:	$(DEPENDENCIES)
		@$(MAKE) -C libstring/
		@$(MAKE) -C libstd/
		@$(MAKE) -C libELF/

clean:
		@$(MAKE) -C libstring/ clean
		@$(MAKE) -C libstd/ clean
		@$(MAKE) -C libELF/ clean

fclean:	clean
		@$(MAKE) -C libstring/ fclean
		@$(MAKE) -C libstd/ fclean
		@$(MAKE) -C libELF/ fclean

re:
		@$(ECHO) "Recompiling"
		@$(MAKE) fclean
		@$(MAKE) all

.PHONY: clean fclean all re

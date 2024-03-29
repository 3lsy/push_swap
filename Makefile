#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 11:47:33 by echavez-          #+#    #+#              #
#    Updated: 2023/06/24 13:39:17 by echavez-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME        =   push_swap

BONUS		=	checker

#****************** INC *******************#
# General
INC         =   ./include/                  # Project header files drectory

# Libft
LIB         =   ./libft/                    # Library to include
LIB_H       =   ./libft/                    # Library header files directory

INCLUDE     =   -O3 -I $(LIB_H) -I $(INC)   # Header files

LIB_INC     =   -L$(LIB_H) -lft             # Include library

#****************** SRC *******************#

DIRSRC      =   ./src/
DIRFOO      :=  #$(DIRSRC)/foo/

DIRS        :=  $(DIRSRC) $(DIRFOO)

SRC         =   main.c analyzer.c list.c sort.c decisions.c op.c search.c mini_sort.c limits.c
FOO         =   checker.c checker_exec.c analyzer.c list.c sort.c decisions.c op.c search.c mini_sort.c limits.c

SRCS        :=  $(SRC)

#***************** DEPS ******************#

DIROBJ      =   ./depo/

#********************************* END OF CONFIG *********************************#

OAUX        =   $(SRCS:%=$(DIROBJ)%)
DEPS        =   $(OAUX:.c=.d)
OBJS        =   $(OAUX:.c=.o)

BOAUX       =   $(FOO:%=$(DIROBJ)%)
BDEPS       =   $(BOAUX:.c=.d)
BOBJS       =   $(BOAUX:.c=.o)

.ONESHELL:

$(info Creating directory...)
$(shell mkdir -p $(DIROBJ))

ifdef FLAGS
    ifeq ($(FLAGS), no)
CFLAGS      =
    endif
    ifeq ($(FLAGS), debug)
CFLAGS      =   -Wall -Wextra -Werror -ansi -pedantic -g
    endif
else
CFLAGS      =   -Wall -Wextra -Werror
endif

ifdef VERB
    ifeq ($(VERB), on)
CFLAGS      +=  -DM_VERB
    endif
endif

ifndef VERBOSE
.SILENT:
endif

ENV         =   /usr/bin/env
CC          =   $(ENV) clang
RM          =   $(ENV) rm -rf
ECHO        =   $(ENV) echo -e
MKDIR       =   $(ENV) mkdir -p
GIT         =   $(ENV) git
BOLD        =   "\e[1m"
REVER       =   "\e[7m"
BLINK       =   "\e[5m"
RED         =   "\e[38;2;255;0;0m"
GREEN       =   "\e[92m"
BLUE        =   "\e[34m"
YELLOW      =   "\e[33m"
E0M         =   "\e[0m"

FMT         :=  $(REVER)$(YELLOW)$(BLINK)

#******************************* DEPS COMPILATION ********************************#

%.o             :   $(foreach dir,$(DIRS),../$(dir)/%.c)
	                @printf $(GREEN)"Generating "$(NAME)" objects... %-33.33s\r"$(E0M) $@
	                @$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#******************************* MAIN COMPILATION ********************************#

$(NAME)         :   ftlib $(OBJS)
	                @$(CC) $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_INC)
	                @$(ECHO)
	                @$(ECHO) '                       '$(FMT)'██████'$(E0M)
	                @$(ECHO) '                   '$(FMT)'████░░░░░░██'$(E0M)
	                @$(ECHO) '                 '$(FMT)'██░░░░░░░░██'$(E0M)
	                @$(ECHO) '               '$(FMT)'██░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '             '$(FMT)'██░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '           '$(FMT)'██░░░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '           '$(FMT)'██░░░░░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '   '$(FMT)'████████░░░░░░░░░░░░░░░░░░░░░░░░████████'$(E0M)
	                @$(ECHO) ' '$(FMT)'██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) ' '$(FMT)'██▓▓░░░░░░░░░░░░  ██░░░░  ██░░░░░░░░░░░░▓▓██'$(E0M)
	                @$(ECHO) '   '$(FMT)'██▓▓░░░░░░░░░░████░░░░████░░░░░░░░░░▓▓██'$(E0M)
	                @$(ECHO) '     '$(FMT)'██▓▓░░░░░░░░████░░░░████░░░░░░░░▓▓██'$(E0M)
	                @$(ECHO) '       '$(FMT)'██░░░░░░░░▓▓██░░░░██▓▓░░░░░░░░██'$(E0M)
	                @$(ECHO) '       '$(FMT)'██░░░░░░░░░░░░░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '       '$(FMT)'██░░░░░░░░░░░░░░░░░░░░░░░░░░░░██'$(E0M)
	                @$(ECHO) '       '$(FMT)'██▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓██'$(E0M)
	                @$(ECHO) '       '$(FMT)'██▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓██'$(E0M)
	                @$(ECHO) '         '$(FMT)'██░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░██'$(E0M)
	                @$(ECHO) '         '$(FMT)'██▓▓░░▓▓████████████▓▓░░▓▓██'$(E0M)
	                @$(ECHO) '           '$(FMT)'██▓▓██'$(E0M)'            '$(FMT)'██▓▓██'$(E0M)
	                @$(ECHO) '             '$(FMT)'██'$(E0M)'                '$(FMT)'██'$(E0M)
	                @$(ECHO) $(E0M)

	                @$(ECHO) $(BOLD)$(GREEN)'> '$(NAME)' Compiled'$(E0M)

bonus			:	ftlib $(BOBJS)
					@$(CC) $(INCLUDE) $(CFLAGS) -o $(BONUS) $(BOBJS) $(LIB_INC)
	                @$(ECHO) $(BOLD)$(GREEN)'> '$(BONUS)' Compiled'$(E0M)

clean           :
	                @($(RM) $(OBJS))
					@($(RM) $(BOBJS))
	                @($(RM) $(DEPS))
	                @($(RM) $(DIROBJ))
	                @(cd $(LIB) && $(MAKE) clean)
	                @$(ECHO) $(BOLD)$(RED)'> '$(NAME)' directory        cleaned'$(E0M)

all             :  $(NAME)

fclean          :  clean
	                @$(RM) $(NAME)
					@$(RM) $(BONUS)
	                @(cd $(LIB) && $(MAKE) fclean)
	                @$(ECHO) $(BOLD)$(RED)'> Executable             removed'$(E0M)

re              :  fclean mkdepo all

mkdepo			:
					mkdir -p $(DIROBJ)

ftlib           :
	                @(cd $(LIB) && $(MAKE))

init            :
	                @$(GIT) submodule init
	                @$(GIT) submodule update

.PHONY          :  all clean re fclean ftlib

-include $(DEPS)

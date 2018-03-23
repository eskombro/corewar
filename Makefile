# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 15:09:24 by hbouillo          #+#    #+#              #
#    Updated: 2018/03/23 22:44:13 by hbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include Makefile.inc

# COMPILATION VARIABLES
CC = clang

# TARGET 1
TARGET_1 = corewar
SRC_1 = vm/main.c \
	vm/debug.c \
	\
	vm/champ/get_champ.c \
	vm/champ/get_spawn.c \
	\
	vm/memory/gestion_memoire.c \
	vm/memory/write_champ.c \
	\
	vm/logic/logic.c \
	vm/logic/lives.c \
	vm/logic/instr/filler.c \
	vm/logic/instr/instructions.c \
	vm/logic/process/process.c \
	\
	vm/instr/add.c \
	vm/instr/aff.c \
	vm/instr/and.c \
	vm/instr/fork.c \
	vm/instr/ld.c \
	vm/instr/ldi.c \
	vm/instr/lfork.c \
	vm/instr/live.c \
	vm/instr/or.c \
	vm/instr/st.c \
	vm/instr/sti.c \
	vm/instr/sub.c \
	vm/instr/xor.c \
	vm/instr/zjmp.c \
	vm/instr/write_read_reg.c \
	\
	vm/display/verbose.c \
	vm/display/load.c \
	vm/display/spe_instr.c \
	vm/display/store.c \
	vm/display/bin_op.c \
	vm/ncurse/visual.c

OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))
CFLAGS_1 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-Iinc \
	-Ilib/inc
LFLAGS_1 = $(DEBUG_FLAGS) \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lft \
	-lncurses

all: prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1)
	@echo > /dev/null

$(TARGET_1): $(OBJ_1)
	$(call link, $(LFLAGS_1))

prebuild.$(TARGET_1):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C libft
	$(call dylib_install,./libft/lib/libft.dylib)
	$(call dylib_include_install,./libft/inc)
	$(call bgn_msg,$(TARGET_1))

postbuild.$(TARGET_1):
	$(call $(END_MSG),$(TARGET_1))

$(OBJ_1): ./obj/%.o: %.c
	$(call compile, $(CFLAGS_1))

clean:
	@$(MAKE) -C libft clean
	$(call clean,$(TARGET_1),$(OBJ_1))

fclean:
	@$(MAKE) -C libft fclean
	$(call fclean,$(TARGET_1),$(OBJ_1))

libclean:
	@$(MAKE) -C libft libclean
	@rm -rf ./lib

re: fclean all

.PHONY: all clean fclean \
	prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) postbuild.$(TARGET_2)

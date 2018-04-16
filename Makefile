# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbouillo <hbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/14 15:09:24 by hbouillo          #+#    #+#              #
#    Updated: 2018/04/16 04:38:22 by sjimenez         ###   ########.fr        #
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
	vm/memory/dump.c \
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
	\
	vm/ncurse/arena_visu.c \
	vm/ncurse/display.c \
	vm/ncurse/visual.c \
	\
	vm/callers/process_callers.c \
	vm/callers/memory_callers.c \
	vm/callers/logic_callers.c \
	vm/callers/instr_callers.c \
	vm/callers/champ_callers.c \
	vm/callers/core_callers.c \
	\
	vm/commands/commands.c \
	vm/commands/command_writers.c \
	vm/commands/command_readers.c

OBJ_1 = $(addprefix obj/src/,$(SRC_1:.c=.o))
CFLAGS_1 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-Iinc \
	-Iinc/common \
	-Ilib/inc
LFLAGS_1 = $(DEBUG_FLAGS) \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lft \
	-lncurses

# TARGET 2
TARGET_2 = show_corewar
SRC_2 = visu/main.c \
	visu/visu.c \
	visu/error.c \
	visu/debug.c \
	\
	visu/gui/gui.c \
	visu/gui/colors.c \
	visu/gui/scene/main/main_scene.c \
	visu/gui/scene/main/main_components.c \
	\
	visu/event/events.c \
	visu/event/key/key_event.c \
	visu/event/command/command_event.c \
	\
	visu/reader/reader.c \
	\
	visu/commands/commands.c \
	visu/commands/command_writers.c \
	visu/commands/command_readers.c
OBJ_2 = $(addprefix obj/src/,$(SRC_2:.c=.o))
CFLAGS_2 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-I$(LIBS_PATH)/include/freetype2 \
	-Iinc/visu \
	-Iinc/common \
	-Iinc \
	-Ilib/inc
LFLAGS_2 = $(DEBUG_FLAGS) \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lft \
	-lSDL2 \
	-lsimplegui \
	-lfreetype \
	-framework OpenGL

# TARGET 3
TARGET_3 = show_corewar_ncurse
SRC_3 = nvisu/main.c \
	nvisu/communication_corewar.c \
	nvisu/print_modules.c \
	nvisu/handle_callers/handle_champ_callers.c \
	nvisu/handle_callers/handle_core_callers.c \
	nvisu/handle_callers/handle_logic_callers.c \
	nvisu/handle_callers/handle_memory_callers.c \
	nvisu/handle_callers/handle_process_callers.c \
	nvisu/handle_callers/process_display.c \
	nvisu/free_all.c \
	nvisu/initialize_ncurses.c \
	nvisu/test_char.c \
	nvisu/display_shortcuts.c \
	\
	nvisu/commands/commands.c \
	nvisu/commands/command_writers.c \
	nvisu/commands/command_readers.c
OBJ_3 = $(addprefix obj/src/,$(SRC_3:.c=.o))
CFLAGS_3 = $(DEBUG_FLAGS) \
	-I$(LIBS_PATH)/include \
	-Iinc/nvisu \
	-Iinc/common \
	-Iinc \
	-Ilib/inc
LFLAGS_3 = $(DEBUG_FLAGS) \
	-L$(LIBS_PATH)/lib \
	-Llib \
	-lft \
	-lncurses

all: prebuild.$(TARGET_1) $(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) $(TARGET_2) postbuild.$(TARGET_2) \
	prebuild.$(TARGET_3) $(TARGET_3) postbuild.$(TARGET_3)
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

$(TARGET_2): $(OBJ_2)
	$(call link, $(LFLAGS_2))

prebuild.$(TARGET_2):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C libft
	@$(MAKE) -C simple-gui
	$(call dylib_install,./simple-gui/lib/libsimplegui.dylib)
	$(call dylib_include_install,./simple-gui/lib/inc)
	$(call dylib_include_install,./simple-gui/inc)
	$(call dylib_install,./libft/lib/libft.dylib)
	$(call dylib_include_install,./libft/inc)
	$(call bgn_msg,$(TARGET_2))

postbuild.$(TARGET_2):
	$(call $(END_MSG),$(TARGET_2))

$(OBJ_2): ./obj/%.o: %.c
	$(call compile, $(CFLAGS_2))

$(TARGET_3): $(OBJ_3)
	$(call link, $(LFLAGS_3))

prebuild.$(TARGET_3):
	@mkdir -p lib
	@mkdir -p lib/inc
	@$(MAKE) -C libft
	$(call dylib_install,./libft/lib/libft.dylib)
	$(call dylib_include_install,./libft/inc)
	$(call bgn_msg,$(TARGET_3))

postbuild.$(TARGET_3):
	$(call $(END_MSG),$(TARGET_3))

$(OBJ_3): ./obj/%.o: %.c
	$(call compile, $(CFLAGS_3))

clean:
	@$(MAKE) -C libft clean
	@$(MAKE) -C simple-gui clean
	$(call clean,$(TARGET_1),$(OBJ_1))
	$(call clean,$(TARGET_2),$(OBJ_2))
	$(call clean,$(TARGET_3),$(OBJ_3))

fclean:
	@$(MAKE) -C libft fclean
	@$(MAKE) -C simple-gui fclean
	$(call fclean,$(TARGET_1),$(OBJ_1))
	$(call fclean,$(TARGET_2),$(OBJ_2))
	$(call fclean,$(TARGET_3),$(OBJ_3))

libclean:
	@$(MAKE) -C libft libclean
	@$(MAKE) -C simple-gui libclean
	@rm -rf ./lib

re: fclean all

.PHONY: all clean fclean \
	prebuild.$(TARGET_1) postbuild.$(TARGET_1) \
	prebuild.$(TARGET_2) postbuild.$(TARGET_2) \
	prebuild.$(TARGET_3) postbuild.$(TARGET_3)

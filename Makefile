################################################################################
### MACROS
################################################################################

# $(1) : Compiler
# $(2) : Object file to generate
# $(3) : Source file
# $(4) : Compiler flags
define COMPILER
$(2) : $(3)
	$(1) -c $(4) -o $(2) $(3)
endef

# $(1) : Source file
define C2O
$(patsubst %.c,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1)))
endef

# $(1) : Source file
define CL2O
$(patsubst %.c,%.o,$(1))
endef

# $(1) : Source file
define C2H
$(patsubst %.c,%.h,$(1))
endef

################################################################################
### CONFIG
################################################################################
#-fsanitize=address
NAME		= minishell
NAMEMAIN	= a.out
CFLAGS		= -Wall -Werror -Wextra -g
ARFLAGS		= -crs
C			= gcc
MKDIR		= mkdir -p
SRC			= src
OBJ			= obj
ALLCS		= $(shell find $(SRC) -type f -iname "*.c")
ALLCSLIBS	= $(shell find $(LIBDIR) -type f -iname "*.c")
ALLCOBJS	= $(foreach F,$(ALLCS),$(call C2O,$(F)))
ALLCOBJSLIBS= $(foreach F,$(ALLCSLIBS),$(call CL2O,$(F)))
SUBDIRS 	= $(shell find $(SRC) -type d)
OBJSUBDIRS	= $(patsubst $(SRC)%,$(OBJ)%,$(SUBDIRS))
LIBPRINTF	= $(SRC)/printf/ft_printf.h
MAIN		= main.c
LIBDIR		= lib
LIBS		= $(LIBDIR)/libft/libft.a $(LIBDIR)/get_next_line/get_next_line.a $(LIBDIR)/minilibx_opengl_20191021/libmlx.a
INCDIRS		= -I$(SRC) -I$(LIBDIR)
INCDIRS2	= $(INCDIRS) -lmlx -framework OpenGL -framework AppKit

################################################################################
### RULES
################################################################################

# Entrada por defecto
all			:	$(NAME)

# Entrada para el bonus
bonus		:	$(NAME)

# Genera programa Cube3d
$(NAME)	:	$(OBJSUBDIRS) $(LIBS) $(ALLCOBJS)
	$(C) $(CFLAGS) $(INCDIRS2) -o $(NAME) $(ALLCOBJS) $(LIBS)

# Generate rules for all objects
$(foreach F,$(ALLCS), $(eval $(call COMPILER,$(C),$(call C2O,$(F)),$(F),$(CFLAGS) $(INCDIRS))))
$(foreach F,$(ALLCSLIBS), $(eval $(call COMPILER,$(C),$(call CL2O,$(F)),$(F),$(CFLAGS) $(INCDIRS))))

# Compila librerias
$(LIBS)		:
	$(MAKE) -C $(LIBDIR)

# clean librerias
libs-clean:
	$(MAKE) -C $(LIBDIR) clean

# fclean librerias
libs-fclean:
	$(MAKE) -C $(LIBDIR) fclean

# Crea arbol de carpetas
$(OBJSUBDIRS):
	$(MKDIR) $(OBJSUBDIRS)

# limpia los .o
clean		:
	@echo Delete all objects
	@rm -f $(ALLCOBJS)
	@rm -f $(ALLCOBJSLIBS)
	@rm -f *.gch

# Elimina los .o y el ejecutable
fclean		: clean libs-fclean
	@echo Delete program
	@rm -f $(NAME)
	@rm -f $(NAMEMAIN)

re			: fclean all 

.PHONY		: LIBS clean fclean re
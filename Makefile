PROGNAME = push_swap

#	Folders
SRC_DIR = src
INC_DIR = include

#	Dir library
LIBFT_DIR = lib_c/libft
# PRINTF_DIR = lib_c/ft_printf

#	library name
LIBFT = $(LIBFT_DIR)/libft.a
# PRINTF = $(PRINTF_DIR)/ft_printf.a

#	Compiler & flags
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
INC_FLAGS = -I$(INC_DIR)

#	source files
SRCS = 	primitive_operations.c \
		basic_operations.c \
		basic_operations_bis.c \
		push_swap.c \
		ft_parse.c \
		sort_list.c \
    	ft_utils.c \
		ft_utils2.c \
		valid_sintax.c \
		ft_s_swap.c \
		ft_rotate.c \
    	ft_mix_rot.c \
		ft_rev_rotate.c \
		ft_find_dist_in_b.c \
		node_to_move.c

# Objetivos predeterminados
all : $(LIBFT) $(PRINTF) $(PROGNAME)

# Rule for libft
$(LIBFT) :
	@ $(MAKE) -C $(LIBFT_DIR)

# # Rule for ft_printf 
# $(PRINTF) : $(LIBFT)
# 	@ $(MAKE) -C $(PRINTF_DIR)

# Archivos objeto
OBJS := $(SRCS:%.c=$(SRC_DIR)/%.o)

# Rules
all: $(PROGNAME)

$(PROGNAME): $(OBJS) $(LIBFT) #$(PRINTF)
	@ $(CC) $(CFLAGS) $(INC_FLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@ $(CC) $(CFLAGS) $(INC_FLAGS) -c -o $@ $<

# Cleanning
clean :
	@ $(MAKE) -C $(LIBFT_DIR) clean
# @ $(MAKE) -C $(PRINTF_DIR) clean
	@ rm -f $(OBJS)

fclean : clean
	@ $(MAKE) -C $(LIBFT_DIR) fclean
# @ $(MAKE) -C $(PRINTF_DIR) fclean
	@ rm -f $(PROGNAME)

re: fclean all

.PHONY: all clean fclean re
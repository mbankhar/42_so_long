NAME	:= so_long
LIBMLX	:= ./MLX42
ADOT	:= ./MLX42/build/libmlx42.a

LIBFT	:= libft
HEADERS	:= -I $(LIBMLX)/include/MLX42
INCLUDES := -I $(LIBFT)
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT_LIB	:= $(LIBFT)/libft.a
SRCS	:= so_long.c  parse_map.c error_check.c display.c movements.c \
gamerules.c so_long_utils.c make_monster_move.c
OBJS	:= ${SRCS:.c=.o}

CFLAGS	:= -Wextra -Wall -Werror -g

all: $(ADOT) $(NAME)

libmlx:
	mkdir -p $(LIBMLX)/build
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) $(INCLUDES) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(OBJS) -Llibft -LMLX42 -lft $(LIBS) $(HEADERS) $(INCLUDES) -o $(NAME)

$(ADOT): $(LIBMLX)
	mkdir -p $(LIBMLX)/build
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(LIBMLX) : 
	touch .gitmodules
	git submodule add -f https://github.com/codam-coding-college/MLX42.git

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBFT)/*.o

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/*.a

re: clean all

.PHONY: all, clean, fclean, re, libmlx

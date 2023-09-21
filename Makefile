CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = ft_2d_malloc.c \
	  ft_xpm_add_colour.c \
	  ft_xpm_convert_file.c \
	  ft_xpm_destroy.c \
	  ft_xpm_int_convert_utils.c \
	  ft_xpm_int_colour.c \
	  ft_xpm_int_load_file.c \
	  ft_xpm_int_pos_strstr.c \
	  ft_xpm_int_str_wordtab.c \
	  ft_xpm_new.c \
	  ft_xpm_put_imgdata.c

OBJ = $(patsubst %.c, obj/%.o, $(SRC))

.PHONY = all createdir main clean

all: createdir $(OBJ)

createdir:
	@mkdir -p obj

obj/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

main: main.c
	@$(CC) $(CFLAGS) main.c $(OBJ)

clean:
	@rm -rf obj/

re: clean all

NAME = prog

CC = clang
CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRC = $(wildcard ./*.c)

HDR = typeft.h \
	  xpmft.h \
	  xpmft_int.h

OBJ_DIR = obj

OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY = all clean fclean re create_dir

all: create_dir $(OBJ)
	@$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME) $(DEBUG_1) $(DEBUG_2)

re: clean all


create_dir:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c $(HDR) 
	@$(CC) $(CFLAGS) -c $< -o $@

##########################################
#                                        #
#                 TESTER                 #
#                                        #
##########################################

.PHONY += debug1 debug2

DEBUG_1 = prog_debug_1
DEBUG_2 = prog_debug_2

TESTER_1 = tester_1.c
TESTER_2 = tester_2.c

DEBUG_HDR = xpm_debug.h

OBJ_DEBUG_1 = $(patsubst %.c, $(OBJ_DIR)/%_d1.o, $(SRC))
OBJ_DEBUG_2 = $(patsubst %.c, $(OBJ_DIR)/%_d2.o, $(SRC))

debug1: DEBUG_LEVEL := 1
debug1: create_dir $(HDR) $(DEBUG_HDR) $(OBJ_DEBUG_1) $(DEBUG_1)

debug2: DEBUG_LEVEL := 2
debug2: create_dir $(HDR) $(DEBUG_HDR) $(OBJ_DEBUG_2) $(DEBUG_2)

$(OBJ_DEBUG_1): $(HDR) $(DEBUG_HDR)
	@$(CC) $(CFLAGS) -DDEBUG=$(DEBUG_LEVEL) -include $(DEBUG_HDR) \
	-c $(notdir $(@:_d1.o=.c)) -o $@

$(OBJ_DEBUG_2): $(HDR) $(DEBUG_HDR)
	@$(CC) $(CFLAGS) -DDEBUG=$(DEBUG_LEVEL) -include $(DEBUG_HDR) \
	-c $(notdir $(@:_d2.o=.c)) -o $@

$(DEBUG_1): $(TESTER_1) $(OBJ_DEBUG_1)
	@$(CC) $(CFLAGS) -DDEBUG=$(DEBUG_LEVEL) -include $(DEBUG_HDR) \
	$(TESTER_1) $(OBJ_DEBUG_1) -o $(DEBUG_1)

$(DEBUG_2): $(TESTER_2) $(OBJ_DEBUG_2)
	@$(CC) $(CFLAGS) -DDEBUG=$(DEBUG_LEVEL) -include $(DEBUG_HDR) \
	$(TESTER_2) $(OBJ_DEBUG_2) -o $(DEBUG_2)

#debug3: CFLAGS += -DDEBUG=3
#debug3: create_dir $(HDR) $(OBJ_DEBUG3)
#	@$(CC) $(CFLAGS) main.c $(OBJ_DEBUG3) -o $(DEBUG3)

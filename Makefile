NAME	=pipex

INCD	=include
SRCD	=src
OBJD	=obj
LIBFTD	=libft

CFLAGS	=-Wall -Wextra -Werror
CC		=cc $(CFLAGS)

SRC 	=$(SRCD)/main.c \
$(SRCD)/m_utils1.c \

OBJ		=$(OBJD)/main.o \

LIBFT	=$(LIBFTD)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(OBJ) -L$(LIBFTD) -lft -I$(INCD) -o $@

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	$(CC) -I$(INCD) -o $@ -c $<

$(OBJD):
	mkdir -p $(OBJD)

$(LIBFT):
	make -C $(LIBFTD)

clean: 
	rm -rf $(OBJD)
	make -C $(LIBFTD) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all

.PHONY: all clean fclean re

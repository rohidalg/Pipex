NAME = pipex

MKL = make -s -C libft
MK = make -s
MKD = mkdir -p
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g3

HEADERS =  libft/libft.h \
			pipex.h \

INCLUDES = -I libft

SRCs = pipex.c \
		ft_utils.c


DIR_OBJs = OBJECTS

OBJs = $(addprefix $(DIR_OBJs)/,$(SRCs:%.c=%.o))

all: dir_lib $(NAME)

$(NAME): $(OBJs)
	$(CC) $(CFLAGS) $(OBJs) libft/libft.a -o $(NAME)

$(DIR_OBJs)/%.o: %.c | $(DIR_OBJs)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(DIR_OBJs):
	$(MKD) $(DIR_OBJs)

dir_lib: libft/libft.a

libft/libft.a:
	$(MKL)

clean:
	$(MK) fclean -C libft
	$(RM) $(DIR_OBJs)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: 
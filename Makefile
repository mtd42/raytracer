# **************************************************************************** #
#                                                                              #
#                                                             #                #
#    Filename: Makefile                                      ###               #
#                                                           #####              #
#    By: mtd42 <https://github.com/mtd42>                  #     #             #
#                                                         ###   ###            #
#    Created: 2018/05/27 21:30:17 by mtd42               ##### #####           #
#    Updated: 2018/05/27 21:37:57 by mtd42        May the force be with you    #
#                                                                              #
# **************************************************************************** #

CC		= gcc

RM		= rm -f

NAME		= rt

SRC		= src/cone.c \
		  src/cylinder.c \
		  src/get_color.c \
		  src/get_cos.c \
		  src/init_objects.c \
		  src/image.c \
		  src/light.c \
		  src/misc.c \
		  src/main.c \
		  src/plan.c \
		  src/rotate.c \
		  src/shadow2.c \
		  src/shadow.c \
		  src/sphere.c

OBJ		= $(SRC:.c=.o)

CFLAGS		= -I./include -W -Wall -Wextra

MLX		= -L /usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

$(NAME):	$(OBJ)

		@echo -e "\n\x1b[34mCompiling...\n\033[00m"
		$(CC) -o $(NAME) $(OBJ) $(MLX)

		@echo -e "\n\x1b[32mProgram compiled !\n\033[00m"

all:		$(NAME)

clean:
		@echo -e "\n\x1b[34mRemoving objects...\n\033[00m"
		$(RM) $(OBJ)

		@echo -e "\n\x1b[32mObjects removed !\n\033[00m"

fclean:		clean

		@echo -e "\n\x1b[34mRemoving binary...\n\033[00m"
		$(RM) $(NAME)

		@echo -e "\n\x1b[32mBinary removed !\n\033[00m"

re:		fclean all

.PHONY:		all clean fclean re

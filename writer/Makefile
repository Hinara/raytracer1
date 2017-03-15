##
## Makefile for bsq in /home/robin.milas/Current/CPE_2016_BSQ
## 
## Made by Robin MILAS
## Login   <robin.milas@epitech.net>
## 
## Started on  Mon Dec  5 18:52:38 2016 Robin MILAS
## Last update Mon Mar 13 18:03:15 2017 Milas Robin
##

CC	=	gcc

SRCS	=	src/main.c			\
		src/free.c			\
		src/ask.c			\
		src/utils.c			\
		src/reader.c			\
		src/writer.c			\
		src/builtin.c			\
		src/builtin_print.c		\
		src/builtin_add.c		\
		src/builtin_remove.c		\
		src/get_float.c			\
		src/get_color.c			\
		src/get_nbr.c			\
		src/print_float.c		\
		src/lib/get_next_line.c		\
		src/lib/my_str_to_wordtab.c	\
		src/lib/my_strlen.c		\
		src/lib/my_strcmp.c		\
		src/lib/my_strdup.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	writer

CFLAGS	=	-Wall -Wextra -Werror -pedantic -I./include

LD_FLAGS =	-lc_graph_prog

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LD_FLAGS)

clean	:
		rm -fr $(OBJS)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all

.PHONY	:	all re fclean clean

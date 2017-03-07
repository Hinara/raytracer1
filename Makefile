##
## Makefile for navy in /home/robin.milas/Current/PSU_2016_navy
## 
## Made by Robin MILAS
## Login   <robin.milas@epitech.net>
## 
## Started on  Mon Dec  5 18:52:38 2016 Robin MILAS
## Last update Tue Mar  7 21:59:44 2017 Robin MILAS
##

CC	=	gcc

RM	=	rm -f

SRCS	=	src/display/color.c		\
		src/display/control.c		\
		src/display/framebuffer.c	\
		src/display/main.c		\
		src/display/my_put_pixel.c	\
		src/display/render.c		\
		src/display/utils.c		\
		src/display/window.c		\
		src/decoder/decoder.c		\
		src/decoder/normal.c		\
		src/decoder/intersect.c		\
		src/scene/add_objs.c		\
		src/scene/coord3d.c		\
		src/scene/scene.c		\
		src/calc_dir_vector.c		\
		src/cone.c			\
		src/cylinder.c			\
		src/light.c			\
		src/plane.c			\
		src/rotate.c			\
		src/sphere.c			\
		src/translate.c			\
		src/utils.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	raytracer

## -Werror
CFLAGS	=	-Wall -Wextra -I./include -ffast-math -O3

LDFLAGS	=	-lm -lc_graph_prog

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:
		$(RM) $(NAME) $(OBJS)

re	:	fclean all

.PHONY	:	all re fclean clean

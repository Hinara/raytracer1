##
## Makefile for navy in /home/robin.milas/Current/PSU_2016_navy
## 
## Made by Robin MILAS
## Login   <robin.milas@epitech.net>
## 
## Started on  Mon Dec  5 18:52:38 2016 Robin MILAS
## Last update Tue Apr 25 20:49:37 2017 Milas Robin
##

CC	=	gcc

RM	=	rm -fr

SRCS	=	src/display/color.c		\
		src/display/control.c		\
		src/display/framebuffer.c	\
		src/display/main.c		\
		src/display/free.c		\
		src/display/reader.c		\
		src/display/my_put_pixel.c	\
		src/display/render.c		\
		src/display/utils.c		\
		src/display/window.c		\
		src/decoder/decoder.c		\
		src/decoder/normal.c		\
		src/decoder/intersect.c		\
		src/scene/add_objs.c		\
		src/scene/scene.c		\
		src/calc_dir_vector.c		\
		src/cone.c			\
		src/cylinder.c			\
		src/light.c			\
		src/plane.c			\
		src/rotate.c			\
		src/sphere.c			\
		src/translate.c			\
		src/utils.c			\
		src/vector.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	raytracer

DEPS	=	deps

CFLAGS	=	-Wall -Wextra -Werror -I./include -ffast-math -O3 -I$(DEPS)/include

LDFLAGS	=	-lm -lc_graph_prog -L$(DEPS)/lib

all	:	$(NAME)

$(NAME)	:	deps $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

deps	:
		mkdir $(DEPS)
		wget "https://cdn.local.epitech.eu/elearning/B-MUL-151/C_Graph_Prog_Installer_Full-v1.2.0.tar" -O - | tar -x
		mv installer/lib $(DEPS)/lib/
		mv installer/include $(DEPS)/include/
		$(RM) installer

clean	:
		$(RM) $(OBJS)

fclean	:
		$(RM) $(NAME) $(OBJS) $(DEPS)

re	:	fclean all

.PHONY	:	all re fclean clean

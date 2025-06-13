# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olcherno <olcherno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/06 15:18:15 by olcherno          #+#    #+#              #
#    Updated: 2025/06/13 17:46:53 by olcherno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Компілятор і флаги
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# Імена
NAME = so_long

# Шляхи
SRCDIR = src
OBJDIR = obj
LIBFTDIR = libs/libft
FTPRINTF_DIR = libs/libftprintf
MLXDIR = libs/minilibx

# Флаги лінкування
MLX_FLAGS = -L$(MLXDIR) -lmlx -lX11 -lXext -lm
LIBS = -L$(LIBFTDIR) -lft -L$(FTPRINTF_DIR) -lftprintf

# Список файлів
SRC = main.c checking1_map.c checking2_map.c 
SRCS = $(addprefix $(SRCDIR)/, $(SRC))
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))

# Основне правило
$(NAME): $(OBJS) $(LIBFTDIR)/libft.a $(FTPRINTF_DIR)/libftprintf.a $(MLXDIR)/libmlx.a
	$(CC) $(CFLAGS) -no-pie $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

# Компіляція .c → .o
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -I$(SRCDIR) -I$(LIBFTDIR) -I$(FTPRINTF_DIR) -I$(MLXDIR) -c $< -o $@

# Створення obj/
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Збірка бібліотек
$(LIBFTDIR)/libft.a:
	$(MAKE) -C $(LIBFTDIR)

$(FTPRINTF_DIR)/libftprintf.a:
	$(MAKE) -C $(FTPRINTF_DIR)

$(MLXDIR)/libmlx.a:
	$(MAKE) -C $(MLXDIR)

# Стандартні правила
.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(FTPRINTF_DIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(FTPRINTF_DIR) fclean
	$(MAKE) -C $(MLXDIR) clean

re: fclean all
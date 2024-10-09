# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalebrun <nalebrun@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 14:22:51 by nalebrun          #+#    #+#              #
#    Updated: 2024/10/09 14:22:57 by nalebrun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
CC = gcc

# Flags
CFLAGS -Wall -Werror -Wextra -g -Iinclude

# Dirs
SRCDIR = src
INCDIR = includes
BUILDDIR = build
LIBDIR = .

# Target name
LIBNAME = libft.a

# Sources
SRCS = $(wildcard $(SRCDIR)/*.c)

# Objects
OBJS = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRCS))

# Phony targets
.PHONY: all clean fclean re

# Default target
# (all : _lib_ -> means lib must be buid to be marked as up to date)
all: $(LIBDIR)/$(LIBNAME)

# Rule to create the lib
# ($@ = auto var to rep. $(LIBDIR)/$(LIBNAME) | $^ auto var to rep. $(OBJS) )
$(LIBDIR)/$(LIBNAME): $(OBJS)
	@ar rcs $@ $^

# Rule to create the objects files
# ($< = auto var to rep. the source file
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean the lib and build dir
fclean:
	rm -rf $(BUILDDIR) $(LIBDIR)/$(LIBNAME)

# Clean the build dir
clean:
	rm -rf $(BUILDDIR)

re: fclean all
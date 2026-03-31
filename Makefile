# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eschloss <eschloss@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 16:25:02 by eschloss          #+#    #+#              #
#    Updated: 2026/03/24 16:45:35 by eschloss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#colours
GREEN := \\033[1;92m
RED := \\033[31m
WHITE := \\033[1;60m
RESET := \\033[0m

NAME := libft.a #compiled library name
CC := cc 
CFLAGS = -Wall -Wextra -Werror
# Wall - enables warnings avoidable code constructs (i.e. unitiliazed vars, functions w/out return value, etc.)
# Wextra - enables additional warnings (i.e. "empty" if-bodies, unused-but-set paramters, etc.)
# Werror - treats warnings as compilation errors
AR = ar rcs
# ar - lower-level archiver tool to create, modify and exract static libraries.
# it bundles individual object files into single archive and generates symbol table to help
# linker efficiently locate symbols during linking
# r (replace) - replaces old files with new ones, creates them if they dont exist
# c (create) - creates archive if it doesnt exist, surpressing warning that normally appears
# s (symbl table) - generates/updates symbol table(index), allows linker to quickly locate symbols
RM = rm -f 
# rm  - permanently deletes files/dirs
# f (force) - ignores non-existent files. Otherwise, trying to delete non-existing file would 
# throw a warning
# silent - wont ask for confirmation
SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_substr.c
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)libft object files have been archived.$(RESET)"
%.o : %.c 
	$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(WHITE)Compiling file ->$(RESET) $(GREEN) $< $(RESET)"
clean:
	$(RM) $(OBJS)
	@echo "$(RED)Object files have been removed.$(RESET)"
fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Library has been removed.$(RESET)"
re: fclean all #REbuild everything, shortcut for doing a full clean and building again
.PHONY: all clean fclean re #treats these only as rules, not filenames (if they exist)
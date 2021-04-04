# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jkoers <jkoers@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/05 15:36:08 by jkoers        #+#    #+#                  #
#    Updated: 2021/01/17 13:35:42 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= push_swap

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror -Wuninitialized -O3
# CFLAGS			= -Wall -Wextra -Wuninitialized -O0 # debug

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj

LIBDIR			= ../lib
ifeq ($(shell uname),Linux)
LINKSRC			=
LINKS			=
LIBS			= $(LIBDIR)/libft/bin/libft.a
INCLUDES		= -I$(HEADERDIR) -I$(LIBDIR)
else
LINKSRC			=
LINKS			=
LIBS			= $(LIBDIR)/libft/bin/libft.a
INCLUDES		= -I$(HEADERDIR) -I$(LIBDIR)
endif

HEADERS			= $(shell find $(HEADERDIR) -type f -name '*.h')

include sources.mk

OBJ	= $(foreach src,$(SRC),$(BUILDDIR)/$(notdir $(src:.$(SRCEXT)=.$(OBJEXT))))

VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')

all:
	make -j4 $(NAME)

bonus:
	make -j4 $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJ) $(HEADERS) $(LIBS) $(SETTINGS)
	$(CC) $(CFLAGS) $(INCLUDES) $(BUILDDIR)/*.$(OBJEXT) -o $(NAME) \
$(LIBS) $(LINKS)

# sources

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS) $(SETTINGS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(BUILDDIR)/$(notdir $@) $(LINKSRC)

# libs
$(LIBDIR)/libft/bin/libft.a:
	$(MAKE) -C $(LIBDIR)/libft/

clean:
	make -C $(LIBDIR)/libft/ clean
ifneq ($(BUILDDIR),.)
	/bin/rm -rf $(BUILDDIR)/
endif

fclean:
	$(MAKE) clean
	make -C $(LIBDIR)/libft/ fclean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

findsources:
	echo "# SRC = find src/ -name \"\*.c\" -exec echo \"\{\} \\\\\" \\\;" \
> sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

silent:
	@$(MAKE) bonus > /dev/null

.PHONY: all clean fclean re findsources silent

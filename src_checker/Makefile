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

NAME      		= checker

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Wuninitialized -O3
# CFLAGS      	= -Wall -Wextra -Werror -Wuninitialized -O3

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj

LIBS			= ../lib/libft/bin/libft.a
INCLUDES		= -I$(HEADERDIR) -I../lib/

HEADERS			= $(shell find $(HEADERDIR) -type f -name '*.h')

include sources.mk

OBJ	= $(foreach src,$(SRC),$(BUILDDIR)/$(notdir $(src:.$(SRCEXT)=.$(OBJEXT))))

VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')
.SUFFIXES:
SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"

all bonus: $(NAME)

$(NAME): $(BUILDDIR)/ $(OBJ) $(HEADERS) $(SETTINGS)
	cp ../lib/stack/obj/*.o $(BUILDDIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(BUILDDIR)/*.$(OBJEXT) $(LIBS) -o $(NAME)

# sources

$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS) $(SETTINGS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(BUILDDIR)/$(notdir $@) $(LINKSRC)

clean:
ifneq ($(BUILDDIR),.)
	/bin/rm -rf $(BUILDDIR)/
endif

fclean:
	$(MAKE) clean
	/bin/rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

findsources:
	echo "# SRC = \$$(shell find $(SRCDIR)/ -type f -name '*.c')" > sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

silent:
	@$(MAKE) > /dev/null

.PHONY: all clean fclean re findsources silent

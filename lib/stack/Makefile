# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: joppe <joppe@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/08/23 17:53:14 by jkoers        #+#    #+#                  #
#    Updated: 2020/12/31 13:03:32 by jkoers        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME      		= libstack

CC          	= gcc
CFLAGS      	= -Wall -Wextra -Werror

SRCEXT      	= c
SRCDIR      	= src
HEADERDIR		= include
OBJEXT      	= o
BUILDDIR    	= obj
BINDIR			= bin
HEADER			= include/libft.h

LIBS			= ../libft/bin/libft.a
INCLUDES		= -Iinclude/

include sources.mk

OBJECTS     	= $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$\
				  $(SRC:.$(SRCEXT)=.$(OBJEXT)))

# make bs
SILECE_MAKE = | grep -v -E ".*Leaving directory|.*Entering directory"
.SUFFIXES:
VPATH = $(shell find $(SRCDIR) -type d | tr '\n' ':' | sed -E 's/(.*):/\1/')

all: $(BINDIR)/$(NAME).a

$(NAME): $(BINDIR)/$(NAME).a

static: $(BINDIR)/$(NAME).a

$(BINDIR)/$(NAME).a: $(BUILDDIR)/ $(BINDIR)/ $(OBJECTS)
	$(MAKE) -C ../libft $(SILECE_MAKE)
	cp ../libft/bin/libft.a $(BINDIR)/$(NAME).a
	ar -cr $(BINDIR)/$(NAME).a $(BUILDDIR)/*.$(OBJEXT) $(LIBS)


clean:
	/bin/rm -rf $(BUILDDIR)/

fclean:
	$(MAKE) clean $(SILECE_MAKE)
	/bin/rm -f $(TESTNAME)
	/bin/rm -rf $(BINDIR)/

re:
	$(MAKE) fclean $(SILECE_MAKE)
	$(MAKE) all $(SILECE_MAKE)

findsources:
	echo "# SRC = \$$(shell find $(SRCDIR)/ -type f -name '*.c')" > sources.mk
	echo "SRC = \\" >> sources.mk
	find src/ -name "*.c" -exec echo "{} \\" \; >> sources.mk

$(BUILDDIR)/:
	mkdir -p $(BUILDDIR)

$(BINDIR)/:
	mkdir -p $(BINDIR)


$(BUILDDIR)/%.$(OBJEXT): %.$(SRCEXT) $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(BUILDDIR)/$(notdir $@)

.PHONY: all so static clean fclean re

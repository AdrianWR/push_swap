# This Makefile has improved a lot from the tips given by Lunderberg.
# While his main focus was to build projects with C++, we could take
# a lot of great ideas to use here as well. Check out his work on
# http://www.lunderberg.com/2015/08/24/cpp-makefile-multiple-libraries/

# Default build variables, can be overridden by command line options.

NAME		=	checker push_swap

CC			=	clang
CPPFLAGS	=
CFLAGS		=
LDFLAGS		=
LDLIBS		=
RM			=	rm -f
BUILD		=	default

ifneq ($(BUILD),default)
    include build-targets/$(BUILD).inc
endif

# Additional flags that are necessary to compile.
# Even if not specified on the command line, these should be present.

override CPPFLAGS	+= -Iinclude
override CFLAGS		+= -Wall -Wextra -Werror
override LDFLAGS	+= -Llib -Wl,-rpath,\$$ORIGIN/../lib -Wl,--no-as-needed
override LDLIBS		+=

.SECONDARY:
.SECONDEXPANSION:
.PHONY: all clean fclean re force test

# Source and object files for the executable
vpath %.c	src	src/checker src/push_swap libft/src libstack/src

SRC_FILES			=	get_stack.c	\
						search.c	\
						free.c		\
						utils.c		\
						utils_sort.c
O_FILES				= 	$(patsubst %.c,build/$(BUILD)/build/%.o,$(SRC_FILES))

CHECKER_SRC_FILES	=	checker.c		\
						search.c		\
						get_line.c		\
						execute.c
CHECKER_O_FILES		= 	$(patsubst %.c,build/$(BUILD)/build/%.o,$(CHECKER_SRC_FILES)) $(O_FILES)

PUSH_SWAP_SRC_FILES	=	push_swap.c		\
						sort.c			\
						sort_small.c	\
						sort_complex.c	\
						smart.c			\
						index.c			\
						move.c			\
						run.c
PUSH_SWAP_O_FILES	= 	$(patsubst %.c,build/$(BUILD)/build/%.o,$(PUSH_SWAP_SRC_FILES)) $(O_FILES)

# Build and link of multiple libraries
LIBRARY_FOLDERS = libft libstack
LIBRARY_INCLUDES = $(patsubst %,-I%/include,$(LIBRARY_FOLDERS))
override CPPFLAGS += $(LIBRARY_INCLUDES)
LIBRARY_FLAGS = $(patsubst lib%,-l%,$(LIBRARY_FOLDERS))
override LDLIBS += $(LIBRARY_FLAGS)
library_src_files = ft_atoi.c			\
					ft_bzero.c			\
					ft_calloc.c			\
					ft_isalnum.c		\
					ft_isalpha.c		\
					ft_isascii.c		\
					ft_isdigit.c		\
					ft_isprint.c		\
					ft_isspace.c		\
					ft_itoa.c			\
					ft_lstadd_front.c	\
					ft_lstdelone.c		\
					ft_lstfirst.c		\
					ft_lstmap.c			\
					ft_lstnew.c			\
					ft_lstsize.c		\
					ft_memccpy.c		\
					ft_strtrim.c		\
					ft_memcpy.c			\
					ft_strtok_r.c		\
					ft_memcmp.c			\
					ft_memset.c			\
					ft_putchar_fd.c		\
					ft_putendl_fd.c		\
					ft_putnbr_fd.c		\
					ft_putstr_fd.c		\
					ft_strchr.c			\
					ft_strcspn.c		\
					ft_strdup.c			\
					ft_strlcat.c		\
					ft_strlcpy.c		\
					ft_memmove.c		\
					ft_strmapi.c		\
					ft_strnstr.c		\
					ft_strrchr.c		\
					ft_strspn.c			\
					ft_split.c			\
					ft_lstiter.c		\
					ft_substr.c			\
					ft_tolower.c		\
					ft_toupper.c		\
					ft_strjoin.c		\
					ft_strtok.c			\
					ft_lstadd_back.c	\
					ft_lstlast.c		\
					ft_memchr.c			\
					ft_strlen.c			\
					ft_strncmp.c		\
					ft_strreplace.c		\
					ft_streq.c			\
					ft_lstclear.c		\
					get_next_line.c		\
					initialize.c		\
					push.c				\
					max.c				\
					min.c				\
					rotate.c			\
					swap.c
library_o_files   = $(patsubst %.c,build/$(BUILD)/build/%.o,$(call library_src_files,$(1)))
STATIC_LIBRARY_OUTPUT = $(patsubst %,lib/%.a,$(LIBRARY_FOLDERS))

# Source and object files for unit tests
TEST_FOLDER = test
TEST_INCLUDES = $(patsubst %,-I%/include,$(TEST_FOLDER))
override CPPFLAGS += $(TEST_INCLUDES)
TEST_SRC_FILES = $(TEST_FOLDER)/src/test.c
TEST_O_FILES	= $(patsubst %.c,build/$(BUILD)/build/%.o, $(TEST_SRC_FILES))
TEST_O_FILES	+= $(O_FILES)
TEST_O_FILES	+= $(filter-out %/checker.o, $(CHECKER_O_FILES))
TEST_O_FILES	+= $(filter-out %/push_swap.o, $(PUSH_SWAP_O_FILES))


################
# SOURCE FILES #
################

all: $(NAME)

override CPPFLAGS += -MMD
-include $(shell find build -name "*.d" 2> /dev/null)

.build-target: force
	echo $(BUILD) | cmp -s - $@ || echo $(BUILD) > $@

checker: build/$(BUILD)/bin/checker .build-target $(STATIC_LIBRARY_OUTPUT)
	mkdir -p $(@D)
	cp -f $< $@

push_swap: build/$(BUILD)/bin/push_swap .build-target $(STATIC_LIBRARY_OUTPUT)
	mkdir -p $(@D)
	cp -f $< $@

lib/%: build/$(BUILD)/lib/% .build-target
	mkdir -p $(@D)
	cp -f $< $@

build/$(BUILD)/bin/checker: $(CHECKER_O_FILES) $(STATIC_LIBRARY_OUTPUT)
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/$(BUILD)/bin/push_swap: $(PUSH_SWAP_O_FILES) $(STATIC_LIBRARY_OUTPUT)
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

build/$(BUILD)/build/%.o: %.c
	mkdir -p $(@D)
	$(CC) -c $(CPPFLAGS) $(CFLAGS) $< -o $@

##################
# LIBRARIES ZONE #
##################

define library_variables
CPPFLAGS_LIB =
CFLAGS_LIB =
LDFLAGS_LIB  =
-include $(1)/Makefile.inc
build/$(1)/%.o: CPPFLAGS := $$(CPPFLAGS) $$(CPPFLAGS_LIB)
build/$(1)/%.o: CFLAGS := $$(CFLAGS) $$(CFLAGS_LIB)
lib/$(1).a:  LDFLAGS  := $$(ALL_LDFLAGS)  $$(LDFLAGS_LIB)
endef

$(foreach lib,$(LIBRARY_FOLDERS),$(eval $(call library_variables,$(lib))))
	
build/$(BUILD)/lib/lib%.a: $$(call library_o_files,%)
	mkdir -p $(@D)
	$(AR) rcs $@ $^

#############
# TEST ZONE #
#############

build/$(BUILD)/bin/test: $(TEST_O_FILES) $(STATIC_LIBRARY_OUTPUT)
	mkdir -p $(@D)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

test: build/$(BUILD)/bin/test
	./$<

#########
# UTILS #
#########

clean:
	$(RM) -r bin build lib .build-target

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

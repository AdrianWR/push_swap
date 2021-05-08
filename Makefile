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
.PHONY: all clean fclean re force test shell debug

# Source and object files for the executable
vpath %.c src src/checker src/push_swap

SRC_FILES			=	get_stack.c	\
						search.c	\
						free.c		\
						utils.c
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
						push_chunk.c	\
						pivot.c			\
						index.c			\
						run.c
PUSH_SWAP_O_FILES	= 	$(patsubst %.c,build/$(BUILD)/build/%.o,$(PUSH_SWAP_SRC_FILES)) $(O_FILES)

# Build and link of multiple libraries
LIBRARY_FOLDERS = libft libstack
LIBRARY_INCLUDES = $(patsubst %,-I%/include,$(LIBRARY_FOLDERS))
override CPPFLAGS += $(LIBRARY_INCLUDES)
LIBRARY_FLAGS = $(patsubst lib%,-l%,$(LIBRARY_FOLDERS))
override LDLIBS += $(LIBRARY_FLAGS)
library_src_files = libft/src/ft_atoi.c			\
					libft/src/ft_bzero.c		\
					libft/src/ft_calloc.c		\
					libft/src/ft_isalnum.c		\
					libft/src/ft_isalpha.c		\
					libft/src/ft_isascii.c		\
					libft/src/ft_isdigit.c		\
					libft/src/ft_isprint.c		\
					libft/src/ft_isspace.c		\
					libft/src/ft_itoa.c			\
					libft/src/ft_lstadd_front.c	\
					libft/src/ft_lstdelone.c	\
					libft/src/ft_lstfirst.c		\
					libft/src/ft_lstmap.c		\
					libft/src/ft_lstnew.c		\
					libft/src/ft_lstsize.c		\
					libft/src/ft_memccpy.c		\
					libft/src/ft_strtrim.c		\
					libft/src/ft_memcpy.c		\
					libft/src/ft_strtok_r.c		\
					libft/src/ft_memcmp.c		\
					libft/src/ft_memset.c		\
					libft/src/ft_putchar_fd.c	\
					libft/src/ft_putendl_fd.c	\
					libft/src/ft_putnbr_fd.c	\
					libft/src/ft_putstr_fd.c	\
					libft/src/ft_strchr.c		\
					libft/src/ft_strcspn.c		\
					libft/src/ft_strdup.c		\
					libft/src/ft_strlcat.c		\
					libft/src/ft_strlcpy.c		\
					libft/src/ft_memmove.c		\
					libft/src/ft_strmapi.c		\
					libft/src/ft_strnstr.c		\
					libft/src/ft_strrchr.c		\
					libft/src/ft_strspn.c		\
					libft/src/ft_split.c		\
					libft/src/ft_lstiter.c		\
					libft/src/ft_substr.c		\
					libft/src/ft_tolower.c		\
					libft/src/ft_toupper.c		\
					libft/src/ft_strjoin.c		\
					libft/src/ft_strtok.c		\
					libft/src/ft_lstadd_back.c	\
					libft/src/ft_lstlast.c		\
					libft/src/ft_memchr.c		\
					libft/src/ft_strlen.c		\
					libft/src/ft_strncmp.c		\
					libft/src/ft_strreplace.	\
					libft/src/ft_streq.c		\
					libft/src/ft_lstclear.c		\
					libft/src/get_next_line.	\
					libstack/src/initialize.	\
					libstack/src/push.c			\
					libstack/src/max.c			\
					libstack/src/min.c			\
					libstack/src/rotate.c		\
					libstack/src/swap.c
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

all: $(NAME)

override CPPFLAGS += -MMD
-include $(shell find build -name "*.d" 2> /dev/null)

ifneq ($(BUILD),default)
    include build-targets/$(BUILD).inc
endif

################
# SOURCE FILES #
################

all: $(NAME)

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

test_debug:
	$(MAKE) BUILD=debug build/debug/bin/test
	gdb ./build/debug/bin/test

shell: $(NAME)
	./$(NAME)

#########
# UTILS #
#########

debug_push_swap:
	$(MAKE) BUILD=debug build/debug/bin/push_swap
	gdb ./build/debug/bin/push_swap

debug_checker:
	$(MAKE) BUILD=debug build/debug/bin/checker
	gdb ./build/debug/bin/checker

clean:
	$(RM) -r bin build lib .build-target

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

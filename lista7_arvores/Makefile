CC = gcc
CFLAGS = -Wall -Wextra -g
DIRS = $(sort $(dir $(wildcard Exer*/main.c)))
EXES = $(addsuffix main.exe,$(DIRS))

all: $(EXES)

define REGRA
$(1)main.exe: $(wildcard $(1)*.c) $(wildcard $(1)*.h)
	$(CC) $(CFLAGS) $(wildcard $(1)*.c) -o $(1)main.exe
endef

$(foreach d,$(DIRS),$(eval $(call REGRA,$(d))))

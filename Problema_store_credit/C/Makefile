# ------------------------------------------------
# Makefile for C projects
# ------------------------------------------------
TARGET   = out

COMPILER=gcc -std=c99
# compiling flags here
CFLAGS   = -std=c99 -Wall -I.

# linking flags here
LINKER   = gcc -o
LFLAGS   = -Wall -I. -lm

# Directories
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(INCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(COMPILER) $(LFLAGS) $(LDLIBS) $(OBJECTS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(COMPILER) $(LFLAGS) $(LDLIBS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

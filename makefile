CFLAGS  += -Wall -Wpedantic -std=c11
LDFLAGS +=
LDLIBS  +=

SRCDIR = src
OBJDIR = obj
DEPDIR = .dep

COMPILE    = $(CC) $(CFLAGS) -c -o $@ $<
LINK       = $(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
MAKEDEPEND = $(CC) $(CFLAGS) -MM -MP -MT $@ -o $(DEPDIR)/$*.d $<

OUT = ucc
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

$(shell mkdir -p $(DEPDIR) $(OBJDIR))

all: $(OUT)

clean:
	rm -rf $(DEPDIR) $(OBJDIR) $(OUT)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPDIR)/%.d
	$(MAKEDEPEND)
	$(COMPILE)

$(OUT): $(OBJ)
	$(LINK)

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

-include $(SRC:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

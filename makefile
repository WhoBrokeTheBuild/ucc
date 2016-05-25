.PHONY: all clean

LEX  = flex
YACC = bison

CFLAGS  += -g -Wall -Wpedantic -std=c11
LDFLAGS +=
LDLIBS  +=
LFLAGS  +=
YFLAGS  += -v

SRCDIR = src
OBJDIR = obj
DEPDIR = .dep

COMPILE    = $(CC) $(CFLAGS) -c -o $@ $<
LINK       = $(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
MAKEDEPEND = $(CC) $(CFLAGS) -MM -MP -MT $@ -o $(DEPDIR)/$*.d $<

OUT  = ucc
SRC  = $(wildcard $(SRCDIR)/*.c)
OBJ  = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LEX_SRC = $(wildcard $(SRCDIR)/*.l)
LEX_GEN = $(SRCDIR)/lex.yy.c
YACC_SRC = $(wildcard $(SRCDIR)/*.y)
YACC_GEN = $(YACC_SRC:%.y=%.tab.c)
YACC_HDR = $(YACC_SRC:%.y=%.tab.h)

SRC += $(LEX_GEN) $(YACC_GEN)

$(shell mkdir -p $(DEPDIR) $(OBJDIR))

all: $(OUT)

clean:
	rm -rf $(DEPDIR) $(OBJDIR) $(OUT) $(SRCDIR)/*.yy.c $(SRCDIR)/*.tab.* $(SRCDIR)/*.output

$(OBJDIR)/%.o : $(SRCDIR)/%.c
$(OBJDIR)/%.o : $(SRCDIR)/%.c $(DEPDIR)/%.d
	$(MAKEDEPEND)
	$(COMPILE)

$(OUT): $(OBJ)
	$(LINK)

$(LEX_GEN): $(LEX_SRC) $(YACC_GEN)
	$(LEX) $(LFLAGS) -o $@ $<

$(YACC_GEN): $(YACC_SRC)
	$(YACC) $(YFLAGS) -d $^ -o $@

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

-include $(SRC:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

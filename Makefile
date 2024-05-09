CC = g++
CFLAGS = -Wall -std=c++11
TARGET = biblioteca
SRCDIR = src
OBJDIR = obj
INSTALLDIR = bin

SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $SRCDIR/%.cpp,$(OBJDIR)/%.o,$(SOURCES))

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

clean:
	rm -rf $(OBJDIR) $(TARGET)
	rm -rf $(INSTALLDIR)/*

install: $(TARGET)
	install -m 755 $(TARGET) $(INSTALLDIR)

.PHONY: clean install

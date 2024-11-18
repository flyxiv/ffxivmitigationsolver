CC = gcc
PKGCONFIG = pkg-config
CFLAGS = -Wall -g -I./src -I./src/util -I./src/ffxivcomponents -I./src/ffxivcomponents/damage -I./src/ffxivcomponents/mitigation -I./src/ffxivcomponents/timelineboard -I./src/ffxivcomponents/timelineparser -I./src/error 
LIBS = $(shell $(PKGCONFIG) --libs gtk4)
SRCDIR = src
OBJDIR = obj

SOURCES_OTHER_THAN_MAIN = $(wildcard $(SRCDIR)/util/*.c) $(wildcard $(SRCDIR)/util/tests/*.c) $(wildcard $(SRCDIR)/ffxivcomponents/*.c) $(wildcard $(SRCDIR)/ffxivcomponents/damage/*.c) $(wildcard $(SRCDIR)/ffxivcomponents/mitigation/*.c) $(wildcard $(SRCDIR)/timelineboard/*.c)  $(wildcard $(SRCDIR)/timelineparser/*.c) $(wildcard $(SRCDIR)/error/*.c)



# 소스 파일과 오브젝트 파일 목록 생성
SOURCES_MAIN = $(wildcard $(SRCDIR)/main.c) $(SOURCES_OTHER_THAN_MAIN)
OBJECTS_MAIN = $(SOURCES_MAIN:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


SOURCES_TEST = $(wildcard $(SRCDIR)/test_main.c) $(SOURCES_OTHER_THAN_MAIN) 
OBJECTS_TEST = $(SOURCES_TEST:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# 최종 실행 파일 이름
MAIN = ffxiv_mitigation_solver.exe
TEST = ffxiv_mitigation_solver_test.exe

# 오브젝트 디렉토리 생성
$(shell mkdir -p $(OBJDIR) $(OBJDIR)/util $(OBJDIR)/util/tests $(OBJDIR)/ffxivcomponents $(OBJDIR)/ffxivcomponents/damage $(OBJDIR)/ffxivcomponents/mitigation $(OBJDIR)/timelineboard $(OBJDIR)/timelineparser $(OBJDIR)/error)

# 기본 규칙
all: $(MAIN) $(TEST)

# 실행 파일 생성 규칙
$(MAIN): $(OBJECTS_MAIN)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(TEST): $(OBJECTS_TEST)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

# 오브젝트 파일 생성 규칙
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# 청소 규칙
clean:
	rm -rf $(OBJDIR) $(MAIN)

.PHONY: all clean
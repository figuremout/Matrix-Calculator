CC := gcc
CFLAGS := -Wall -O2 -std=gnu11
# generate .gcno files
DEBUGFLAGS := -DDEBUG=1 -g -fprofile-arcs -ftest-coverage

BINDIR = ./bin
COVREPORTDIR = ./cov-report

.PHONY: all
all: compile

.PHONY: prepare
prepare:
	bash -c "if [[ ! -d $(BINDIR) ]]; then mkdir $(BINDIR); fi"
	bash -c "if [[ ! -d $(COVREPORTDIR) ]]; then mkdir $(COVREPORTDIR); fi"

.PHONY: compile
compile: prepare
	$(CC) vhder.c vhdlib.c -o $(BINDIR)/vhder $(CFLAGS) $(LDFLAGS) $(DEBUGFLAGS)
	chmod a+x $(BINDIR)/vhder

.PHONY: memcheck
memcheck: compile fuzzing
	valgrind --tool=memcheck --leak-check=yes -s $(BINDIR)/vhder -d random.vhd > /dev/null

.PHONY: covcheck
covcheck: compile fuzzing
	$(BINDIR)/vhder -d random.vhd > /dev/null 2>&1 # generate .gcda files
	gcov $(BINDIR)/vhder-vhder # generate .gcov files
	gcov $(BINDIR)/vhder-vhdlib
	lcov -c -d . -o cov.info # generate .info
	genhtml -o $(COVREPORTDIR) cov.info # generate html report

.PHONY: clean
clean:
	rm -rf ./bin
	rm -rf *.info
	rm -rf *.gcov
	rm -rf ./cov-report

.PHONY: install
install:
	#install vhdlib

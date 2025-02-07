CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic
CXXFILES = tests/*.cc
LDFLAGS = -lgtest -pthread
LINTFLAGS = -style=google --verbose
LINTFILES = find . -name '*.h' -o -name '*.cc' -o -name '*.tpp'
GCOVCOMPFLAGS = -fprofile-arcs -ftest-coverage
LCOVFLAGS = -c -d . -q --no-external 
LCOVFILES = s21_containers.info
REPORT_DIR = report/index.html

ifeq ($(shell uname), Darwin)
	IGNORELCOV = --ignore-errors mismatch --ignore-errors inconsistent
endif

all: test

test: check_comp
	$(CXX) $(CXXFLAGS) $(CXXFILES) $(LDFLAGS) -o test.out
	./test.out
gcov_report:
ifeq ($(shell which lcov 2>/dev/null),)
	$(error "lcov is required!")
endif
	@rm -rf report
	$(CXX) $(CXXFLAGS) $(GCOVCOMPFLAGS) $(CXXFILES) $(LDFLAGS) -o gcov_report.out 
	./gcov_report.out
	lcov -t s21_containers -o $(LCOVFILES) $(LCOVFLAGS) $(IGNORELCOV)
	genhtml -o report $(LCOVFILES) -q
	@rm -f *.info *.gcda *.gcno gcov_report.out
	@rm -f *.o
	@echo -e '\n'HTML report is here --\> $(shell pwd)/$(REPORT_DIR)
clean:
	rm -f *.a *.o *.info *.gcda *.gcno *.out
	rm -rf report
rebuild: clean all

style_check: check_lint
	@$(LINTFILES) | xargs clang-format -n $(LINTFLAGS)
style_fix: check_lint
	@$(LINTFILES) | xargs clang-format -i $(LINTFLAGS)
cpplint:
ifeq ($(shell which cpplint 2>/dev/null),)
	$(error "cpplint is required!")
endif
	@$(LINTFILES) | xargs cpplint --filter=-runtime/explicit,-build/include_what_you_use

valgrind: check_valgrind clean test
	valgrind --tool=memcheck --leak-check=full ./test.out

check_comp:
ifeq ($(shell which g++ 2>/dev/null),)
	$(error "g++ is required!")
endif
check_lint:
ifeq ($(shell which clang-format 2>/dev/null),)
	$(error "clang-format is required!")
endif
check_valgrind:
ifeq ($(shell which valgrind 2>/dev/null),)
	$(error "valgrind is required!")
endif
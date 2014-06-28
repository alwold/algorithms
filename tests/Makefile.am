TESTS = check_merge
check_PROGRAMS = check_merge
check_merge_SOURCES = check_merge.c $(top_builddir)/src/merge.h
check_merge_CFLAGS = @CHECK_CFLAGS@
check_merge_LDADD = $(top_builddir)/src/merge.o $(top_builddir)/src/quick_sort.o $(top_builddir)/src/util.o $(top_builddir)/src/linked_list.o $(top_builddir)/src/heap.o @CHECK_LIBS@
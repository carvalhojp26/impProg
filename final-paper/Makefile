.PHONY: docs build

build:
	gcc main.c utils.c -o main.out

docs:
	doxygen docs/Doxyfile && \
	cd latex/ && \
	make pdf && \
	cd .. && \
	mv latex/refman.pdf docs/docs.pdf && \
	rm -rf latex

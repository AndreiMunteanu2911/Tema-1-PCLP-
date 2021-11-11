all: build
build: task1.c task2.c task3.c task4.c
	gcc task1.c -o task1
	gcc task2.c -o task2
	gcc task3.c -o task3
	gcc task4.c -o task4

clean:
	rm -f task1 task2 task3 task4
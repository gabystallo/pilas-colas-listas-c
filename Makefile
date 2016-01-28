all:
	gcc pcl.c -o pcl
test:
	gcc pcl.c -o pcl
	./pcl
	rm pcl
clean:
	rm pcl

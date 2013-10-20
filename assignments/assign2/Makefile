compiler=gcc

all: 261 264 269 273

261: 261.c 261_tester.c  
	$(compiler) 261_tester.c -o 261.test
264: 264.c 264_tester.c 
	$(compiler) 264_tester.c -o 264.test
269: 269.c 269_tester.c 
	$(compiler) 269_tester.c -o 269.test
273: 273.c 273_tester.c
	$(compiler) 273_tester.c -o 273.test
	
clang: compiler=clang -fsanitize=undefined
clang: c261 c264 c269 c273
	
c261: 261.c 261_tester.c  
	$(compiler) 261_tester.c -o c261.test
c264: 264.c 264_tester.c 
	$(compiler) 264_tester.c -o c264.test
c269: 269.c 269_tester.c 
	$(compiler) 269_tester.c -o c269.test
c273: 273.c 273_tester.c
	$(compiler) 273_tester.c -o c273.test
	
clean:
	rm *.test
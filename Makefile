run: a.out
	./a.out

.SILENT: a.out
a.out: $(F)
	g++ -I ~/CP -include stdc++.h -DLOCAL -std=c++20 $(F)

valgrind: va.out
	valgrind ./va.out
	# valgrind --quiet ./va.out

va.out: $(F)
	g++ -I ~/CP -include stdc++.h.g -DLOCAL -std=c++20 -g $(F) -o va.out

clean:
	rm a.out va.out vgcore* [A-Z] 2> /dev/null
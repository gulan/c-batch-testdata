hosp_td : main.o person_type.o surname.o hyphen.o ward_id.o
	gcc -Wall -std=c99 -o hosp_td main.o person_type.o surname.o hyphen.o ward_id.o

main.o : main.c
	gcc -Wall -std=c99 -c main.c

person_type.o : person_type.h person_type.c
	gcc -Wall -std=c99 -c person_type.c

surname.o : surname.h surname.c
	gcc -Wall -std=c99 -c surname.c

hyphen.o : hyphen.h hyphen.c surname.h
	gcc -Wall -std=c99 -c hyphen.c

ward_id.o : ward_id.h ward_id.c
	gcc -Wall -std=c99 -c ward_id.c

clean :
	-rm -f main.o person_type.o surname.o hyphen.o ward_id.o

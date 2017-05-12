hosp_td : main.o person_type.o surname.o ward_id.o
	gcc -Wall -std=c99 -o hosp_td main.o person_type.o surname.o ward_id.o

main.o : main.c
	gcc -Wall -std=c99 -c main.c

person_type.o : person_type.h
	gcc -Wall -std=c99 -c person_type.c

surname.o : surname.h
	gcc -Wall -std=c99 -c surname.c

ward_id.o : ward_id.h
	gcc -Wall -std=c99 -c ward_id.c

clean :
	-rm -f hosp_td main.o person_type.o surname.o ward_id.o

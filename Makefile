OPT = -Wall

a2:	main.o Control.o Course.o CourseArray.o Schedule.o School.o View.o Time.o
	g++ $(OPT) -o a2 main.o Control.o Course.o CourseArray.o Schedule.o School.o View.o Time.o

main.o: main.cc Control.h
	g++ $(OPT) -c main.cc 

Control.o: Control.cc Control.h School.h View.h defs.h
	g++ $(OPT) -c Control.cc

Course.o: Course.cc Course.h Time.h
	g++ $(OPT) -c Course.cc

CourseArray.o: CourseArray.cc CourseArray.h Course.h defs.h
	g++ $(OPT) -c CourseArray.cc

Schedule.o: Schedule.cc Schedule.h defs.h Course.h Time.h
	g++ $(OPT) -c Schedule.cc

School.o: School.cc School.h CourseArray.h Course.h
	g++ $(OPT) -c School.cc

View.o: View.cc View.h 
	g++ $(OPT) -c View.cc

Time.o: Time.cc Time.h defs.h
	g++ $(OPT) -c Time.cc

clean:
	del -f *.o a2.exe
OBJS = httpreq.o jsonhttpreq.o test_request.o
CC = g++
CFLAGS = -Wall -std=c++11 -c
LFLAGS = -Wall -std=c++11 -lcurl

test_request : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -lcurl -o test_request.out

test_request.o : httpreq.o jsonhttpreq.o
	$(CC) $(CFLAGS) test_request.cpp
	
jsonhttpreq.o : httpreq.o
	$(CC) $(CFLAGS) jsonhttpreq.cpp 
	
httpreq.o :
	$(CC) $(CFLAGS) httpreq.cpp

clean :
	\rm -fvr *.o *.out *~
	
	


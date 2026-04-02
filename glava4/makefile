encrypt.o: ebcrypt.c encrypt.h 
	gcc -c ebcrypt.c

message_hider.o: message_hider.c encrypt.h 
	gcc -c message_hider.c

encrypt: encrypt.o message_hider.o
	gcc  ebcrypt.o message_hider.o -o m
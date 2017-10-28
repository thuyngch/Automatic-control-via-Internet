#!/bin/sh

# clear screen
reset

# Compile
gcc -g -o main  main.c  											\
				../raspberry/lib/communication/communication.c 				\
				../raspberry/lib/bufferproc/bufferproc.c 					\
				../raspberry/lib/fileproc/fileproc.c 					\
				../raspberry/lib/frame/frame.c 						\
				./serveAdmin/serveAdmin.c 							\
				./adminService/adminService.c 						\
				./adminService/backup/backup.c						\
				./adminService/management/management.c 					\
				./adminService/login/admin_login.c 						\
				./adminService/history_viewer/history.c 					\
				./adminService/configuration/configuration.c 				\

				
# Run
./main 14.226.232.94 9000 	#P421
# ./main 14.226.228.25 9000 	#P423
# ./main 192.168.100.10 9000


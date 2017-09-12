#!/bin/sh

# Compile
gcc -g -o main  main.c  									\
				platform.c  								\
				../os-shell/os_shell.c						\
				../embedded-shell/embedded_shell.c 			\
				../lib/frame/frame.c  						\
				../lib/platform/thread.c  					\
				../lib/communication/communication.c 		\
				../lib/fileproc/fileproc.c 					\
				../os-shell/serverService/backup.c 			\
				../lib/bufferproc/bufferproc.c 				\
				-lpthread

# Run
./main 
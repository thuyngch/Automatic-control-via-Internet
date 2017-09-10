#!/bin/sh

# Compile
gcc -g -o main  main.c  						\
				platform.c  					\
				../os-shell/os_shell.c			\
				../lib/frame/frame.c  			\
				../lib/hplib/strproc.c 			\
				../lib/hplib/filesystem.c 		\
				../lib/platform/thread.c  		\
				-lpthread

# Run
./main 
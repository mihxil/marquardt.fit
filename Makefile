SHELL = /bin/sh 
NR = ../include/NR

CC = g++  -g 

SOURCE = fit.cpp qcalc.h f2calc.h function.h cmdln.cmdl Makefile

fit: fit.cpp cmdln.h qcalc.h f2calc.h function.h
	$(CC) -I$(NR)  $(NR)/t_nrutil.o fit.cpp  -o fit

cmdln.h: cmdln.cmdl
	gencom cmdln.cmdl > cmdln.h

clean:
	@rm -vf fit *~ cmdln.h

# Makes a backup from your source in bu/<date>.<sequence number>.tar.gz
backup: $(SOURCE)
	@mkdir -p bu
	@echo making backup
	@tar c -h $(SOURCE) | gzip > `echo bu/\`date "+%Y-%m-%d"\`.%d.tar.gz | numbername | tee  backup`  
	@echo >> backup
	@cat backup     
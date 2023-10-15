OUTDIR:=bin/
SRCDIR:=src/

testing:=minmax_parallelized.cpp
size:=99999

all:
	#source ~/intel/oneapi/setvars.sh
	sed s/TAMAÑO/$(size)/ $(SRCDIR)$(testing) > $(OUTDIR)tmp.cpp
	icpx -g -O3 -o $(OUTDIR)executable -fopenmp $(OUTDIR)tmp.cpp
	$(OUTDIR)executable > $(OUTDIR)resultado.txt
	python $(SRCDIR)comprobar_minmax.py $(OUTDIR)resultado.txt

clean:
	find . -iname "*~" -exec rm "{}" \;
	find . -iname "*.s" -exec rm "{}" \;
	find . -iname "*.o" -exec rm "{}" \;
	rm -rf $(OUTDIR)


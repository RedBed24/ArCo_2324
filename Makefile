OUTDIR:=bin/
SRCDIR:=src/

testing:=sumavector
size:=99999

all:
	#source ~/intel/oneapi/setvars.sh
	sed s/TAMAÑO/$(size)/ $(SRCDIR)$(testing).cpp > $(OUTDIR)tmp.cpp
	sed s/TAMAÑO/$(size)/ $(SRCDIR)$(testing)_parallelized.cpp > $(OUTDIR)tmp_parallelized.cpp
	icpx -g -O3 -o $(OUTDIR)executable -fopenmp $(OUTDIR)tmp.cpp
	icpx -g -O3 -o $(OUTDIR)executable_parallelized -fopenmp $(OUTDIR)tmp_parallelized.cpp
	$(OUTDIR)executable > $(OUTDIR)resultado.txt
	$(OUTDIR)executable_parallelized > $(OUTDIR)resultado_parallelized.txt
	python $(SRCDIR)comprobar_$(testing).py $(OUTDIR)resultado.txt
	python $(SRCDIR)comprobar_$(testing).py $(OUTDIR)resultado_parallelized.txt

dirs:
	mkdir $(OUTDIR)

clean:
	find . -iname "*~" -exec rm "{}" \;
	find . -iname "*.s" -exec rm "{}" \;
	find . -iname "*.o" -exec rm "{}" \;
	rm -rf $(OUTDIR)


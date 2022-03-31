PARFLOW_LIB=/home/jerom/parflow/lib/libpftools.so
build:
	gcc test.c bmi_parflow.c bmi_parflow_io.c bmi_parflow_advance.c ${PARFLOW_LIB}
	mv a.out test
	chmod 777 test
	./test
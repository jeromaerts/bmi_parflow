
LIB_DIR=/home/jerom/parflow/lib
#LIBRARIES= \
-L${LIB_DIR}/libpfsimulator.a \
-L${LIB_DIR}/libamps.a \
-L${LIB_DIR}/libcjson.a \
-L${LIB_DIR}/libpfkinsol.a \
-L${LIB_DIR}/libpfclm.a
LIBRARIES= \
${LIB_DIR}




LIB_NAME= \
-lpfsimulator \
-lamps \
-lcjson \
-lpfkinsol \
-lpfclm \
-lgfortran

#export LD_LIBRARY_PATH=/home/jerom/parflow/lib



INCLUDE_PATH= \
-I/home/jerom/parflow/pfsimulator/amps/mpi1 \
-I/home/jerom/parflow/pfsimulator/amps/common \
-I/home/jerom/parflow/pfsimulator/parflow_lib \
-I/home/jerom/build/include \
-I/usr/lib/openmpi/include \


Test:
	mpicc ${INCLUDE_PATH} -E bmi_parflow_io.c 


build:
	mpicc ${INCLUDE_PATH} test.c bmi_parflow.c bmi_parflow_io.c bmi_parflow_advance.c -L${LIB_DIR} ${LIB_NAME} -o test -lm
	#mpicc ${INCLUDE_PATH} test.c bmi_parflow.c bmi_parflow_io.c bmi_parflow_advance.c -l -lm -o test
	chmod 777 test
	./test
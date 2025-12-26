SOURCEMODULES = temp_api.c sensor_vector.c sensor_t.c
OBJECTMODULES = ${SOURCEMODULES:.c=.o}
CFLAGS = -g -Wall

%.o: %.c %.h
	${CC} ${CFLAGS} -c $< -o $@

prog: main.c ${OBJECTMODULES}
	${CC} ${CFLAGS} $^ -o $@

ifneq (clean, ${MAKECMDGOALS})
-include deps.mk
endif

deps.mk: ${SOURCEMODULES} main.c
	${CC} -MM $^ > $@

clean:
	rm -f *.o prog


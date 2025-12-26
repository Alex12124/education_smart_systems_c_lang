temp_api.o: temp_api.c temp_api.h sensor_t.h
sensor_vector.o: sensor_vector.c sensor_vector.h sensor_t.h
sensor_t.o: sensor_t.c sensor_t.h
main.o: main.c temp_api.h sensor_t.h sensor_vector.h

CC=gcc
CFLAGS=-O -Wall -W -pedantic -ansi -std=c99
DEBUG_SYMBOL=-g

all: exercise_1 exercise_2 exercise_3 exercise_4 exercise_5 exercise_6 exercise_8 exercise_11 exercise_12 exercise_13 exercise_14 exercise_15 exercise_16 exercise_17 exercise_18 exercise_19

debug: debug_exercise

exercise_1: exercise_1.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_2: exercise_2.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_3: exercise_3.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_4: exercise_4.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_5: exercise_5.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_6: exercise_6.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_8: exercise_8.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_11: exercise_11.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_12: exercise_12.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_13: exercise_13.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_14: exercise_14.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_15: exercise_15.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_16: exercise_16.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_17: exercise_17.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_18: exercise_18.c
	$(CC) $(CFLAGS) -o $@ $<

exercise_19: exercise_19.c
	$(CC) $(CFLAGS) -o $@ $<

debug_exercise: exercise_13.c
	$(CC) $(CFLAGS) $(DEBUG_SYMBOL) -o $@ $<

clean:
	rm exercise_1 exercise_2 exercise_3 exercise_4 exercise_5 exercise_6 exercise_8 exercise_11 exercise_12 exercise_13 exercise_14 exercise_15 exercise_16 exercise_17 exercise_18 exercise_19

clean_d:
	@echo "[PROGRESS] Removing debugging symbols directory"
	rm debug_exercise
	rm -r debug_exercise.dSYM
	@echo "[STATUS] Removed debug executable and symbols directory"

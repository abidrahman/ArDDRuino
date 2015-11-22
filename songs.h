const unsigned long mil = 1000000;

// song1: Numb by Linkin Park
const int bpm1 = 110; // beats per minute of song
const unsigned long start1 = 4.386*mil; //first even in song
const unsigned long bpm1_dt = 60.0 / 110.0 * mil; // time inbetween beats in microseconds

const prog_uint32_t song1[] PROGMEM = {
	start1, 1,
	start1 + bpm1_dt * 1.5, 3,
	start1 + bpm1_dt * 3, 2,
	start1 + bpm1_dt * 8, 4,
	start1 + bpm1_dt * 9.5, 3,
	start1 + bpm1_dt * 11, 1,
	start1 + bpm1_dt * 14.5, 1,
	start1 + bpm1_dt * 14.5, 3,
	start1 + bpm1_dt * 15, 2,
	start1 + bpm1_dt * 15, 4,
	start1 + bpm1_dt * 15.5, 1,
	start1 + bpm1_dt * 15.5, 3,
	start1 + bpm1_dt * 16, 1,
	start1 + bpm1_dt * 16, 2,
	start1 + bpm1_dt * 16.5, 2,
	start1 + bpm1_dt * 17, 2,
	start1 + bpm1_dt * 17.5, 1,
	start1 + bpm1_dt * 17.5, 4,
	start1 + bpm1_dt * 18, 4,
	start1 + bpm1_dt * 18.5, 4,
	start1 + bpm1_dt * 19, 1,
	start1 + bpm1_dt * 19, 3,
	start1 + bpm1_dt * 19.5, 3,
	start1 + bpm1_dt * 20, 1,
	start1 + bpm1_dt * 21, 3,
	start1 + bpm1_dt * 22.5, 1,
	start1 + bpm1_dt * 22.5, 3,
	start1 + bpm1_dt * 23, 2,
	start1 + bpm1_dt * 23, 4,
	start1 + bpm1_dt * 23.5, 1,
	start1 + bpm1_dt * 23.5, 3,
	start1 + bpm1_dt * 24, 1,
	start1 + bpm1_dt * 24, 4,
	start1 + bpm1_dt * 24.5, 4,
	start1 + bpm1_dt * 25, 4,
	start1 + bpm1_dt * 25.5, 1,
	start1 + bpm1_dt * 25.5, 3,
	start1 + bpm1_dt * 26, 3,
	start1 + bpm1_dt * 26.5, 3,
	start1 + bpm1_dt * 27, 1,
	start1 + bpm1_dt * 27, 2
};
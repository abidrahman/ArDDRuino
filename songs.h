const unsigned long mil = 1000000;

// song1: Numb by Linkin Park
const int bpm1 = 110; // beats per minute of song
const unsigned long start1 = 4.386*mil; //first even in song
const unsigned long bpm1_dt = 60.0 / 110.0 * mil; // time inbetween beats in microseconds
const unsigned long song1_length = start1 + bpm1_dt * 120;
const unsigned long song1_end = start1 + bpm1_dt * 130;

const prog_uint32_t song1[] PROGMEM = {
	start1, 1,
	start1 + bpm1_dt * 1.5, 3,
	start1 + bpm1_dt * 3, 2,
	start1 + bpm1_dt * 8, 4,
	start1 + bpm1_dt * 9.5, 3,
	start1 + bpm1_dt * 11, 1,
	start1 + bpm1_dt * 14.5, 1,
	start1 + bpm1_dt * 15, 2,
	start1 + bpm1_dt * 15.5, 1,
	start1 + bpm1_dt * 16, 1,
	start1 + bpm1_dt * 16, 2,
	start1 + bpm1_dt * 17.5, 1,
	start1 + bpm1_dt * 17.5, 4,
	start1 + bpm1_dt * 19, 1,
	start1 + bpm1_dt * 19, 3,
	start1 + bpm1_dt * 22.5, 1,
	start1 + bpm1_dt * 23, 2,
	start1 + bpm1_dt * 23.5, 1,
	start1 + bpm1_dt * 24, 1,
	start1 + bpm1_dt * 24, 4,
	start1 + bpm1_dt * 25.5, 1,
	start1 + bpm1_dt * 25.5, 3,
	start1 + bpm1_dt * 27, 1,
	start1 + bpm1_dt * 27, 2,
	start1 + bpm1_dt * 30.5, 1,
	start1 + bpm1_dt * 31, 2,
	start1 + bpm1_dt * 31.5, 1,
	start1 + bpm1_dt * 32, 2,
	start1 + bpm1_dt * 32, 4,
	start1 + bpm1_dt * 33, 3,
	start1 + bpm1_dt * 33.5, 3,
	start1 + bpm1_dt * 34, 3,
	start1 + bpm1_dt * 34.5, 3,
	start1 + bpm1_dt * 35, 4,
	start1 + bpm1_dt * 35.5, 3,
	start1 + bpm1_dt * 36.5, 3,
	start1 + bpm1_dt * 37, 2,
	start1 + bpm1_dt * 38, 1,
	start1 + bpm1_dt * 39.5, 1,
	start1 + bpm1_dt * 40, 4,
	start1 + bpm1_dt * 40.5, 4,
	start1 + bpm1_dt * 41, 3,
	start1 + bpm1_dt * 41.5, 2,
	start1 + bpm1_dt * 41.5, 3,
	start1 + bpm1_dt * 42.5, 3,
	start1 + bpm1_dt * 42.5, 4,
	start1 + bpm1_dt * 43.5, 1,
	start1 + bpm1_dt * 44, 4,
	start1 + bpm1_dt * 44.5, 4,
	start1 + bpm1_dt * 45, 3,
	start1 + bpm1_dt * 45.5, 2,
	start1 + bpm1_dt * 45.5, 3,
	start1 + bpm1_dt * 46.5, 3,
	start1 + bpm1_dt * 46.5, 4,
    start1 + bpm1_dt * 48.5, 1,
    start1 + bpm1_dt * 49, 3,
    start1 + bpm1_dt * 49.5, 3,
    start1 + bpm1_dt * 50, 3,
    start1 + bpm1_dt * 50.5, 3,
    start1 + bpm1_dt * 51, 4,
    start1 + bpm1_dt * 51.5, 3,
    start1 + bpm1_dt * 52.5, 3,
    start1 + bpm1_dt * 53, 2,
    start1 + bpm1_dt * 53.5, 1,
    start1 + bpm1_dt * 53.5, 2,
    start1 + bpm1_dt * 55.5, 1,
    start1 + bpm1_dt * 56, 4,
    start1 + bpm1_dt * 56.5, 4,
    start1 + bpm1_dt * 57, 3,
    start1 + bpm1_dt * 57.5, 2,
    start1 + bpm1_dt * 57.5, 3,
    start1 + bpm1_dt * 58.5, 1,
    start1 + bpm1_dt * 58.5, 2,
    start1 + bpm1_dt * 59.5, 1,
    start1 + bpm1_dt * 60, 4,
    start1 + bpm1_dt * 60.5, 3,
    start1 + bpm1_dt * 61.5, 1,
    start1 + bpm1_dt * 62.5, 3,
    start1 + bpm1_dt * 63.5, 4,
    start1 + bpm1_dt * 65, 1,
    start1 + bpm1_dt * 66, 2,
    start1 + bpm1_dt * 67, 3,
    start1 + bpm1_dt * 67.5, 4,
    start1 + bpm1_dt * 68, 1,
    start1 + bpm1_dt * 68.5, 2,
    start1 + bpm1_dt * 69, 3,
    start1 + bpm1_dt * 70, 4,
    start1 + bpm1_dt * 71, 3,
    start1 + bpm1_dt * 71.5, 3,
    start1 + bpm1_dt * 72, 4,
    start1 + bpm1_dt * 72.5, 4,
    start1 + bpm1_dt * 73, 3,
    start1 + bpm1_dt * 73.5, 1,
    start1 + bpm1_dt * 74.5, 1,
    start1 + bpm1_dt * 75, 1,
    start1 + bpm1_dt * 75.5, 4,
    start1 + bpm1_dt * 76.5, 4,
    start1 + bpm1_dt * 77, 3,
    start1 + bpm1_dt * 77.5, 2,
    start1 + bpm1_dt * 78.5, 3,
    start1 + bpm1_dt * 79.5, 4,
    start1 + bpm1_dt * 81, 1,
    start1 + bpm1_dt * 82, 2,
    start1 + bpm1_dt * 83, 3,
    start1 + bpm1_dt * 83.5, 4,
    start1 + bpm1_dt * 84, 1,
    start1 + bpm1_dt * 84.5, 2,
    start1 + bpm1_dt * 85, 3,
    start1 + bpm1_dt * 86, 4,
    start1 + bpm1_dt * 88, 1,
    start1 + bpm1_dt * 88, 3,
    start1 + bpm1_dt * 88, 4,
    start1 + bpm1_dt * 89.5, 1,
    start1 + bpm1_dt * 89.5, 4,
    start1 + bpm1_dt * 90, 1,
    start1 + bpm1_dt * 90, 4,
    start1 + bpm1_dt * 91, 1,
    start1 + bpm1_dt * 91, 3,
    start1 + bpm1_dt * 92, 1,
    start1 + bpm1_dt * 92, 4,
    start1 + bpm1_dt * 93, 2,
    start1 + bpm1_dt * 93.5, 2,
    start1 + bpm1_dt * 94, 2,
    start1 + bpm1_dt * 95, 2,
    start1 + bpm1_dt * 95, 4,
    start1 + bpm1_dt * 96, 1,
    start1 + bpm1_dt * 96, 3,
    start1 + bpm1_dt * 97, 3,
    start1 + bpm1_dt * 97.5, 3,
    start1 + bpm1_dt * 98, 3,
    start1 + bpm1_dt * 99, 2,
    start1 + bpm1_dt * 100, 1,
    start1 + bpm1_dt * 100, 3,
    start1 + bpm1_dt * 101, 1,
    start1 + bpm1_dt * 101.5, 2,
    start1 + bpm1_dt * 102, 3,
    start1 + bpm1_dt * 102.5,
    start1 + bpm1_dt * 103, 1,
    start1 + bpm1_dt * 103.5, 1,
    start1 + bpm1_dt * 104, 2,
    start1 + bpm1_dt * 104.5, 4,
    start1 + bpm1_dt * 106, 3,
    start1 + bpm1_dt * 106.5, 2,
    start1 + bpm1_dt * 107, 3,
    start1 + bpm1_dt * 108, 4,
    start1 + bpm1_dt * 109, 1,
    start1 + bpm1_dt * 109.5, 2,
    start1 + bpm1_dt * 110, 3,
    start1 + bpm1_dt * 110.5, 4,
    start1 + bpm1_dt * 111, 1,
    start1 + bpm1_dt * 112, 3,
    start1 + bpm1_dt * 112.5, 2,
    start1 + bpm1_dt * 113, 3,
    start1 + bpm1_dt * 114, 4,
    start1 + bpm1_dt * 115, 1,
    start1 + bpm1_dt * 115.5, 2,
    start1 + bpm1_dt * 116, 3,
    start1 + bpm1_dt * 116.5, 4,
    start1 + bpm1_dt * 117, 3,
    start1 + bpm1_dt * 117.5, 2,
    start1 + bpm1_dt * 118, 1,
    start1 + bpm1_dt * 119, 2,
    start1 + bpm1_dt * 120, 3,
    start1 + bpm1_dt * 121, 4,
    start1 + bpm1_dt * 122, 4,
    start1 + bpm1_dt * 123, 4,
    start1 + bpm1_dt * 124, 4,
    start1 + bpm1_dt * 125, 4,
    start1 + bpm1_dt * 126, 4,
    
};

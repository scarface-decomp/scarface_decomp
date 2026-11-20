// bin: xb
// va: 0x00026740
// what: Rounds a float down to the nearest whole number (the C++ floorf overload from <math.h>).
// tool: Claude Opus 5.5

// The original is the Toolkit's own header inline, <math.h>'s floorf(float), emitted out of line
// because something takes or keeps a call to it that the compiler did not inline.
#include <math.h>

// Taking floorf's address makes the compiler emit the header's copy of it.
float (*g_FloorF)(float) = floorf;

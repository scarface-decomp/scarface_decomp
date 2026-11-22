// bin: proto
// va: 0x000550D0
// what: 
// tool: the portal's starter code (no AI)

// sub_000550D0 (Proto 0x000550D0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CD94;
extern "C" float DAT_0037CE50;
extern "C" float DAT_003AB1D0;

float __cdecl sub_000550D0(float a1)
{
    if (0.0f >= a1) {
        return DAT_0037CD94;
    }
    if (a1 >= DAT_0037CE50) {
        return DAT_0037CE50;
    }
    return (DAT_003AB1D0 - (a1 + a1)) * a1 * a1;
}

// bin: xb
// va: 0x0005F990
// tool: the portal's starter code (no AI)
// sub_0005F990 (0x0005F990, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;
extern "C" float DAT_0039D664;
extern "C" float DAT_003C7E40;

float __cdecl sub_0005F990(float a1)
{
    if (0.0f >= a1) {
        return DAT_0039D584;
    }
    if (a1 >= DAT_0039D664) {
        return DAT_0039D664;
    }
    return (DAT_003C7E40 - (a1 + a1)) * a1 * a1;
}

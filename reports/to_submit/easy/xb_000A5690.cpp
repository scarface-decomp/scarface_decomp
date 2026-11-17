// bin: xb
// va: 0x000A5690
// tool: the portal's starter code (no AI)
// sub_000A5690 (0x000A5690, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D584;
extern "C" float DAT_0039D664;
extern "C" float DAT_0039D850;

float __cdecl sub_000A5690(float a1)
{
    if (a1 > DAT_0039D850) {
        return DAT_0039D664;
    }
    return DAT_0039D584;
}

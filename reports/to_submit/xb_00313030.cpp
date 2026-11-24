// bin: xb
// va: 0x00313030
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00313030 (0x00313030, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0041C448;
extern "C" float DAT_00474B30;

void __cdecl sub_00313030(void)
{
    float t1;

    t1 = DAT_0041C448;
    DAT_00474B30 = t1 * t1;
}

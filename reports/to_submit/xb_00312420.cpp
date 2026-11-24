// bin: xb
// va: 0x00312420
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00312420 (0x00312420, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0041ABE8[];
extern "C" char sub_00322750[];
extern "C" void __cdecl sub_00073400(int);
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00312420(void)
{
    sub_00073400((int)DAT_0041ABE8);
    sub_002FBBEF((int)sub_00322750);
}

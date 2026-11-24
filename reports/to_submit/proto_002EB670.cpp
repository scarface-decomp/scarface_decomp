// bin: proto
// va: 0x002EB670
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EB670 (Proto 0x002EB670, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00426F18[];
extern "C" char sub_002F76B0[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EB670(void)
{
    sub_00068E40((int)DAT_00426F18);
    sub_002C8EB3((int)sub_002F76B0);
}

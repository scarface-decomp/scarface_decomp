// bin: proto
// va: 0x002EAA20
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002EAA20 (Proto 0x002EAA20, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_004211C0[];
extern "C" char sub_002F68F0[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002EAA20(void)
{
    sub_00068E40((int)DAT_004211C0);
    sub_002C8EB3((int)sub_002F68F0);
}

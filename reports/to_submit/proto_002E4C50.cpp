// bin: proto
// va: 0x002E4C50
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E4C50 (Proto 0x002E4C50, 24 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00403B60[];
extern "C" char sub_002F19D0[];
extern "C" void __cdecl sub_00068E40(int);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E4C50(void)
{
    sub_00068E40((int)DAT_00403B60);
    sub_002C8EB3((int)sub_002F19D0);
}

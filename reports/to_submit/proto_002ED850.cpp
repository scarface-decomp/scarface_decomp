// bin: proto
// va: 0x002ED850
// what: Start-up code (a static initializer): runs once before the game starts, setting up one of its global objects.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED850 (Proto 0x002ED850, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_002F78C0[];
extern "C" void __cdecl sub_0020DC30(void);
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002ED850(void)
{
    sub_0020DC30();
    sub_002C8EB3((int)sub_002F78C0);
}

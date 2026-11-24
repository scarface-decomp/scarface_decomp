// bin: proto
// va: 0x002ED600
// what: Start-up code (a static initializer): has a static object's destructor run when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002ED600 (Proto 0x002ED600, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_002F78A0[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002ED600(void)
{
    sub_002C8EB3((int)sub_002F78A0);
}

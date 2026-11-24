// bin: proto
// va: 0x002E8A00
// what: Start-up code (a static initializer): has a static object's destructor run when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002E8A00 (Proto 0x002E8A00, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_002F4860[];
extern "C" void __cdecl sub_002C8EB3(int);

void __cdecl sub_002E8A00(void)
{
    sub_002C8EB3((int)sub_002F4860);
}

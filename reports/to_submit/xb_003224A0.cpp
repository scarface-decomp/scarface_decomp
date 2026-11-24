// bin: xb
// va: 0x003224A0
// what: Start-up code (a static initializer): has a static object's destructor run when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_003224A0 (0x003224A0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char sub_00329430[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003224A0(void)
{
    sub_002FBBEF((int)sub_00329430);
}

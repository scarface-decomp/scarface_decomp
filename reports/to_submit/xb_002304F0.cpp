// bin: xb
// va: 0x002304F0
// what: 
// tool: the portal's starter code (no AI)

// sub_002304F0 (0x002304F0, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002240B0(int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_002304F0(int a1)
{
    ((Object*)DAT_00491EF8)->sub_002240B0(a1);
}

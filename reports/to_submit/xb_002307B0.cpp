// bin: xb
// va: 0x002307B0
// what: 
// tool: the portal's starter code (no AI)

// sub_002307B0 (0x002307B0, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002242F0();
};

extern "C" int DAT_00491EF8;

void __cdecl sub_002307B0(void)
{
    ((Object*)DAT_00491EF8)->sub_002242F0();
}

// bin: xb
// va: 0x001E59B0
// what: 
// tool: the portal's starter code (no AI)

// sub_001E59B0 (0x001E59B0, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_001E3DD0();
};

extern "C" void __cdecl sub_00099C10(int);

void __cdecl sub_001E59B0(int a1)
{
    a1 = ((Object*)a1)->sub_001E3DD0();
    sub_00099C10(a1);
}

// bin: xb
// va: 0x00230790
// what: 
// tool: the portal's starter code (no AI)

// sub_00230790 (0x00230790, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002256D0(int, int);
};

extern "C" int DAT_00491EF8;

void __cdecl sub_00230790(int a1, int a2, int a3)
{
    ((Object*)DAT_00491EF8)->sub_002256D0(*(int*)(a3 + 4), 0);
}

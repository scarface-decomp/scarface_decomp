// bin: xb
// va: 0x001E5790
// what: 
// tool: the portal's starter code (no AI)

// sub_001E5790 (0x001E5790, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E3970();
};

extern "C" int __cdecl sub_001E3AA0(void);

void __cdecl sub_001E5790(void)
{
    ((Object*)sub_001E3AA0())->sub_001E3970();
}

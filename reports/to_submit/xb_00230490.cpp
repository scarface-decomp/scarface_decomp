// bin: xb
// va: 0x00230490
// what: 
// tool: the portal's starter code (no AI)

// sub_00230490 (0x00230490, 17 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001E8730(int);
};

extern "C" int DAT_0048F740;

void __cdecl sub_00230490(int a1)
{
    ((Object*)DAT_0048F740)->sub_001E8730(a1);
}

// bin: xb
// va: 0x00322EE0
// what: 
// tool: the portal's starter code (no AI)

// sub_00322EE0 (0x00322EE0, 20 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE560();
};

extern "C" Object DAT_00480FF8;
extern "C" Object DAT_00481008;

void __cdecl sub_00322EE0(void)
{
    DAT_00481008.sub_002CE560();
    DAT_00480FF8.sub_002CE560();
}

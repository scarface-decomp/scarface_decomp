// bin: xb
// va: 0x00324B20
// what: 
// tool: the portal's starter code (no AI)

// sub_00324B20 (0x00324B20, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001204E0();
    void sub_002CE560();
};

extern "C" Object DAT_0048ABC8;
extern "C" Object DAT_0048ABD8;
extern "C" Object DAT_0048ABF4;

void __cdecl sub_00324B20(void)
{
    DAT_0048ABF4.sub_001204E0();
    DAT_0048ABD8.sub_002CE560();
    DAT_0048ABC8.sub_002CE560();
}

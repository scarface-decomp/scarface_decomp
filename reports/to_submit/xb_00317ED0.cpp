// bin: xb
// va: 0x00317ED0
// what: 
// tool: the portal's starter code (no AI)

// sub_00317ED0 (0x00317ED0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016FE60();
};

extern "C" Object DAT_0048AA38;
extern "C" char sub_00324AE0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00317ED0(void)
{
    DAT_0048AA38.sub_0016FE60();
    sub_002FBBEF((int)sub_00324AE0);
}

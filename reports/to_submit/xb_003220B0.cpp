// bin: xb
// va: 0x003220B0
// what: 
// tool: the portal's starter code (no AI)

// sub_003220B0 (0x003220B0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D4B70();
};

extern "C" Object DAT_004BFF08;
extern "C" char sub_00329350[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003220B0(void)
{
    DAT_004BFF08.sub_002D4B70();
    sub_002FBBEF((int)sub_00329350);
}

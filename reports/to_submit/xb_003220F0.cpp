// bin: xb
// va: 0x003220F0
// what: 
// tool: the portal's starter code (no AI)

// sub_003220F0 (0x003220F0, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002D4B70();
};

extern "C" Object DAT_004BFF1C;
extern "C" char sub_00329370[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003220F0(void)
{
    DAT_004BFF1C.sub_002D4B70();
    sub_002FBBEF((int)sub_00329370);
}

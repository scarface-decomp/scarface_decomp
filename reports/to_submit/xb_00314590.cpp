// bin: xb
// va: 0x00314590
// what: 
// tool: the portal's starter code (no AI)

// sub_00314590 (0x00314590, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE3C0(int, int);
};

extern "C" char DAT_003A3348[];
extern "C" Object DAT_00480FBC;
extern "C" char sub_00322EB0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00314590(void)
{
    DAT_00480FBC.sub_002CE3C0((int)DAT_003A3348, 0);
    sub_002FBBEF((int)sub_00322EB0);
}

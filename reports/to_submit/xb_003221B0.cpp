// bin: xb
// va: 0x003221B0
// what: 
// tool: the portal's starter code (no AI)

// sub_003221B0 (0x003221B0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE3C0(int, int);
};

extern "C" char DAT_003E00BC[];
extern "C" Object DAT_004C01D8;
extern "C" char sub_003293D0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003221B0(void)
{
    DAT_004C01D8.sub_002CE3C0((int)DAT_003E00BC, 0);
    sub_002FBBEF((int)sub_003293D0);
}

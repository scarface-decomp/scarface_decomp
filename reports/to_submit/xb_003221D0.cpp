// bin: xb
// va: 0x003221D0
// what: 
// tool: the portal's starter code (no AI)

// sub_003221D0 (0x003221D0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE3C0(int, int);
};

extern "C" char DAT_003E016C[];
extern "C" Object DAT_004C021C;
extern "C" char sub_003293E0[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_003221D0(void)
{
    DAT_004C021C.sub_002CE3C0((int)DAT_003E016C, 0);
    sub_002FBBEF((int)sub_003293E0);
}

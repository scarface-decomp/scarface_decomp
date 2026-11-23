// bin: xb
// va: 0x00322200
// what: 
// tool: the portal's starter code (no AI)

// sub_00322200 (0x00322200, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_002CE3C0(int, int);
};

extern "C" char DAT_0039D444[];
extern "C" Object DAT_004C0430;
extern "C" char sub_00329400[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00322200(void)
{
    DAT_004C0430.sub_002CE3C0((int)DAT_0039D444, 0);
    sub_002FBBEF((int)sub_00329400);
}

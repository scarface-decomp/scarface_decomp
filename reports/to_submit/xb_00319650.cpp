// bin: xb
// va: 0x00319650
// what: 
// tool: the portal's starter code (no AI)

// sub_00319650 (0x00319650, 22 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0009A390();
};

extern "C" Object DAT_0048C2A0;
extern "C" char sub_00325150[];
extern "C" void __cdecl sub_002FBBEF(int);

void __cdecl sub_00319650(void)
{
    DAT_0048C2A0.sub_0009A390();
    sub_002FBBEF((int)sub_00325150);
}

// bin: xb
// va: 0x003243A0
// what: 
// tool: the portal's starter code (no AI)

// sub_003243A0 (0x003243A0, 21 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00242120(int, int);
};

extern "C" Object DAT_00489FAC;
extern "C" char sub_00107BC0[];

void __cdecl sub_003243A0(void)
{
    DAT_00489FAC.sub_00242120((int)sub_00107BC0, (int)&DAT_00489FAC);
}

// bin: proto
// va: 0x0018A540
// what: 
// tool: the portal's starter code (no AI)

// sub_0018A540 (Proto 0x0018A540, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016EF30(int, int, int);
};

extern "C" int DAT_0045E07C;

void __cdecl sub_0018A540(void)
{
    ((Object*)DAT_0045E07C)->sub_0016EF30(-1, 0, 0);
}

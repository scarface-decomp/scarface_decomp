// bin: proto
// va: 0x0016EC80
// what: 
// tool: the portal's starter code (no AI)

// sub_0016EC80 (Proto 0x0016EC80, 25 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0016ED30(int);
    void sub_001867A0();
};

extern "C" int DAT_0045E07C;

void __cdecl sub_0016EC80(void)
{
    int t1;

    t1 = ((Object*)DAT_0045E07C)->sub_0016ED30(52);
    if (t1) {
        ((Object*)t1)->sub_001867A0();
        return;
    }
}

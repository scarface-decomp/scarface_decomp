// bin: proto
// va: 0x001979D0
// tool: the portal's starter code (no AI)
// sub_001979D0 (0x001979D0, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001C4030(int, int, int, int);
};

extern "C" int DAT_004601C0[];
extern "C" bool DAT_0046021C;

void __stdcall sub_001979D0(int a1, int a2, int a3, int a4, int a5)
{
    if (DAT_0046021C) {
        if (!DAT_004601C0[a1]) goto L_31;
        ((Object*)DAT_004601C0[a1])->sub_001C4030(a2, a3, a4, a5);
    }
L_31:
    ;
}

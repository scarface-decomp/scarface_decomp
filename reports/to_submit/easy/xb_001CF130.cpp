// bin: xb
// va: 0x001CF130
// tool: the portal's starter code (no AI)
// sub_001CF130 (0x001CF130, 52 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_001FF590(int, int, int, int);
};

extern "C" int DAT_0048EC30[];
extern "C" bool DAT_0048EC9C;

void __stdcall sub_001CF130(int a1, int a2, int a3, int a4, int a5)
{
    if (DAT_0048EC9C) {
        if (!DAT_0048EC30[a1]) goto L_31;
        ((Object*)DAT_0048EC30[a1])->sub_001FF590(a2, a3, a4, a5);
    }
L_31:
    ;
}

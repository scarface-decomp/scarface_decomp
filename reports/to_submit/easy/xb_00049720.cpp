// bin: xb
// va: 0x00049720
// tool: the portal's starter code (no AI)
// sub_00049720 (0x00049720, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000546B0(int);
};

void __cdecl sub_00049720(int a1, int a2)
{
    if (a1) {
        if (*(int*)(*(int*)(a1 + 4) + 84) != 512) goto L_1E;
        ((Object*)*(int*)(a1 + 4))->sub_000546B0(a2);
    }
L_1E:
    ;
}

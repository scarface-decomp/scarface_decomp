// bin: xb
// va: 0x00077900
// tool: the portal's starter code (no AI)
// sub_00077900 (0x00077900, 26 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000819A0(int);
};

extern "C" int DAT_00480FA8;

void __cdecl sub_00077900(int a1)
{
    if (*(int*)(DAT_00480FA8 + 292)) {
        ((Object*)*(int*)(DAT_00480FA8 + 292))->sub_000819A0(a1);
    }
}

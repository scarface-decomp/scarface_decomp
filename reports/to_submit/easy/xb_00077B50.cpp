// bin: xb
// va: 0x00077B50
// tool: the portal's starter code (no AI)
// sub_00077B50 (0x00077B50, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" int DAT_00480FA8;

void __cdecl sub_00077B50(void)
{
    int t1;

    t1 = *(int*)(DAT_00480FA8 + 284);
    if (*(int*)(DAT_00480FA8 + 284)) {
        ((Object*)t1)->vfunc_00(1);
        *(int*)(DAT_00480FA8 + 284) = 0;
    }
}

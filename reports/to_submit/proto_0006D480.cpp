// bin: proto
// va: 0x0006D480
// what: 
// tool: the portal's starter code (no AI)

// sub_0006D480 (Proto 0x0006D480, 37 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" int DAT_00453744;

void __cdecl sub_0006D480(void)
{
    int t1;

    t1 = *(int*)(DAT_00453744 + 292);
    if (*(int*)(DAT_00453744 + 292)) {
        ((Object*)t1)->vfunc_00(1);
        *(int*)(DAT_00453744 + 292) = 0;
    }
}

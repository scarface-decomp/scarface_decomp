// bin: proto
// va: 0x002F27C0
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F27C0 (Proto 0x002F27C0, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int);
};

extern "C" int DAT_0045BFF0;
extern "C" int DAT_0045BFF4;
extern "C" int DAT_0045BFFC;
extern "C" void __cdecl sub_001098C0(int, int);

void __cdecl sub_002F27C0(void)
{
    int t2;

    sub_001098C0(DAT_0045BFF0, DAT_0045BFF4);
    t2 = DAT_0045BFF0;
    DAT_0045BFF4 = DAT_0045BFF0;
    if (DAT_0045BFF0) {
        ((Object*)DAT_0045BFFC)->vfunc_05(t2);
    }
    ((Object*)DAT_0045BFFC)->vfunc_01();
}

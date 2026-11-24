// bin: xb
// va: 0x00324400
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_00324400 (0x00324400, 37 bytes)
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

extern "C" int DAT_0048A0F8;
extern "C" int DAT_0048A0FC;
extern "C" int DAT_0048A104;

void __cdecl sub_00324400(void)
{
    int t1;

    t1 = DAT_0048A0F8;
    DAT_0048A0FC = DAT_0048A0F8;
    if (DAT_0048A0F8) {
        ((Object*)DAT_0048A104)->vfunc_05(t1);
    }
    ((Object*)DAT_0048A104)->vfunc_01();
}

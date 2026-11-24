// bin: proto
// va: 0x002F2880
// what: Shutdown code (an atexit stub): destroys one of the game's static objects when the game exits.
// how: shape
// tool: the portal's starter code (no AI)

// sub_002F2880 (Proto 0x002F2880, 37 bytes)
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

extern "C" int DAT_0045C2BC;
extern "C" int DAT_0045C2C0;
extern "C" int DAT_0045C2C8;

void __cdecl sub_002F2880(void)
{
    int t1;

    t1 = DAT_0045C2BC;
    DAT_0045C2C0 = DAT_0045C2BC;
    if (DAT_0045C2BC) {
        ((Object*)DAT_0045C2C8)->vfunc_05(t1);
    }
    ((Object*)DAT_0045C2C8)->vfunc_01();
}

// bin: xb
// va: 0x001AE890
// tool: the portal's starter code (no AI)
// ViceCopHUD::vfunc_01 (0x001AE890, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int, int);
};

extern "C" char DAT_003BF55C[];

class ViceCopHUD
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
};

void ViceCopHUD::vfunc_01()
{
    int r_ecx;

    r_ecx = (int)this;
    if (!(*(unsigned char*)(r_ecx + -8) & 16)) {
        if (!*(int*)(r_ecx + 24)) goto L_1C;
    }
    r_ecx = *(int*)(r_ecx + 24);
    ((Object*)r_ecx)->vfunc_03(0, (int)DAT_003BF55C);
L_1C:
    ;
}

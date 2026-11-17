// bin: xb
// va: 0x00247880
// tool: the portal's starter code (no AI)
// core::ControllerSystemXBox::vfunc_07 (0x00247880, 88 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08(int, int);
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21(int, int);
};

namespace core {

class ControllerSystemXBox
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07(int a1);
};

void ControllerSystemXBox::vfunc_07(int a1)
{
    int r_ebp, r_ebx, r_edi, r_esi;

    r_edi = a1;
    r_esi = (int)this;
    if (!a1) {
        *(bool*)(r_esi + 16) = false;
        ((Object*)r_esi)->vfunc_08(a1, a1);
        r_edi = 10;
    } else {
        *(bool*)(r_esi + 16) = true;
    }
    r_ebp = *(int*)(r_esi + 4768);
    *(int*)(r_esi + 24) = r_edi;
    r_esi += 32;
    r_ebx = 4;
    do {
        if (*(bool*)(r_esi + 1182)) {
            ((Object*)r_esi)->vfunc_21(r_edi, r_ebp);
        }
        r_esi += 1184;
        r_ebx -= 1;
    } while (r_ebx);
}

}

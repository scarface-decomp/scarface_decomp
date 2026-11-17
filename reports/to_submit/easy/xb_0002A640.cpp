// bin: xb
// va: 0x0002A640
// tool: the portal's starter code (no AI)
// PositionSetObject::vfunc_25 (0x0002A640, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC50(void);
extern "C" bool __cdecl sub_0002CA90(int, int, int);

class PositionSetObject
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
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
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual bool vfunc_25(int a1);
};

bool PositionSetObject::vfunc_25(int a1)
{
    int r_ecx, r_esi, t1;

    r_ecx = (int)this;
    r_esi = (int)this;
    t1 = sub_0002AC50();
    r_ecx = a1;
    if (t1 == a1) {
        return true;
    }
    r_esi += 44;
    return sub_0002CA90(r_ecx, r_esi, 2);
}

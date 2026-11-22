// bin: proto
// va: 0x0004C7E0
// what: 
// tool: the portal's starter code (no AI)

// renderer::OceanPrimitive::vfunc_13 (Proto 0x0004C7E0, 38 bytes)
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
    virtual void vfunc_22(int);
};

extern "C" float DAT_0037FEAC;
extern "C" int __cdecl sub_00040CD0(void);

namespace renderer {

class OceanPrimitive
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
    char m_pad04[0x24];
    int m_Field28; // +0x28
    char m_pad2C[0x8];
    float m_Field34; // +0x34
};

void OceanPrimitive::vfunc_13()
{
    int t1;

    t1 = sub_00040CD0();
    if (t1) {
        ((Object*)t1)->vfunc_22((int)(&m_Field28));
        m_Field34 = DAT_0037FEAC;
    }
}

}

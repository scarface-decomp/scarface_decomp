// bin: xb
// va: 0x00055E80
// tool: the portal's starter code (no AI)
// renderer::WorldGeoRenderable::vfunc_15 (0x00055E80, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

namespace renderer {

class WorldGeoRenderable
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
    virtual bool vfunc_15(int a1);
    char m_pad04[0x80];
    int m_Field84; // +0x84
    int m_Field88; // +0x88
    int m_Field8C; // +0x8C
    unsigned char m_Field90_bit0 : 1; // +0x90, bit 0
};

bool WorldGeoRenderable::vfunc_15(int a1)
{
    *(int*)a1 = m_Field84;
    *(int*)(a1 + 4) = m_Field88;
    *(int*)(a1 + 8) = m_Field8C;
    return m_Field90_bit0;
}

}

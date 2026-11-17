// bin: proto
// va: 0x0023C550
// tool: the portal's starter code (no AI)
// pure3d::prop::StateProp::vfunc_09 (0x0023C550, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field98
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
    virtual bool vfunc_09();
};

namespace pure3d { namespace prop {

class StateProp
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
    virtual int vfunc_09();
    char m_pad04[0x94];
    Field98* m_Field98; // +0x98
    char m_pad9C[0x8C];
    unsigned short m_Field128; // +0x128
};

int StateProp::vfunc_09()
{
    if (!m_Field128) {
        if (!m_Field98->vfunc_09()) goto L_1F;
        return 1;
    }
L_1F:
    return 0;
}

} }

// bin: proto
// va: 0x00102F90
// what: 
// tool: the portal's starter code (no AI)

// sub_00102F90 (Proto 0x00102F90, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00102F90
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    void sub_00102F90();
    bool m_Field04; // +0x04
};

void Class_00102F90::sub_00102F90()
{
    if (m_Field04) {
        vfunc_04();
        vfunc_05();
        m_Field04 = false;
    }
}

// bin: xb
// va: 0x00200D90
// tool: the portal's starter code (no AI)
// BoatArtTemplate::vfunc_04 (0x00200D90, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0020C840(int);

class BoatArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_00200C50();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void BoatArtTemplate::vfunc_04(int a1)
{
    sub_0020C840(a1);
    if (m_Field22) {
        sub_00200C50();
    }
}

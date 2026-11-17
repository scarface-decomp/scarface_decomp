// bin: xb
// va: 0x00200430
// tool: the portal's starter code (no AI)
// AirplaneArtTemplate::vfunc_04 (0x00200430, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0020C840(int);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_00200380();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void AirplaneArtTemplate::vfunc_04(int a1)
{
    sub_0020C840(a1);
    if (m_Field22) {
        sub_00200380();
    }
}

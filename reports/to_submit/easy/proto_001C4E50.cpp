// bin: proto
// va: 0x001C4E50
// tool: the portal's starter code (no AI)
// AirplaneArtTemplate::vfunc_05 (0x001C4E50, 31 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_001D1320(int);

class AirplaneArtTemplate
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(int a1);
    void sub_001C4DA0();
    char m_pad04[0x1E];
    bool m_Field22; // +0x22
};

void AirplaneArtTemplate::vfunc_05(int a1)
{
    sub_001D1320(a1);
    if (m_Field22) {
        sub_001C4DA0();
    }
}

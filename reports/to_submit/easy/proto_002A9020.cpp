// bin: proto
// va: 0x002A9020
// tool: the portal's starter code (no AI)
// audio::SeqActionSilence::vfunc_02 (0x002A9020, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __stdcall sub_0029E790(int, int);

namespace audio {

class SeqActionSilence
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02(int a1, bool a2);
    char m_pad04[0xC];
    int m_Field10; // +0x10
};

void SeqActionSilence::vfunc_02(int a1, bool a2)
{
    sub_0029E790(2, a1);
    if (a2) {
        m_Field10 = 0;
    }
}

}

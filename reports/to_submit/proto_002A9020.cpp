// bin: proto
// va: 0x002A9020
// what: Sends command 2 with the value given and, when asked to, clears the number at +0x10.
// tool: Claude Opus 5.5 (transplanted from xb:0x002DCAA0, nearest by portal/tools/similar.py)
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
    int r_eax;

    r_eax = a1;
    sub_0029E790(2, a1);
    r_eax = a2;
    if (a2) {
        m_Field10 = 0;
    }
}

}
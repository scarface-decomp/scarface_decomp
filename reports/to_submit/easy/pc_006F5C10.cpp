// bin: pc
// va: 0x006F5C10
// tool: the portal's starter code (no AI)
// audio::SeqEventTypeBase::vfunc_00 (0x006F5C10, 61 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006EBBD0();
};

struct Object
{
    void sub_006F2A40(int);
};

extern "C" char DAT_00772DEC[];
extern "C" Object DAT_0085D4D8;
extern "C" void __cdecl sub_0043CE70(int);

namespace audio {

class SeqEventTypeBase
{
public:
    virtual SeqEventTypeBase* vfunc_00(int a1);
    int m_Field04; // +0x04
    char m_pad08[0xC];
    Field20 m_Field14; // +0x14
    char m_pad15[0xB];
    Field20 m_Field20; // +0x20
};

SeqEventTypeBase* SeqEventTypeBase::vfunc_00(int a1)
{
    *(int*)this = (int)DAT_00772DEC;
    DAT_0085D4D8.sub_006F2A40((int)(&m_Field04));
    m_Field20.sub_006EBBD0();
    m_Field14.sub_006EBBD0();
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

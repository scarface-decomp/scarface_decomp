// bin: pc
// va: 0x006EDE70
// tool: the portal's starter code (no AI)
// om::ContentStream::vfunc_00 (0x006EDE70, 45 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00();
    virtual void vfunc_01();
};

extern "C" char DAT_0073C2A8[];
extern "C" char DAT_00772678[];
extern "C" void __cdecl sub_0043CE70(int);

namespace om {

class ContentStream
{
public:
    virtual ContentStream* vfunc_00(int a1);
    char m_pad04[0x1C];
    int m_Field20; // +0x20
};

ContentStream* ContentStream::vfunc_00(int a1)
{
    int t1;

    t1 = m_Field20;
    *(int*)this = (int)DAT_00772678;
    ((Object*)t1)->vfunc_01();
    *(int*)this = (int)DAT_0073C2A8;
    if (a1 & 1) {
        sub_0043CE70((int)this);
    }
    return this;
}

}

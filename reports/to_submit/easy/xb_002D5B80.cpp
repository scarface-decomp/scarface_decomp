// bin: xb
// va: 0x002D5B80
// tool: the portal's starter code (no AI)
// audio::OmHalStream::vfunc_03 (0x002D5B80, 13 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002D3510(int);

namespace audio {

class OmHalStream
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03();
};

int OmHalStream::vfunc_03()
{
    return sub_002D3510((int)this + 12);
}

}

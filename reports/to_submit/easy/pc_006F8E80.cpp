// bin: pc
// va: 0x006F8E80
// tool: the portal's starter code (no AI)
// audio::SeqEventChannelVolumes::vfunc_00 (0x006F8E80, 86 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006ED500(int, int);
extern "C" bool __cdecl sub_006F33D0(int, int);
extern "C" bool __stdcall sub_006F5740(int);
extern "C" bool __cdecl sub_006F8D60(int, int);

namespace audio {

class SeqEventChannelVolumes
{
public:
    virtual int vfunc_00(int a1);
    char m_pad04[0x14];
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
};

int SeqEventChannelVolumes::vfunc_00(int a1)
{
    if (sub_006F5740(a1)) {
        if (!sub_006F33D0(a1, (int)(&m_Field18))) goto L_4F;
        if (!sub_006ED500(a1, (int)(&m_Field1C))) goto L_4F;
        if (!sub_006F8D60(a1, (int)this + 8)) goto L_4F;
        return 1;
    }
L_4F:
    return 0;
}

}

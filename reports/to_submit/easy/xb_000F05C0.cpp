// bin: xb
// va: 0x000F05C0
// tool: the portal's starter code (no AI)
// WatchRunningPed::vfunc_07 (0x000F05C0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field14
{
    bool sub_000CA1C0();
    void sub_000CA300(int, int);
};

extern "C" int __cdecl sub_0002AC90(int);

class WatchRunningPed
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual int vfunc_07();
    bool sub_000F0390(int, int);
    char m_pad04[0xC];
    int m_Field10; // +0x10
    Field14 m_Field14; // +0x14
};

int WatchRunningPed::vfunc_07()
{
    int t2;

    t2 = sub_0002AC90(m_Field10);
    if (sub_000F0390(t2, t2 + 100)) {
        m_Field14.sub_000CA300(700, 1500);
    }
    return !m_Field14.sub_000CA1C0();
}

// bin: proto
// va: 0x000A02F0
// tool: the portal's starter code (no AI)
// sub_000A02F0 (0x000A02F0, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    virtual void vfunc_00(int);
};

extern "C" char DAT_00384428[];
extern "C" int __cdecl sub_00028120(int);
extern "C" void __cdecl sub_00066030(int, int, int);

class Class_000A02F0
{
public:
    void sub_000A02F0(int a1);
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x454];
    unsigned char m_Field460; // +0x460
    char m_pad461[0x3];
    int m_Field464; // +0x464
};

void Class_000A02F0::sub_000A02F0(int a1)
{
    int t1;

    if (m_Field460 != ((unsigned char)a1)) {
        t1 = m_Field464;
        m_Field460 = (unsigned char)a1;
        if (m_Field464) {
            ((Object*)t1)->vfunc_00(a1);
        }
        if (!sub_00028120(m_Field08)) goto L_50;
        sub_00066030(sub_00028120(m_Field08), 1, (int)DAT_00384428);
    }
L_50:
    ;
}

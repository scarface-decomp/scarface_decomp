// bin: proto
// va: 0x000293E0
// tool: the portal's starter code (no AI)
// CollisionBehaviourTypeGroup::vfunc_04 (0x000293E0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0006C370(int, int);

class CollisionBehaviourTypeGroup
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04(int a1);
    void sub_00028C40(int);
    int m_Field04; // +0x04
    char m_pad08[0x4];
    int m_Field0C; // +0x0C
    char m_pad10[0xE];
    unsigned char m_Field1E; // +0x1E
};

void CollisionBehaviourTypeGroup::vfunc_04(int a1)
{
    if (a1) {
        if (!*(unsigned char*)a1) goto L_25;
        m_Field04 = sub_0006C370(a1, 0);
        m_Field0C = 0;
    }
L_25:
    if (m_Field1E & 2) {
        sub_00028C40(0);
    }
}

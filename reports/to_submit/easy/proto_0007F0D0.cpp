// bin: proto
// va: 0x0007F0D0
// tool: the portal's starter code (no AI)
// sub_0007F0D0 (0x0007F0D0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002014E0(int, int);

class Class_0007F0D0
{
public:
    Class_0007F0D0* sub_0007F0D0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_0007F0D0* Class_0007F0D0::sub_0007F0D0(int a1)
{
    m_Field00 = 0;
    m_Field04 = 0;
    if (a1) {
        if (!*(unsigned char*)a1) goto L_2B;
        m_Field04 = sub_002014E0(a1, 0);
    }
L_2B:
    return this;
}

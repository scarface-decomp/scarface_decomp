// bin: proto
// va: 0x000893B0
// tool: the portal's starter code (no AI)
// sub_000893B0 (0x000893B0, 42 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_00383978[];
extern "C" int __cdecl sub_002014E0(int, int);

class Class_000893B0
{
public:
    Class_000893B0* sub_000893B0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_000893B0* Class_000893B0::sub_000893B0(int a1)
{
    m_Field00 = (int)DAT_00383978;
    if (a1) {
        if (!*(unsigned char*)a1) goto L_24;
        m_Field04 = sub_002014E0(a1, 0);
    }
L_24:
    return this;
}

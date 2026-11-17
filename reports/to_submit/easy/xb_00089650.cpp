// bin: xb
// va: 0x00089650
// tool: the portal's starter code (no AI)
// sub_00089650 (0x00089650, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00244040(int, int);

class Class_00089650
{
public:
    Class_00089650* sub_00089650(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_00089650* Class_00089650::sub_00089650(int a1)
{
    m_Field00 = 0;
    m_Field04 = 0;
    if (a1) {
        if (!*(unsigned char*)a1) goto L_2B;
        m_Field04 = sub_00244040(a1, 0);
    }
L_2B:
    return this;
}

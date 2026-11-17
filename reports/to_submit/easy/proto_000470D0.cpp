// bin: proto
// va: 0x000470D0
// tool: the portal's starter code (no AI)
// sub_000470D0 (0x000470D0, 28 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_000470D0
{
public:
    int sub_000470D0(float a1, int a2, int a3);
    char m_pad00[0x48];
    float m_Field48; // +0x48
    int m_Field4C; // +0x4C
    int m_Field50; // +0x50
};

int Class_000470D0::sub_000470D0(float a1, int a2, int a3)
{
    m_Field48 = a1;
    m_Field4C = a2;
    m_Field50 = a3;
    return a2;
}

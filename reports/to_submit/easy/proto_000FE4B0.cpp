// bin: proto
// va: 0x000FE4B0
// tool: the portal's starter code (no AI)
// sub_000FE4B0 (0x000FE4B0, 35 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_000FE010(int, int, int);

class Class_000FE4B0
{
public:
    void sub_000FE4B0(int a1);
    char m_pad00[0x4C];
    unsigned char m_Field4C; // +0x4C
    char m_pad4D[0x3];
    int m_Field50; // +0x50
};

void Class_000FE4B0::sub_000FE4B0(int a1)
{
    if (!m_Field4C) {
        m_Field4C = sub_000FE010(a1, (int)this, (int)(&m_Field50));
    }
}

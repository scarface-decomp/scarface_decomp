// bin: proto
// va: 0x000BBEB0
// tool: the portal's starter code (no AI)
// sub_000BBEB0 (0x000BBEB0, 64 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field08
{
    void sub_000BDBD0();
};

extern "C" void __cdecl sub_00021A00(int, int);

class Class_000BBEB0
{
public:
    void sub_000BBEB0();
    char m_pad00[0x8];
    Field08* m_Field08; // +0x08
    char m_pad0C[0xD4];
    int m_FieldE0; // +0xE0
};

void Class_000BBEB0::sub_000BBEB0()
{
    m_Field08->sub_000BDBD0();
    m_FieldE0 = m_FieldE0 | 2;
    if (!(((unsigned char)(m_FieldE0 | 2)) & 1)) {
        sub_00021A00(5, 255);
        m_FieldE0 = m_FieldE0 | 8;
    }
}

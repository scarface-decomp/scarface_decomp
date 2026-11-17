// bin: xb
// va: 0x00163560
// tool: the portal's starter code (no AI)
// sub_00163560 (0x00163560, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field1AC
{
    void sub_000CFE20(int);
    void sub_000D2B80(int, int, int, int, int, int, int);
};

class Class_00163560
{
public:
    void sub_00163560(int a1, int a2, int a3, int a4, int a5, bool a6, int a7, int a8);
    char m_pad00[0x110];
    bool m_Field110; // +0x110
    char m_pad111[0x9B];
    Field1AC* m_Field1AC; // +0x1AC
};

void Class_00163560::sub_00163560(int a1, int a2, int a3, int a4, int a5, bool a6, int a7, int a8)
{
    m_Field110 = a6;
    if (m_Field1AC) {
        m_Field1AC->sub_000CFE20(a3);
        m_Field1AC->sub_000D2B80(a1, a3, a4, 0, a5, a7, a8);
    }
}

// bin: proto
// va: 0x000BA160
// what: 
// tool: the portal's starter code (no AI)

// sub_000BA160 (Proto 0x000BA160, 58 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    int sub_000B8850();
};

class Class_000BA160
{
public:
    void sub_000BA160(int a1);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    Field34* m_Field34; // +0x34
    int m_Field38; // +0x38
    char m_pad3C[0x20];
    int m_Field5C; // +0x5C
    int m_Field60; // +0x60
};

void Class_000BA160::sub_000BA160(int a1)
{
    if (a1 < m_Field34->sub_000B8850()) {
        if (a1 < 0) goto L_36;
        if (m_Field30) goto L_36;
        if (m_Field38) goto L_36;
        m_Field5C = a1;
        m_Field60 = 0;
        m_Field30 = 10;
    }
L_36:
    ;
}

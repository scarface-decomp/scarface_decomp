// bin: proto
// va: 0x000BA050
// tool: the portal's starter code (no AI)
// sub_000BA050 (0x000BA050, 68 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_000B8750(int);
    bool sub_000B8820();
    bool sub_000B8AE0(int);
};

extern "C" char DAT_00384B90[];

class Class_000BA050
{
public:
    void sub_000BA050();
    void sub_000B9880(int);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    Field34* m_Field34; // +0x34
    char m_pad38[0x24];
    int m_Field5C; // +0x5C
    char m_pad60[0x9];
    unsigned char m_Field69; // +0x69
};

void Class_000BA050::sub_000BA050()
{
    m_Field69 = m_Field34->sub_000B8AE0(m_Field5C);
    if (!m_Field34->sub_000B8820()) {
        if (m_Field69) goto L_42;
    }
    sub_000B9880((int)DAT_00384B90);
    m_Field34->sub_000B8750(1);
    m_Field30 = 19;
L_42:
    ;
}

// bin: proto
// va: 0x000B9E20
// tool: the portal's starter code (no AI)
// sub_000B9E20 (0x000B9E20, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field34
{
    void sub_000B8750(int);
    bool sub_000B8820();
    bool sub_000B8AE0(int);
    void sub_0021AF00(int);
};

extern "C" char DAT_00384B2C[];

class Class_000B9E20
{
public:
    void sub_000B9E20();
    void sub_000B9880(int);
    char m_pad00[0x30];
    int m_Field30; // +0x30
    Field34* m_Field34; // +0x34
    char m_pad38[0x24];
    int m_Field5C; // +0x5C
    char m_pad60[0x9];
    unsigned char m_Field69; // +0x69
};

void Class_000B9E20::sub_000B9E20()
{
    m_Field69 = m_Field34->sub_000B8AE0(m_Field5C);
    if (!m_Field34->sub_000B8820()) {
        if (m_Field69) goto L_4C;
    }
    sub_000B9880((int)DAT_00384B2C);
    m_Field34->sub_000B8750(1);
    m_Field34->sub_0021AF00(0);
    m_Field30 = 19;
L_4C:
    ;
}

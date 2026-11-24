// bin: xb
// va: 0x0025DB70
// what: 
// tool: the portal's starter code (no AI)

// sub_0025DB70 (0x0025DB70, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0039E22C[];
extern "C" char DAT_003D5CC8[];
extern "C" void __cdecl sub_00027600(int);

class Class_0025DB70
{
public:
    void sub_0025DB70();
    int m_Field00; // +0x00
    char m_pad04[0xC];
    int m_Field10; // +0x10
    int m_Field14; // +0x14
    int m_Field18; // +0x18
    int m_Field1C; // +0x1C
    int m_Field20; // +0x20
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
};

void Class_0025DB70::sub_0025DB70()
{
    m_Field00 = (int)DAT_003D5CC8;
    sub_00027600(m_Field10);
    sub_00027600(m_Field14);
    sub_00027600(m_Field18);
    sub_00027600(m_Field1C);
    sub_00027600(m_Field20);
    sub_00027600(m_Field24);
    sub_00027600(m_Field28);
    sub_00027600(m_Field2C);
    m_Field00 = (int)DAT_0039E22C;
}

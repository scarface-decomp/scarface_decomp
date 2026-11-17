// bin: proto
// va: 0x000309A0
// tool: the portal's starter code (no AI)
// sub_000309A0 (0x000309A0, 69 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00025160(int);
extern "C" int __stdcall sub_00030530(int);

class Class_000309A0
{
public:
    void sub_000309A0(int a1);
    char m_pad00[0x24];
    int m_Field24; // +0x24
    int m_Field28; // +0x28
    int m_Field2C; // +0x2C
    int m_Field30; // +0x30
    int m_Field34; // +0x34
    char m_pad38[0x10];
    int m_Field48; // +0x48
    int m_Field4C; // +0x4C
};

void Class_000309A0::sub_000309A0(int a1)
{
    int t1, t2;

    t1 = sub_00030530(a1);
    m_Field28 = t1 | -1;
    m_Field2C = t1 | -1;
    m_Field30 = t1 | -1;
    m_Field34 = t1 | -1;
    t2 = m_Field4C;
    m_Field24 = 0;
    if (m_Field4C) {
        sub_00025160(t2);
        m_Field4C = 0;
        m_Field48 = 0;
    }
}

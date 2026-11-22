// bin: pc
// va: 0x006EE4F0
// what: 
// tool: the portal's starter code (no AI)

// sub_006EE4F0 (PC 0x006EE4F0, 60 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field20
{
    void sub_006F2A40(int);
};

struct Object
{
    void sub_006F2C40(int);
};

extern "C" char DAT_007F682C[];
extern "C" int __cdecl sub_006EE890(int, int);

class Class_006EE4F0
{
public:
    int sub_006EE4F0();
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0xC];
    Field20* m_Field20; // +0x20
    char m_pad24[0x4];
    int m_Field28; // +0x28
};

int Class_006EE4F0::sub_006EE4F0()
{
    int t1;
    Field20* t2;

    t1 = m_Field28;
    if ((unsigned int)m_Field28 > (unsigned int)1) {
        m_Field28 = t1 + -1;
        return t1 + -1;
    }
    t2 = m_Field20;
    m_Field20->sub_006F2A40((int)this);
    ((Object*)(int)t2 + 40)->sub_006F2C40((int)(&m_Field10));
    return sub_006EE890((int)DAT_007F682C, (int)this);
}

// bin: xb
// va: 0x0007A140
// tool: the portal's starter code (no AI)
// sub_0007A140 (0x0007A140, 79 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2C
{
    bool sub_00081E10(int, int);
};

struct Object
{
    void sub_00020FA0(int);
};

class Class_0007A140
{
public:
    void sub_0007A140(int a1);
    char m_pad00[0x2C];
    Field2C* m_Field2C; // +0x2C
    char m_pad30[0xC];
    Field2C* m_Field3C; // +0x3C
    char m_pad40[0x47];
    bool m_Field87; // +0x87
};

void Class_0007A140::sub_0007A140(int a1)
{
    if (m_Field87) {
        if (!m_Field2C) goto L_4B;
        if (!m_Field3C) goto L_4B;
        ((Object*)(int)(&a1))->sub_00020FA0(a1);
        if (m_Field2C->sub_00081E10((int)(&a1), 1)) goto L_4B;
        m_Field3C->sub_00081E10((int)(&a1), 1);
    }
L_4B:
    ;
}

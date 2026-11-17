// bin: xb
// va: 0x00232E90
// tool: the portal's starter code (no AI)
// sub_00232E90 (0x00232E90, 81 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0001E5C0(int);

class Class_00232E90
{
public:
    void sub_00232E90(int a1, int a2);
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0x8];
    int m_Field1C; // +0x1C
    char m_pad20[0xC];
    bool m_Field2C; // +0x2C
};

void Class_00232E90::sub_00232E90(int a1, int a2)
{
    int r_edi, t1;

    if (!a1) goto L_4D;
    t1 = m_Field10;
    if (a1 != m_Field10) goto L_4D;
    r_edi = a2;
    if (t1 == 6) {
        if (!(m_Field1C & a2)) goto L_39;
        if (m_Field2C) goto L_39;
        sub_0001E5C0(0);
        m_Field10 = 2;
    }
L_39:
    if (r_edi == m_Field1C) {
        if (m_Field2C) goto L_4D;
        m_Field10 = 2;
    }
L_4D:
    ;
}

// bin: proto
// va: 0x0009DA50
// tool: the portal's starter code (no AI)
// sub_0009DA50 (0x0009DA50, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field10
{
    void sub_0009D460(int, int);
};

extern "C" char DAT_0037D2DC[];
extern "C" int __cdecl sub_00015450(int);
extern "C" void __stdcall sub_0007D870(int, int);

class Class_0009DA50
{
public:
    void sub_0009DA50(int a1, int a2);
    int m_Field00; // +0x00
    bool m_Field04; // +0x04
    char m_pad05[0xB];
    Field10 m_Field10; // +0x10
};

void Class_0009DA50::sub_0009DA50(int a1, int a2)
{
    int r_edi, t2, t3, t4;

    sub_0007D870(a1, (int)DAT_0037D2DC);
    r_edi = 0;
    t2 = m_Field00;
    if (m_Field04) {
        if (!t2) goto L_46;
        if (!*(unsigned char*)t2) goto L_46;
        t3 = sub_00015450(t2);
        if (!t3) goto L_46;
        if (*(unsigned short*)(t3 + 48) != 1) goto L_46;
        t4 = *(int*)*(int*)(t3 + 36);
        if (!*(int*)*(int*)(t3 + 36)) goto L_46;
        r_edi = t4;
    }
L_46:
    m_Field10.sub_0009D460(r_edi, a2);
}

// bin: proto
// va: 0x000763E0
// tool: the portal's starter code (no AI)
// sub_000763E0 (0x000763E0, 96 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0026DAC0();
    void sub_00297770(int, int, int, int);
    int sub_00297960();
};

extern "C" int __cdecl sub_00297980(int, int);

class Class_000763E0
{
public:
    void sub_000763E0(int a1);
    char m_pad00[0x1C];
    int m_Field1C; // +0x1C
    char m_pad20[0xC];
    int m_Field2C; // +0x2C
};

void Class_000763E0::sub_000763E0(int a1)
{
    int r_esi, t4;

    if (!m_Field1C) goto L_5C;
    m_Field2C = (m_Field2C & -15) | 1;
    r_esi = ((Object*)a1)->sub_0026DAC0();
    if (!r_esi) {
        r_esi = sub_00297980(*(int*)(m_Field1C + 12), a1);
        if (!r_esi) goto L_5A;
    }
    t4 = ((Object*)r_esi)->sub_00297960();
    if (!t4) {
        ((Object*)r_esi)->sub_00297770(t4, 1, t4, -0x39E3C000);
    }
L_5A:
L_5C:
    ;
}

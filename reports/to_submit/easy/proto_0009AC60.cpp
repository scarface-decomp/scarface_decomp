// bin: proto
// va: 0x0009AC60
// tool: the portal's starter code (no AI)
// sub_0009AC60 (0x0009AC60, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00043DB0(int, int, int);

class Class_0009AC60
{
public:
    int sub_0009AC60(int a1);
    char m_pad00[0x80];
    int m_Field80; // +0x80
    int m_Field84; // +0x84
};

int Class_0009AC60::sub_0009AC60(int a1)
{
    int r_eax, t1;

    r_eax = m_Field80;
    if (r_eax) {
        if (!*(unsigned char*)r_eax) goto L_2C;
        t1 = m_Field84;
        if (!m_Field84) goto L_2C;
        if (!a1) goto L_2C;
        r_eax = sub_00043DB0(r_eax, t1, a1);
    }
L_2C:
    return r_eax;
}

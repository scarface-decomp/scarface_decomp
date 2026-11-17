// bin: xb
// va: 0x00288790
// tool: the portal's starter code (no AI)
// sub_00288790 (0x00288790, 91 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D827C[];
extern "C" int __cdecl sub_00027590(int);
extern "C" int __stdcall sub_00275190(int, int);

class Class_00288790
{
public:
    int sub_00288790(int a1, int a2);
    void sub_002882A0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

int Class_00288790::sub_00288790(int a1, int a2)
{
    int r_eax;

    r_eax = a2;
    sub_002882A0(a1, a2);
    r_eax = m_Field10;
    m_Field00 = (int)DAT_003D827C;
    m_Field18 = 0;
    if (!m_Field0C) {
        r_eax = sub_00027590(r_eax * 8);
        m_Field18 = r_eax;
        r_eax = (int)this;
        return r_eax;
    }
    r_eax <<= 3;
    r_eax = sub_00275190(r_eax, 3);
    m_Field18 = r_eax;
    r_eax = (int)this;
    return r_eax;
}

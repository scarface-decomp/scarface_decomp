// bin: proto
// va: 0x0004BB80
// tool: the portal's starter code (no AI)
// sub_0004BB80 (0x0004BB80, 95 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0004B6C0(int, int, int, int, int);
};

extern "C" float DAT_0037F70C;
extern "C" char DAT_0037FC2C[];
extern "C" int __cdecl sub_001FCF20(int);
extern "C" void __stdcall sub_00217060(int);

class Class_0004BB80
{
public:
    int sub_0004BB80(int a1, int a2, int a3, int a4, int a5);
    void sub_00216BB0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

int Class_0004BB80::sub_0004BB80(int a1, int a2, int a3, int a4, int a5)
{
    int r_eax;

    sub_00217060(1);
    m_Field00 = (int)DAT_0037FC2C;
    r_eax = sub_001FCF20(108);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_0004B6C0(a1, a2, a3, a4, a5);
    } else {
        r_eax = 0;
    }
    sub_00216BB0(0, r_eax);
    m_Field3C = DAT_0037F70C;
    r_eax = (int)this;
    return r_eax;
}

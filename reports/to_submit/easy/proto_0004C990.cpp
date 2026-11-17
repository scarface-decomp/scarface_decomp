// bin: proto
// va: 0x0004C990
// tool: the portal's starter code (no AI)
// sub_0004C990 (0x0004C990, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0004C830(int, int, int);
};

extern "C" float DAT_0037CD90;
extern "C" char DAT_0037FEB4[];
extern "C" int __cdecl sub_001FCF20(int);
extern "C" void __stdcall sub_00217060(int);

class Class_0004C990
{
public:
    int sub_0004C990(int a1, int a2, int a3);
    void sub_00216BB0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

int Class_0004C990::sub_0004C990(int a1, int a2, int a3)
{
    int r_eax;

    sub_00217060(1);
    m_Field00 = (int)DAT_0037FEB4;
    r_eax = sub_001FCF20(76);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_0004C830(a1, a2, a3);
    } else {
        r_eax = 0;
    }
    sub_00216BB0(0, r_eax);
    m_Field3C = DAT_0037CD90;
    r_eax = (int)this;
    return r_eax;
}

// bin: proto
// va: 0x00055A00
// tool: the portal's starter code (no AI)
// sub_00055A00 (0x00055A00, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00055500(int);
};

extern "C" char DAT_00380874[];
extern "C" float DAT_0038097C;
extern "C" int __cdecl sub_001FCF20(int);
extern "C" void __stdcall sub_00217060(int);

class Class_00055A00
{
public:
    int sub_00055A00(int a1);
    void sub_00216BB0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

int Class_00055A00::sub_00055A00(int a1)
{
    int r_eax;

    sub_00217060(1);
    m_Field00 = (int)DAT_00380874;
    r_eax = sub_001FCF20(3732);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00055500(a1);
    } else {
        r_eax = 0;
    }
    sub_00216BB0(0, r_eax);
    m_Field3C = DAT_0038097C;
    r_eax = (int)this;
    return r_eax;
}

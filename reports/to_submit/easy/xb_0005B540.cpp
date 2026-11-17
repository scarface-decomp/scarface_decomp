// bin: xb
// va: 0x0005B540
// tool: the portal's starter code (no AI)
// sub_0005B540 (0x0005B540, 84 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0025D080();
};

extern "C" char DAT_003A1114[];
extern "C" char DAT_003A1164[];
extern "C" int __cdecl sub_0023F760(int);
extern "C" void __stdcall sub_0025ADD0(int);

class Class_0005B540
{
public:
    Class_0005B540* sub_0005B540();
    void sub_0025A8D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

Class_0005B540* Class_0005B540::sub_0005B540()
{
    int r_esi;

    sub_0025ADD0(1);
    m_Field00 = (int)DAT_003A1164;
    r_esi = sub_0023F760(60);
    if (r_esi) {
        ((Object*)r_esi)->sub_0025D080();
        *(int*)r_esi = (int)DAT_003A1114;
        *(bool*)(r_esi + 56) = true;
        *(int*)(r_esi + 12) = 1;
    } else {
        r_esi = 0;
    }
    sub_0025A8D0(0, r_esi);
    m_Field3C = 0.0f;
    return this;
}

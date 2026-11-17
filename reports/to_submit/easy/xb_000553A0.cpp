// bin: xb
// va: 0x000553A0
// tool: the portal's starter code (no AI)
// sub_000553A0 (0x000553A0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00055250(int, int, int);
};

extern "C" float DAT_0039D580;
extern "C" char DAT_003A0C3C[];
extern "C" int __cdecl sub_0023F760(int);
extern "C" void __stdcall sub_0025ADD0(int);

class Class_000553A0
{
public:
    int sub_000553A0(int a1, int a2, int a3);
    void sub_0025A8D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

int Class_000553A0::sub_000553A0(int a1, int a2, int a3)
{
    int r_eax;

    sub_0025ADD0(1);
    m_Field00 = (int)DAT_003A0C3C;
    r_eax = sub_0023F760(72);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_00055250(a1, a2, a3);
    } else {
        r_eax = 0;
    }
    sub_0025A8D0(0, r_eax);
    m_Field3C = DAT_0039D580;
    r_eax = (int)this;
    return r_eax;
}

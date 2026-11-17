// bin: xb
// va: 0x000602C0
// tool: the portal's starter code (no AI)
// sub_000602C0 (0x000602C0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0005FDC0(int);
};

extern "C" char DAT_003A16F4[];
extern "C" float DAT_003A1804;
extern "C" int __cdecl sub_0023F760(int);
extern "C" void __stdcall sub_0025ADD0(int);

class Class_000602C0
{
public:
    int sub_000602C0(int a1);
    void sub_0025A8D0(int, int);
    int m_Field00; // +0x00
    char m_pad04[0x38];
    float m_Field3C; // +0x3C
};

int Class_000602C0::sub_000602C0(int a1)
{
    int r_eax;

    sub_0025ADD0(1);
    m_Field00 = (int)DAT_003A16F4;
    r_eax = sub_0023F760(3732);
    if (r_eax) {
        r_eax = ((Object*)r_eax)->sub_0005FDC0(a1);
    } else {
        r_eax = 0;
    }
    sub_0025A8D0(0, r_eax);
    m_Field3C = DAT_003A1804;
    r_eax = (int)this;
    return r_eax;
}

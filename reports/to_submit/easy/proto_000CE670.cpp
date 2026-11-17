// bin: proto
// va: 0x000CE670
// tool: the portal's starter code (no AI)
// sub_000CE670 (0x000CE670, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000CE570();
    void sub_001B2090();
};

extern "C" char DAT_00386658[];
extern "C" void __cdecl sub_002002C0(void);

class Class_000CE670
{
public:
    int sub_000CE670(int a1);
    int m_Field00; // +0x00
    char m_pad04[0x8];
    int m_Field0C; // +0x0C
    int m_Field10; // +0x10
    char m_pad14[0xCC];
    int m_FieldE0; // +0xE0
    int m_FieldE4; // +0xE4
};

int Class_000CE670::sub_000CE670(int a1)
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    sub_002002C0();
    m_Field00 = (int)DAT_00386658;
    r_eax = (int)(&m_Field10);
    r_ecx = 13;
    do {
        *(float*)r_eax = 0.0f;
        *(int*)(r_eax + 4) = 0;
        *(int*)(r_eax + 8) = 0;
        *(int*)(r_eax + 12) = 0;
        r_eax += 16;
        r_ecx -= 1;
    } while (r_ecx);
    r_ecx = (int)(&m_FieldE4);
    ((Object*)r_ecx)->sub_001B2090();
    r_eax = a1;
    r_ecx = (int)this;
    m_Field0C = a1;
    m_FieldE0 = 0;
    ((Object*)r_ecx)->sub_000CE570();
    r_eax = (int)this;
    return r_eax;
}

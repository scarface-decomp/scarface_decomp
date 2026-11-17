// bin: proto
// va: 0x000801D0
// tool: the portal's starter code (no AI)
// sub_000801D0 (0x000801D0, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0008D4C0(int);
};

extern "C" bool DAT_00453B10;
extern "C" float DAT_00453B14;
extern "C" float DAT_00453B18;
extern "C" char DAT_00453B44[];

class Class_000801D0
{
public:
    int sub_000801D0();
    char m_pad00[0x2370];
    int m_Field2370; // +0x2370
    int m_Field2374; // +0x2374
};

int Class_000801D0::sub_000801D0()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_ecx = (int)DAT_00453B44;
    ((Object*)r_ecx)->sub_0008D4C0(0);
    r_eax = m_Field2370;
    r_ecx = m_Field2374 + (m_Field2374 * 2);
    r_ecx = r_eax + (r_ecx * 8);
    DAT_00453B10 = false;
    DAT_00453B18 = 0.0f;
    DAT_00453B14 = 0.0f;
    if ((unsigned int)r_eax < (unsigned int)r_ecx) {
        r_edx = 0x3FFFFFFF;
        do {
            *(int*)(r_eax + 12) &= r_edx;
            r_eax += 24;
        } while ((unsigned int)r_eax < (unsigned int)r_ecx);
    }
    return r_eax;
}

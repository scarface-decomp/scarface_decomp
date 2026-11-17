// bin: xb
// va: 0x0008AC20
// tool: the portal's starter code (no AI)
// sub_0008AC20 (0x0008AC20, 80 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_00098B90(int);
};

extern "C" bool DAT_0048149C;
extern "C" float DAT_004814A0;
extern "C" float DAT_004814A4;
extern "C" char DAT_00481578[];

class Class_0008AC20
{
public:
    int sub_0008AC20();
    char m_pad00[0x2500];
    int m_Field2500; // +0x2500
    int m_Field2504; // +0x2504
};

int Class_0008AC20::sub_0008AC20()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_ecx = (int)DAT_00481578;
    ((Object*)r_ecx)->sub_00098B90(0);
    r_eax = m_Field2500;
    r_ecx = m_Field2504 + (m_Field2504 * 2);
    r_ecx = r_eax + (r_ecx * 8);
    DAT_0048149C = false;
    DAT_004814A4 = 0.0f;
    DAT_004814A0 = 0.0f;
    if ((unsigned int)r_eax < (unsigned int)r_ecx) {
        r_edx = 0x3FFFFFFF;
        do {
            *(int*)(r_eax + 8) &= r_edx;
            r_eax += 24;
        } while ((unsigned int)r_eax < (unsigned int)r_ecx);
    }
    return r_eax;
}

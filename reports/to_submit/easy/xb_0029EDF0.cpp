// bin: xb
// va: 0x0029EDF0
// tool: the portal's starter code (no AI)
// sub_0029EDF0 (0x0029EDF0, 85 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D9C48[];
extern "C" char DAT_003D9C84[];
extern "C" int __cdecl sub_00027590(int);

class Class_0029EDF0
{
public:
    int sub_0029EDF0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
    int m_Field08; // +0x08
    int m_Field0C; // +0x0C
};

int Class_0029EDF0::sub_0029EDF0(int a1)
{
    int r_eax, r_ecx, r_edi, r_edx;

    r_ecx = (int)this;
    r_edi = a1;
    r_eax = a1;
    r_eax = a1 * 28;
    m_Field00 = (int)DAT_003D9C84;
    r_eax = sub_00027590(r_eax);
    if (r_eax) {
        r_edx = r_edi + -1;
        r_ecx = r_eax;
        if (r_edx < 0) goto L_40;
        r_edx += 1;
        do {
            *(int*)r_ecx = (int)DAT_003D9C48;
            r_ecx += 28;
            r_edx -= 1;
        } while (r_edx);
        goto L_40;
    }
    r_eax = 0;
L_40:
    m_Field04 = r_edi;
    m_Field0C = r_eax;
    m_Field08 = 0;
    r_eax = (int)this;
    return r_eax;
}

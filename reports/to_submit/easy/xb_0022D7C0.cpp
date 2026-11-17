// bin: xb
// va: 0x0022D7C0
// tool: the portal's starter code (no AI)
// sub_0022D7C0 (0x0022D7C0, 73 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000788D0(int, int, int, int, int);

class Class_0022D7C0
{
public:
    void sub_0022D7C0(int a1);
    char m_pad00[0x64];
    int m_Field64; // +0x64
};

void Class_0022D7C0::sub_0022D7C0(int a1)
{
    int r_eax, r_ecx, r_esi;

    r_ecx = (int)this;
    r_ecx = a1;
    if (!a1) goto L_45;
    r_esi = 0;
    r_eax = (int)(&m_Field64);
L_11:
    if (*(int*)r_eax) {
        r_esi += 1;
        r_eax += 4;
        if ((unsigned int)r_esi < (unsigned int)5) goto L_11;
        return;
    }
    *(int*)((int)this + (r_esi * 4) + 100) = r_ecx;
    r_eax = *(int*)r_ecx;
    ((void (__cdecl*)(void))*(int*)r_eax)();
    r_ecx = *(int*)((int)this + (r_esi * 4) + 100);
    sub_000788D0(r_ecx, 500, 0, 3, 1);
L_45:
    ;
}

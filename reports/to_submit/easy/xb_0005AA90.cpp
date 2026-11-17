// bin: xb
// va: 0x0005AA90
// tool: the portal's starter code (no AI)
// sub_0005AA90 (0x0005AA90, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int DAT_00475990[];

class Class_0005AA90
{
public:
    void sub_0005AA90();
};

void Class_0005AA90::sub_0005AA90()
{
    int r_eax, r_ecx, r_edx, r_esi;

    r_ecx = (int)this;
    r_edx = r_ecx + 4;
    r_esi = 8;
L_10:
    r_ecx = *(int*)r_edx;
    if (!r_ecx) goto L_4E;
    r_eax = 0;
L_20:
    if (DAT_00475990[r_eax] != r_ecx) {
        r_eax += 1;
        if ((unsigned int)r_eax < (unsigned int)48) goto L_20;
        goto L_4E;
    }
    r_ecx = DAT_00475990[r_eax];
    *(bool*)(r_ecx + 1664) = false;
    r_eax = DAT_00475990[r_eax];
    *(float*)(r_eax + 1660) = 0.0f;
L_4E:
    *(int*)r_edx = 0;
    r_edx += 32;
    r_esi -= 1;
    if (r_esi) goto L_10;
}

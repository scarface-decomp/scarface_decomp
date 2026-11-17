// bin: xb
// va: 0x001E4190
// tool: the portal's starter code (no AI)
// sub_001E4190 (0x001E4190, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0039D65C;
extern "C" int __cdecl sub_001E3EE0(void);

class Class_001E4190
{
public:
    void sub_001E4190();
};

void Class_001E4190::sub_001E4190()
{
    int r_eax, r_ecx, r_edi, r_edx, r_esi;
    float t1;

    r_ecx = (int)this;
    t1 = DAT_0039D65C;
    r_edi = (int)this;
    *(float*)(r_edi + 148) = t1;
    r_eax = sub_001E3EE0();
    r_edx = *(int*)r_eax;
    r_esi = *(int*)(r_eax + 4);
    if (r_edx == r_esi) goto L_50;
L_22:
    if (*(int*)r_edx != r_edi) {
        r_edx += 4;
        if (r_edx != r_esi) goto L_22;
        return;
    }
    r_ecx = r_edx + 4;
    if (r_ecx != r_esi) {
        r_edx -= r_ecx;
        do {
            r_edi = *(int*)r_ecx;
            *(int*)(r_edx + r_ecx) = r_edi;
            r_ecx += 4;
        } while (r_ecx != r_esi);
    }
    *(int*)(r_eax + 4) += -4;
L_50:
    ;
}

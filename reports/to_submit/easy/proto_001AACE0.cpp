// bin: proto
// va: 0x001AACE0
// tool: the portal's starter code (no AI)
// sub_001AACE0 (0x001AACE0, 83 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_0037CE60;
extern "C" int __cdecl sub_001AAA20(void);

class Class_001AACE0
{
public:
    void sub_001AACE0();
};

void Class_001AACE0::sub_001AACE0()
{
    int r_eax, r_ecx, r_edi, r_edx, r_esi;
    float t1;

    r_ecx = (int)this;
    t1 = DAT_0037CE60;
    r_edi = (int)this;
    *(float*)(r_edi + 152) = t1;
    r_eax = sub_001AAA20();
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

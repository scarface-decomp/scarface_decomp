// bin: xb
// va: 0x0005E350
// tool: the portal's starter code (no AI)
// sub_0005E350 (0x0005E350, 82 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0005E350
{
public:
    int sub_0005E350(float a1, int a2);
};

int Class_0005E350::sub_0005E350(float a1, int a2)
{
    int r_eax, r_ebx, r_ecx, r_edi, r_edx, r_esi, t1;

    r_ecx = (int)this;
    r_eax = *(int*)(r_ecx + 72);
    r_eax -= *(int*)(r_ecx + 68);
    r_eax >>= 4;
    if (r_eax > 0) {
        r_edi = 0;
        r_ebx = r_eax;
        do {
            r_eax = *(int*)(r_ecx + 68);
            r_eax = *(int*)(r_edi + r_eax);
            r_esi = *(int*)(r_eax + 60);
            r_edx = 0;
            if (r_esi > 0) {
                r_esi = 0;
                do {
                    *(float*)(r_esi + *(int*)(r_eax + 56) + 8) = a1;
                    t1 = *(int*)(r_eax + 60);
                    r_edx += 1;
                    r_esi += 16;
                } while (r_edx < t1);
            }
            r_edi += 16;
            r_ebx -= 1;
        } while (r_ebx);
    }
    return r_eax;
}

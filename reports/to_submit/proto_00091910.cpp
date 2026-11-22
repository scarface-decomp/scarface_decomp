// bin: proto
// va: 0x00091910
// what: 
// tool: the portal's starter code (no AI)

// sub_00091910 (Proto 0x00091910, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00091910
{
public:
    int sub_00091910();
};

int Class_00091910::sub_00091910()
{
    int r_eax, r_ecx, r_edx;

    r_ecx = (int)this;
    r_edx = *(int*)(r_ecx + 12);
    r_eax = 0;
    if (r_edx > 0) {
        r_ecx = *(int*)(r_ecx + 16);
        r_ecx += 588;
        do {
            if (*(unsigned char*)r_ecx) {
                r_eax += 1;
            }
            r_ecx += 592;
            r_edx -= 1;
        } while (r_edx);
    }
    return r_eax;
}

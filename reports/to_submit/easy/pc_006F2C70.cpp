// bin: pc
// va: 0x006F2C70
// tool: the portal's starter code (no AI)
// sub_006F2C70 (0x006F2C70, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_006F2C70
{
public:
    int sub_006F2C70();
};

int Class_006F2C70::sub_006F2C70()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_ecx = *(int*)r_ecx;
    r_eax = 0;
    if (r_ecx) {
        do {
            r_ecx = *(int*)r_ecx;
            r_eax += 1;
        } while (r_ecx);
    }
    return r_eax;
}

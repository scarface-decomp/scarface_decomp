// bin: proto
// va: 0x000F7A70
// what: 
// tool: the portal's starter code (no AI)

// sub_000F7A70 (Proto 0x000F7A70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_0037CD30[];

class Class_000F7A70
{
public:
    bool sub_000F7A70(int a1);
};

bool Class_000F7A70::sub_000F7A70(int a1)
{
    int r_ecx, r_edx;
    bool t1;

    r_ecx = (int)this;
    r_edx = r_ecx + 48;
    r_ecx = a1;
    if (!a1) {
        r_ecx = (int)DAT_0037CD30;
    }
    do {
        t1 = *(bool*)r_ecx;
        r_ecx += 1;
        *(bool*)r_edx = t1;
        r_edx += 1;
    } while (t1);
    return t1;
}

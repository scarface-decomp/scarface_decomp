// bin: proto
// va: 0x00018750
// tool: the portal's starter code (no AI)
// sub_00018750 (0x00018750, 34 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00018750
{
public:
    int sub_00018750();
};

int Class_00018750::sub_00018750()
{
    int r_eax, r_ecx;

    r_ecx = (int)this;
    r_eax = 0;
    if (*(bool*)(r_ecx + 8)) {
        r_ecx = *(int*)r_ecx;
        r_ecx = *(int*)(r_ecx + 4);
    } else {
        r_ecx = *(int*)(*(int*)r_ecx + 32);
    }
    if (r_ecx) {
        if (*(unsigned short*)r_ecx != 5) goto L_21;
        r_eax = r_ecx;
    }
L_21:
    return r_eax;
}

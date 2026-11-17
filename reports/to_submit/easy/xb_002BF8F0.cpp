// bin: xb
// va: 0x002BF8F0
// tool: the portal's starter code (no AI)
// sub_002BF8F0 (0x002BF8F0, 63 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_002BF8F0
{
public:
    int sub_002BF8F0(int a1, int a2);
};

int Class_002BF8F0::sub_002BF8F0(int a1, int a2)
{
    int r_ecx;

    r_ecx = (int)this;
    if (*(unsigned char*)(r_ecx + 232) == 85) {
        r_ecx = a2;
        *(int*)a1 = -1;
        *(int*)r_ecx = -1;
        return a1;
    }
    *(int*)a1 = *(char*)(r_ecx + 239) - 49;
    r_ecx = *(char*)(r_ecx + 240);
    r_ecx -= 65;
    *(int*)a2 = r_ecx;
    return a1;
}

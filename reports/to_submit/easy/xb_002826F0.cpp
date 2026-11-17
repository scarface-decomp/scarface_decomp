// bin: xb
// va: 0x002826F0
// tool: the portal's starter code (no AI)
// sub_002826F0 (0x002826F0, 92 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int sub_0033A678;
extern "C" char sub_0033A6B0[];
extern "C" char sub_0033A6B8[];

class Class_002826F0
{
public:
    void sub_002826F0(int a1, int a2, int a3);
};

void Class_002826F0::sub_002826F0(int a1, int a2, int a3)
{
    int r_eax, t1;

    r_eax = a1;
    if (*(int*)((int)this + (r_eax * 4) + 100) != a2) {
        *(int*)((int)this + (r_eax * 4) + 100) = a2;
        sub_0033A678 |= 2048;
        *(int*)(((int)sub_0033A6B0) + (a1 << 7)) = a2;
    }
    if (*(int*)((int)this + (r_eax * 4) + 132) != a3) {
        *(int*)((int)this + (r_eax * 4) + 132) = a3;
        t1 = sub_0033A678 | 2048;
        r_eax <<= 7;
        sub_0033A678 = t1;
        *(int*)(((int)sub_0033A6B8) + r_eax) = a3;
    }
}

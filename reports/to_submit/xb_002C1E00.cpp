// bin: xb
// va: 0x002C1E00
// what: 
// tool: the portal's starter code (no AI)

// sub_002C1E00 (0x002C1E00, 141 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int sub_0033A678;
extern "C" char sub_0033A6BC[];
extern "C" char sub_0033A6CC[];

class Class_002C1E00
{
public:
    void sub_002C1E00(int a1, int a2, int a3, int a4);
    void sub_002826F0(int, int, int);
    void sub_00282750(int, int, int);
};

void Class_002C1E00::sub_002C1E00(int a1, int a2, int a3, int a4)
{
    int r_ebx, r_esi, t3;

    r_esi = a1;
    sub_002826F0(a1, a2, a3);
    r_ebx = a4;
    if (*(int*)((int)this + (r_esi * 4) + 148) != a4) {
        *(int*)((int)this + (r_esi * 4) + 148) = a4;
        sub_0033A678 = sub_0033A678 | 2048;
        *(int*)(((int)sub_0033A6BC) + (a1 << 7)) = a4;
    }
    sub_00282750(r_esi, a2, a3);
    if (*(int*)((int)this + (r_esi * 4) + 196) != r_ebx) {
        *(int*)((int)this + (r_esi * 4) + 196) = r_ebx;
        t3 = sub_0033A678 | 2048;
        r_esi <<= 7;
        sub_0033A678 = t3;
        *(int*)(((int)sub_0033A6CC) + r_esi) = r_ebx;
    }
}

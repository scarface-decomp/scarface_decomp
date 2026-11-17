// bin: xb
// va: 0x002C1DB0
// tool: the portal's starter code (no AI)
// sub_002C1DB0 (0x002C1DB0, 78 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" int sub_0033A678;
extern "C" char sub_0033A6CC[];

class Class_002C1DB0
{
public:
    int sub_002C1DB0(int a1, int a2, int a3, int a4);
    void sub_00282750(int, int, int);
};

int Class_002C1DB0::sub_002C1DB0(int a1, int a2, int a3, int a4)
{
    int r_eax;

    r_eax = a3;
    sub_00282750(a1, a2, a3);
    r_eax = a4;
    if (*(int*)((int)this + (a1 * 4) + 196) != a4) {
        *(int*)((int)this + (a1 * 4) + 196) = a4;
        sub_0033A678 = sub_0033A678 | 2048;
        *(int*)(((int)sub_0033A6CC) + (a1 << 7)) = a4;
    }
    return r_eax;
}

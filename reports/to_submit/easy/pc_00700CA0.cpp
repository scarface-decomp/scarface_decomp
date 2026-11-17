// bin: pc
// va: 0x00700CA0
// tool: the portal's starter code (no AI)
// sub_00700CA0 (0x00700CA0, 56 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_006F33D0(int, int);

class Class_00700CA0
{
public:
    int sub_00700CA0(int a1);
};

int Class_00700CA0::sub_00700CA0(int a1)
{
    if (sub_006F33D0(a1, (int)this)) {
        if (!sub_006F33D0(a1, (int)this + 4)) goto L_31;
        return 1;
    }
L_31:
    return 0;
}

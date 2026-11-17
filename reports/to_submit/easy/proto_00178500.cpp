// bin: proto
// va: 0x00178500
// tool: the portal's starter code (no AI)
// sub_00178500 (0x00178500, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003999EC[];
extern "C" int __cdecl sub_0008ECF0(int, int);
extern "C" void __cdecl sub_002062D0(int, int, int);

class Class_00178500
{
public:
    void sub_00178500(int a1);
};

void Class_00178500::sub_00178500(int a1)
{
    if (a1 < 100) {
        if (a1 <= 0) goto L_2D;
        sub_002062D0((int)this + 76, sub_0008ECF0((int)DAT_003999EC, a1), 4);
    }
L_2D:
    ;
}

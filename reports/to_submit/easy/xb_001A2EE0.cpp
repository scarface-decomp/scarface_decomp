// bin: xb
// va: 0x001A2EE0
// tool: the portal's starter code (no AI)
// sub_001A2EE0 (0x001A2EE0, 49 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" char DAT_003BD7B4[];
extern "C" int __cdecl sub_0009A2B0(int, int);
extern "C" void __cdecl sub_00248FB0(int, int, int);

class Class_001A2EE0
{
public:
    void sub_001A2EE0(int a1);
};

void Class_001A2EE0::sub_001A2EE0(int a1)
{
    if (a1 < 100) {
        if (a1 <= 0) goto L_2D;
        sub_00248FB0((int)this + 112, sub_0009A2B0((int)DAT_003BD7B4, a1), 4);
    }
L_2D:
    ;
}

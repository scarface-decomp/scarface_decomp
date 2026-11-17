// bin: xb
// va: 0x000B8330
// tool: the portal's starter code (no AI)
// sub_000B8330 (0x000B8330, 53 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_00012230(int, int);
extern "C" int __cdecl sub_00014D70(int, int, int);

class Class_000B8330
{
public:
    void sub_000B8330(int a1, int a2);
    int m_Field00; // +0x00
};

void Class_000B8330::sub_000B8330(int a1, int a2)
{
    int t1;

    if (a1) {
        if (!*(unsigned char*)a1) goto L_31;
        t1 = sub_00014D70(a1, 0, 0);
        m_Field00 = t1;
        if (!t1) goto L_31;
        sub_00012230(t1, a2);
    }
L_31:
    ;
}

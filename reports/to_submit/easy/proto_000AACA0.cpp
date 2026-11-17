// bin: proto
// va: 0x000AACA0
// tool: the portal's starter code (no AI)
// sub_000AACA0 (0x000AACA0, 51 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_000126D0(int, int);
extern "C" int __cdecl sub_00015680(int, int);

class Class_000AACA0
{
public:
    void sub_000AACA0(int a1, int a2);
    int m_Field00; // +0x00
};

void Class_000AACA0::sub_000AACA0(int a1, int a2)
{
    int t1;

    if (a1) {
        if (!*(unsigned char*)a1) goto L_2F;
        t1 = sub_00015680(a1, 0);
        m_Field00 = t1;
        if (!t1) goto L_2F;
        sub_000126D0(t1, a2);
    }
L_2F:
    ;
}

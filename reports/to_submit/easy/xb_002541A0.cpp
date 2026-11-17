// bin: xb
// va: 0x002541A0
// tool: the portal's starter code (no AI)
// sub_002541A0 (0x002541A0, 89 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_00253AA0(int);
};

extern "C" int __cdecl sub_00244410(void);
extern "C" void __cdecl sub_00244420(int);

class Class_002541A0
{
public:
    void sub_002541A0(int a1, int a2);
    char m_pad00[0x10];
    int m_Field10; // +0x10
    char m_pad14[0x4];
    int m_Field18; // +0x18
};

void Class_002541A0::sub_002541A0(int a1, int a2)
{
    int r_ebx, t1, t4, t5;

    t1 = m_Field10;
    r_ebx = sub_00244410();
    sub_00244420(t1);
    t4 = m_Field18;
    if (a2 >= 0) {
        t5 = (a2 * 196) + *(int*)(t4 + 16);
        if (!*(int*)((a2 * 196) + *(int*)(t4 + 16) + 132)) goto L_49;
        if (*(int*)t5 != a1) goto L_49;
        ((Object*)t4)->sub_00253AA0(a2);
    }
L_49:
    sub_00244420(r_ebx);
}

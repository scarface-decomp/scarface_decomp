// bin: xb
// va: 0x002530A0
// what: 
// tool: the portal's starter code (no AI)

// sub_002530A0 (0x002530A0, 137 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

struct Object
{
    void sub_00254C40(int, int);
};

extern "C" int __cdecl sub_00244410(void);
extern "C" void __cdecl sub_00244420(int);

class Class_002530A0
{
public:
    void sub_002530A0(int a1, int a2);
    char m_pad00[0x10];
    int m_Field10; // +0x10
};

void Class_002530A0::sub_002530A0(int a1, int a2)
{
    int t1, t2;

    t1 = m_Field10;
    t2 = sub_00244410();
    sub_00244420(t1);
    ((Object*)a1)->sub_00254C40(9, a2);
    ((Object*)a1)->sub_00254C40(8, a2);
    ((Object*)a1)->sub_00254C40(11, a2);
    ((Object*)a1)->sub_00254C40(1, a2);
    ((Object*)a1)->sub_00254C40(2, a2);
    ((Object*)a1)->sub_00254C40(3, a2);
    ((Object*)a1)->sub_00254C40(4, a2);
    ((Object*)a1)->sub_00254C40(5, a2);
    ((Object*)a1)->sub_00254C40(6, a2);
    sub_00244420(t2);
}

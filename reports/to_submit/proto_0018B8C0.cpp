// bin: proto
// va: 0x0018B8C0
// what: 
// tool: the portal's starter code (no AI)

// sub_0018B8C0 (Proto 0x0018B8C0, 40 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0017C000(int);
};

extern "C" int __cdecl sub_0017BA20(void);
extern "C" int __cdecl sub_00201440(int, int);

void __cdecl sub_0018B8C0(int a1, int a2, int a3)
{
    int t1;

    t1 = sub_0017BA20();
    if (t1) {
        ((Object*)t1)->sub_0017C000(sub_00201440(*(int*)(a3 + 4), 0));
    }
}

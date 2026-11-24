// bin: xb
// va: 0x001BD5E0
// what: 
// tool: the portal's starter code (no AI)

// sub_001BD5E0 (0x001BD5E0, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_00195650(int, int);
    void sub_00196030(int);
};

extern "C" int DAT_0048C23C;
extern "C" int __cdecl sub_00099BC0(int);

void __cdecl sub_001BD5E0(int a1, int a2, int a3)
{
    int t2;

    t2 = DAT_0048C23C;
    ((Object*)t2)->sub_00196030(((Object*)t2)->sub_00195650(*(int*)(a3 + 4), sub_00099BC0(*(int*)(a3 + 8))));
}

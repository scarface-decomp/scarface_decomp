// bin: xb
// va: 0x0021D990
// what: 
// tool: the portal's starter code (no AI)

// sub_0021D990 (0x0021D990, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00243FA0(int, int);

class Class_0021D990
{
public:
    int sub_0021D990(int a1);
    int sub_0021D940(int);
};

int Class_0021D990::sub_0021D990(int a1)
{
    int t2;

    t2 = sub_0021D940(sub_00243FA0(a1, 0));
    if (t2) {
        return *(short*)(t2 + 16);
    }
    return 0;
}

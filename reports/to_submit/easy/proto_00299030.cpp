// bin: proto
// va: 0x00299030
// tool: the portal's starter code (no AI)
// sub_00299030 (0x00299030, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0029B950(int, int);

class Class_00299030
{
public:
    int sub_00299030(int a1, int a2);
};

int Class_00299030::sub_00299030(int a1, int a2)
{
    a2 = *(int*)a2;
    return sub_0029B950(a1, a2);
}

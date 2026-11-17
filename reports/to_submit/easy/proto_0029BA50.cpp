// bin: proto
// va: 0x0029BA50
// tool: the portal's starter code (no AI)
// sub_0029BA50 (0x0029BA50, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __stdcall sub_0029C650(int);

class Class_0029BA50
{
public:
    int sub_0029BA50(int a1);
};

int Class_0029BA50::sub_0029BA50(int a1)
{
    a1 = *(int*)a1;
    return sub_0029C650(a1);
}

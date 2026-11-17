// bin: xb
// va: 0x00218050
// tool: the portal's starter code (no AI)
// sub_00218050 (0x00218050, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_00218050
{
public:
    int sub_00218050(int a1);
};

int Class_00218050::sub_00218050(int a1)
{
    return sub_0002AC90(*(int*)((int)this + (a1 * 4) + 1572));
}

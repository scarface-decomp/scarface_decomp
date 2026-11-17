// bin: xb
// va: 0x001936C0
// tool: the portal's starter code (no AI)
// sub_001936C0 (0x001936C0, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001936C0
{
public:
    int sub_001936C0(int a1, int a2);
};

int Class_001936C0::sub_001936C0(int a1, int a2)
{
    return *(int*)((int)this + ((a1 + (a2 * 2) + a2) * 4) + 44) != 0;
}

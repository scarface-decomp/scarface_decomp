// bin: proto
// va: 0x001A7D70
// what: 
// tool: the portal's starter code (no AI)

// sub_001A7D70 (Proto 0x001A7D70, 29 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_001A7D70
{
public:
    int sub_001A7D70(int a1, int a2, int a3);
};

int Class_001A7D70::sub_001A7D70(int a1, int a2, int a3)
{
    *(int*)((int)this + (a1 * 4) + 224) = a2;
    *(int*)((int)this + (a1 * 4) + 248) = a3;
    return a1;
}

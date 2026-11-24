// bin: proto
// va: 0x00012EB0
// what: 
// tool: the portal's starter code (no AI)

// sub_00012EB0 (Proto 0x00012EB0, 12 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    int sub_0008E380();
};

class Class_00012EB0
{
public:
    int sub_00012EB0();
};

int Class_00012EB0::sub_00012EB0()
{
    return (short)((unsigned short)((Object*)(int)this + 48)->sub_0008E380());
}

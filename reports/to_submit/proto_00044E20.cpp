// bin: proto
// va: 0x00044E20
// what: 
// tool: the portal's starter code (no AI)

// sub_00044E20 (Proto 0x00044E20, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_000EF610(int);

class Class_00044E20
{
public:
    int sub_00044E20(int a1);
};

int Class_00044E20::sub_00044E20(int a1)
{
    return sub_000EF610(*(int*)((a1 << 4) + (int)this + 92));
}

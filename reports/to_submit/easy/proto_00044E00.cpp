// bin: proto
// va: 0x00044E00
// tool: the portal's starter code (no AI)
// sub_00044E00 (0x00044E00, 23 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_002862E0(int);

class Class_00044E00
{
public:
    int sub_00044E00(int a1);
};

int Class_00044E00::sub_00044E00(int a1)
{
    return sub_002862E0(*(int*)((a1 << 4) + (int)this + 92));
}

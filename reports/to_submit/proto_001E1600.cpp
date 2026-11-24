// bin: proto
// va: 0x001E1600
// what: 
// tool: the portal's starter code (no AI)

// sub_001E1600 (Proto 0x001E1600, 43 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00201440(int, int);

class Class_001E1600
{
public:
    int sub_001E1600(int a1);
    int sub_001E15B0(int);
};

int Class_001E1600::sub_001E1600(int a1)
{
    int t2;

    t2 = sub_001E15B0(sub_00201440(a1, 0));
    if (t2) {
        return *(short*)(t2 + 16);
    }
    return 0;
}

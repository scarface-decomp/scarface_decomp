// bin: xb
// va: 0x002492A0
// what: 
// tool: the portal's starter code (no AI)

// sub_002492A0 (0x002492A0, 59 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.
// This function keeps a frame pointer (push ebp; mov ebp, esp), so it is built with them on.
#pragma optimize("y", off)

extern "C" char DAT_003D4F7C[];
extern "C" int __cdecl sub_00027590(int);
extern "C" int __cdecl sub_0024B8F0(int);
extern "C" void __cdecl sub_0024B910(int, int, int);

class Class_002492A0
{
public:
    Class_002492A0* sub_002492A0(int a1);
    int m_Field00; // +0x00
    int m_Field04; // +0x04
};

Class_002492A0* Class_002492A0::sub_002492A0(int a1)
{
    int t1, t2;

    m_Field00 = (int)DAT_003D4F7C;
    t1 = sub_0024B8F0(a1);
    t2 = sub_00027590(t1 + t1 + 2);
    m_Field04 = t2;
    sub_0024B910(a1, t2, t1 + 1);
    return this;
}

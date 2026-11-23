// bin: proto
// va: 0x001DBB30
// what: 
// tool: the portal's starter code (no AI)

// sub_001DBB30 (Proto 0x001DBB30, 30 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_000D99E0();
};

extern "C" int __stdcall sub_000D8FA0(int, int, int);

class Class_001DBB30
{
public:
    void sub_001DBB30(int a1);
    char m_pad00[0xA8];
    int m_FieldA8; // +0xA8
};

void Class_001DBB30::sub_001DBB30(int a1)
{
    m_FieldA8 = a1;
    ((Object*)sub_000D8FA0(17, a1, 0))->sub_000D99E0();
}

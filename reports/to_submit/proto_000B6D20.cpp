// bin: proto
// va: 0x000B6D20
// what: 
// tool: the portal's starter code (no AI)

// sub_000B6D20 (Proto 0x000B6D20, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00028120(int);

class Class_000B6D20
{
public:
    int sub_000B6D20();
    int m_Field00; // +0x00
};

int Class_000B6D20::sub_000B6D20()
{
    return sub_00028120(m_Field00) != 0;
}

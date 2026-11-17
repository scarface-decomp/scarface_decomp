// bin: xb
// va: 0x001F3980
// tool: the portal's starter code (no AI)
// sub_001F3980 (0x001F3980, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_0002AC90(int);

class Class_001F3980
{
public:
    int sub_001F3980();
    char m_pad00[0x164];
    int m_Field164; // +0x164
};

int Class_001F3980::sub_001F3980()
{
    return sub_0002AC90(m_Field164);
}

// bin: xb
// va: 0x0009E420
// tool: the portal's starter code (no AI)
// sub_0009E420 (0x0009E420, 15 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" float DAT_003A49EC;

class Class_0009E420
{
public:
    Class_0009E420* sub_0009E420();
    float m_Field00; // +0x00
};

Class_0009E420* Class_0009E420::sub_0009E420()
{
    m_Field00 = DAT_003A49EC;
    return this;
}

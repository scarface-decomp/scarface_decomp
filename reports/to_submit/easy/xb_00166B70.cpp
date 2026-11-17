// bin: xb
// va: 0x00166B70
// tool: the portal's starter code (no AI)
// sub_00166B70 (0x00166B70, 55 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Field2AC
{
    bool sub_0017DAA0(int, int, int);
    bool sub_0017E430(int);
};

class Class_00166B70
{
public:
    bool sub_00166B70(int a1, int a2, int a3);
    char m_pad00[0x2AC];
    Field2AC m_Field2AC; // +0x2AC
};

bool Class_00166B70::sub_00166B70(int a1, int a2, int a3)
{
    if (m_Field2AC.sub_0017DAA0((int)(&a1), a2, a3)) {
        return m_Field2AC.sub_0017E430(a1);
    }
    return false;
}

// bin: proto
// va: 0x00200260
// tool: the portal's starter code (no AI)
// sub_00200260 (0x00200260, 16 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_00200260
{
public:
    int sub_00200260(int a1);
    int m_Field00; // +0x00
};

int Class_00200260::sub_00200260(int a1)
{
    return m_Field00 == *(int*)a1;
}

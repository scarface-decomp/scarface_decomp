// bin: xb
// va: 0x0002BF50
// tool: the portal's starter code (no AI)
// sub_0002BF50 (0x0002BF50, 32 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

class Class_0002BF50
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03(int);
    void sub_0002BF50(int a1);
    void sub_0002B420();
    char m_pad04[0x1A];
    unsigned char m_Field1E; // +0x1E
};

void Class_0002BF50::sub_0002BF50(int a1)
{
    vfunc_03(a1);
    if (m_Field1E & 2) {
        sub_0002B420();
    }
}

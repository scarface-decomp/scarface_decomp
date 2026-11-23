// bin: proto
// va: 0x0016A960
// what: 
// tool: the portal's starter code (no AI)

// sub_0016A960 (Proto 0x0016A960, 18 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" void __cdecl sub_0016A830(void);

class Class_0016A960
{
public:
    void sub_0016A960(int a1);
    char m_pad00[0x1AC];
    int m_Field1AC; // +0x1AC
};

void Class_0016A960::sub_0016A960(int a1)
{
    m_Field1AC = a1;
    sub_0016A830();
}

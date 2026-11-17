// bin: xb
// va: 0x0002BF70
// tool: the portal's starter code (no AI)
// sub_0002BF70 (0x0002BF70, 47 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" int __cdecl sub_00076DB0(int, int);

class Class_0002BF70
{
public:
    void sub_0002BF70(int a1);
    void sub_0002B420();
    char m_pad00[0x8];
    int m_Field08; // +0x08
    char m_pad0C[0x12];
    unsigned char m_Field1E; // +0x1E
};

void Class_0002BF70::sub_0002BF70(int a1)
{
    if (a1) {
        if (!*(unsigned char*)a1) goto L_1E;
        m_Field08 = sub_00076DB0(a1, 0);
    }
L_1E:
    if (m_Field1E & 2) {
        sub_0002B420();
    }
}

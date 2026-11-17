// bin: proto
// va: 0x001ED1A0
// tool: the portal's starter code (no AI)
// TutorialPresentationState::vfunc_12 (0x001ED1A0, 67 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    void sub_0016F030();
};

extern "C" char DAT_003ABBC0[];
extern "C" int DAT_0045E07C;
extern "C" bool DAT_00462F96;
extern "C" bool __cdecl sub_00059BF0(int);
extern "C" void __cdecl sub_00065ED0(int, int, int, int, int);

class TutorialPresentationState
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05();
    virtual void vfunc_06();
    virtual void vfunc_07();
    virtual void vfunc_08();
    virtual void vfunc_09();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    char m_pad04[0x4];
    int m_Field08; // +0x08
};

void TutorialPresentationState::vfunc_12()
{
    if (sub_00059BF0(0)) {
        sub_00065ED0((int)DAT_003ABBC0, 0, 0, 0, -1);
        if (!DAT_00462F96) {
            ((Object*)DAT_0045E07C)->sub_0016F030();
        }
        m_Field08 = 10;
    }
}

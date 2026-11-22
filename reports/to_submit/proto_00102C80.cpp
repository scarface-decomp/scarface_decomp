// bin: proto
// va: 0x00102C80
// what: 
// tool: the portal's starter code (no AI)

// AIStimulusDetectorScriptEvent::vfunc_03 (Proto 0x00102C80, 41 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

struct Object
{
    bool sub_000F7950(int);
};

class AIStimulusDetectorScriptEvent
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual int vfunc_03(int a1);
};

int AIStimulusDetectorScriptEvent::vfunc_03(int a1)
{
    int t1;

    t1 = *(int*)a1;
    if (*(unsigned char*)(*(int*)a1 + 1) == 1) {
        if (!((Object*)(int)this + 12)->sub_000F7950(t1 + 4)) goto L_24;
        return 1;
    }
L_24:
    return 0;
}

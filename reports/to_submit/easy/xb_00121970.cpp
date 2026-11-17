// bin: xb
// va: 0x00121970
// tool: the portal's starter code (no AI)
// AIConditionLowPriorityNPCSoundChannelsBusy::vfunc_04 (0x00121970, 11 bytes)
// Starter code written from the disassembly. Names and types are guesses; rename and
// retype them as you work it out. Calls and globals already use their real addresses.

extern "C" bool __cdecl sub_0007DD00(void);

class AIConditionLowPriorityNPCSoundChannelsBusy
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual int vfunc_04();
};

int AIConditionLowPriorityNPCSoundChannelsBusy::vfunc_04()
{
    return !sub_0007DD00();
}

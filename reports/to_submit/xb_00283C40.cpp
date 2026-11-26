// bin: xb
// va: 0x00283C40
// what: Takes a thread's record out of the list of all threads, inside the list's lock.
// tool: Claude (from SPEC-018)

struct Thread;

// One fiber of a thread (0x24 bytes).
struct Fiber
{
    int (__cdecl* m_Entry)(void* argument);     // +0x00
    void* m_Argument;       // +0x04
    Thread* m_Owner;        // +0x08
    Fiber* m_Next;          // +0x0C
    Fiber* m_Previous;      // +0x10
    void* m_SystemFiber;    // +0x14
    int m_Field18;          // +0x18
    int m_Field1C;          // +0x1C
    int m_Field20;          // +0x20
};

// A thread's record (0x4C bytes). Its first fiber is part of it.
struct Thread
{
    Thread* m_Next;         // +0x00
    Thread* m_Previous;     // +0x04
    Fiber m_FirstFiber;     // +0x08
    Fiber* m_CurrentFiber;  // +0x2C
    Fiber* m_FiberHead;     // +0x30
    Fiber* m_FiberTail;     // +0x34
    bool m_Running;         // +0x38
    int m_Result;           // +0x3C
    int m_Priority;         // +0x40
    unsigned int m_Id;      // +0x44
    void* m_Handle;         // +0x48
};

extern "C" int DAT_0039D28C;        // kernel import: RtlLeaveCriticalSection
extern "C" int DAT_0039D290;        // kernel import: RtlEnterCriticalSection
extern "C" Thread* DAT_004BDD1C;    // the last thread in the list of all threads
extern "C" Thread* DAT_004BDD20;    // the first
extern "C" char DAT_004BDD28[];     // the critical section that guards the list

void __cdecl sub_00283C40(Thread* thread)
{
    ((void (__stdcall*)(char*))DAT_0039D290)(DAT_004BDD28);
    if (thread->m_Previous == 0)
    {
        DAT_004BDD20 = thread->m_Next;
    }
    else
    {
        thread->m_Previous->m_Next = thread->m_Next;
    }
    if (thread->m_Next == 0)
    {
        DAT_004BDD1C = thread->m_Previous;
    }
    else
    {
        thread->m_Next->m_Previous = thread->m_Previous;
    }
    ((void (__stdcall*)(char*))DAT_0039D28C)(DAT_004BDD28);
}

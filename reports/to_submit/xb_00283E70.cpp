// bin: xb
// va: 0x00283E70
// what: What a new thread runs first: turns itself into a fiber, calls the thread's function, keeps its result and marks the thread as finished.
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

extern "C" void* __stdcall sub_00309527(void* parameter);       // ConvertThreadToFiber

unsigned int __stdcall sub_00283E70(Thread* thread)
{
    thread->m_FirstFiber.m_Field18 = 0;
    thread->m_FirstFiber.m_SystemFiber = sub_00309527(0);
    thread->m_Result = thread->m_FirstFiber.m_Entry(thread->m_FirstFiber.m_Argument);
    thread->m_Running = false;
    thread->m_FirstFiber.m_Field20 = 0;
    return 0;
}

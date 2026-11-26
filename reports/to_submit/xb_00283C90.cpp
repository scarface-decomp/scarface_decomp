// bin: xb
// va: 0x00283C90
// what: Fills in a thread record for the thread that calls it: its first fiber, its place in the list of all threads, normal priority.
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

extern "C" int DAT_0045B0AC[5];     // the system priority for each of the library's five priorities
extern "C" unsigned int __stdcall GetCurrentThreadId();
extern "C" int __stdcall SetThreadPriority(void* handle, int priority);
extern "C" void* __stdcall sub_00309527(void* parameter);       // ConvertThreadToFiber
void __cdecl sub_00283BF0(Thread* thread);                      // adds it to the list of all threads

// Adds a fiber to the end of its thread's list of fibers.
inline void AppendFiber(Thread* thread, Fiber* fiber)
{
    if (thread->m_FiberHead == 0)
    {
        thread->m_FiberHead = fiber;
        fiber->m_Previous = 0;
    }
    else
    {
        thread->m_FiberTail->m_Next = fiber;
        fiber->m_Previous = thread->m_FiberTail;
    }
    thread->m_FiberTail = fiber;
    fiber->m_Next = 0;
}

// Records the thread's priority (0 to 4) and gives the system thread the matching system priority.
inline void SetPriority(Thread* thread, int priority)
{
    thread->m_Priority = priority;
    SetThreadPriority(thread->m_Handle, DAT_0045B0AC[priority]);
}

void __cdecl sub_00283C90(Thread* thread)
{
    thread->m_FiberHead = 0;
    thread->m_FiberTail = 0;
    thread->m_Running = true;
    thread->m_Id = GetCurrentThreadId();
    thread->m_Handle = (void*)0xFFFFFFFE;
    thread->m_FirstFiber.m_Field20 = 0;
    thread->m_FirstFiber.m_Entry = 0;
    thread->m_FirstFiber.m_Argument = 0;
    thread->m_FirstFiber.m_SystemFiber = sub_00309527(0);
    thread->m_FirstFiber.m_Owner = thread;
    thread->m_FirstFiber.m_Field18 = 0;
    thread->m_FirstFiber.m_Field1C = 0;
    thread->m_CurrentFiber = &thread->m_FirstFiber;
    AppendFiber(thread, &thread->m_FirstFiber);
    sub_00283BF0(thread);
    SetPriority(thread, 2);
}

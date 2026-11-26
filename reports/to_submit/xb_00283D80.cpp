// bin: xb
// va: 0x00283D80
// what: Starts the thread library: makes the lock for the list of all threads and sets up the record of the thread that calls it.
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

extern "C" int DAT_0039D358;        // kernel import: RtlInitializeCriticalSection
extern "C" Thread DAT_004BDCD0;     // the record of the thread that started the library
extern "C" bool DAT_004BDD24;       // the library has been started
extern "C" char DAT_004BDD28[];     // the critical section that guards the list of all threads
void __cdecl sub_00250EC0();
void __cdecl sub_00283C90(Thread* thread);      // sets up a record for the calling thread

void __cdecl sub_00283D80(void* unused)
{
    ((void (__stdcall*)(char*))DAT_0039D358)(DAT_004BDD28);
    DAT_004BDD24 = true;
    sub_00250EC0();
    sub_00283C90(&DAT_004BDCD0);
}

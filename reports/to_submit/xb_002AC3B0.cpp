// bin: xb
// va: 0x002AC3B0
// what: Drops one reference inside the lock; when it was the last, the object is destroyed and its memory freed.
// tool: Claude (from SPEC-017)

// A system semaphore's handle.
struct Semaphore
{
    void* m_Handle; // +0x0
};

struct Thread;

Thread* __cdecl sub_00283EB0();                     // the calling thread's record
void __cdecl sub_00283BD0(Semaphore* semaphore);    // signal it once

namespace core
{
    class Drive;
    class DriveThread;

    // A piece of work queued for a drive.
    class Request
    {
    public:
        virtual ~Request();
        virtual int Do();
        virtual bool ShouldCancel(int key);
        virtual Drive* GetDrive();
        virtual int Prepare();
        virtual int vfunc_05();
        virtual int vfunc_06();

        Request* m_Next;    // +0x04
    };

    // A finished request whose owner is still to be told, kept in a list until its thread asks.
    class CompletionCallbackRequest
    {
    public:
        virtual ~CompletionCallbackRequest();
        virtual void vfunc_01();
        virtual void vfunc_02();
        virtual void vfunc_03();
        virtual void vfunc_04();
        virtual void vfunc_05();
        virtual void vfunc_06();
        virtual void Finish();
        bool sub_00239EC0(Thread* thread);      // whether this request belongs to that thread

        CompletionCallbackRequest* m_Next;      // +0x04
    };

    // What the game registers to be asked about a drive's errors.
    class ErrorHandler
    {
    public:
        virtual bool OnError(int error, const char* driveName, int a, int b, void* userData);
    };

    // The three base parts (SPEC-017 section 1).
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
        virtual void vfunc_02();
        virtual void vfunc_03();
    };

    class Object
    {
    public:
        virtual void Object00();
        void* m_Allocator;  // +0x08
    };

    class SafeRefCount
    {
    public:
        virtual void Lock();
        virtual void Unlock();
        virtual ~SafeRefCount();
        void sub_002AC3B0();

        int m_RefCount;     // +0x10
    };

    class Drive : public IRefCount, public Object, public SafeRefCount
    {
    public:
        virtual void Service();
        virtual const char* GetName();


        char m_Libraries[0x40];             // +0x14  the list of file libraries
        CompletionCallbackRequest* m_Head;  // +0x54  finished requests waiting for their thread
        CompletionCallbackRequest* m_Tail;  // +0x58
        int m_ErrorBehaviour;               // +0x5C  0, or 2 once a handler or a semaphore is set
        Semaphore* m_ErrorSemaphore;        // +0x60
        Thread* m_HandlerThread;            // +0x64
        ErrorHandler* m_Handler;            // +0x68
        void* m_UserData;                   // +0x6C
        bool m_InError;                     // +0x70
        Request* m_Failed;                  // +0x74  the request that failed
        bool m_ReportClear;                 // +0x78
        bool m_InHandler;                   // +0x79
        char m_Media[0x54];                 // +0x7C  media information
        int m_LastError;                    // +0xD0
        DriveThread* m_Thread;              // +0xD4
    };
}

void core::SafeRefCount::sub_002AC3B0()
{
    Lock();
    --m_RefCount;
    if (m_RefCount == 0)
    {
        m_RefCount = 0x5DC;
        Unlock();
        delete this;
    }
    else
    {
        Unlock();
    }
}

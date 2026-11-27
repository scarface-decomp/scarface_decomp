// bin: xb
// va: 0x002AAB70
// what: Constructs the base of every request on a drive handle: counts the request on its owner and adds a reference to it.
// tool: Claude (from SPEC-020)

extern "C" char DAT_003DA6C8[];     // core::Request's table
extern "C" char DAT_003DA750[];     // core::FileRequest's
extern "C" char DAT_003DA790[];     // core::DriveRequest's
extern "C" char DAT_003DA7B0[];     // core::CompletionCallbackRequest's
extern "C" char DAT_003DA708[];     // core::FileCompletionRequest's
extern "C" char DAT_003DA72C[];     // core::DriveCompletionRequest's
extern "C" char DAT_003DA770[];     // core::FileOpenByKeyRequest's
extern "C" char DAT_003DA9B4[];     // core::DriveFindFirstRequest's
extern "C" char DAT_004BDD44[];     // the lock around the request allocator

const char* __cdecl sub_00250EB0();             // the library's name ("core"); every constructor level calls it
void __cdecl sub_00283B80(void* lock);          // take a lock
void __cdecl sub_00283B70(void* lock);          // let it go
extern "C" char* __cdecl strncpy(char* to, const char* from, unsigned int count);

// The allocator requests come from.
class Allocator
{
public:
    virtual void vfunc_00();
    virtual void vfunc_01();
    virtual void vfunc_02();
    virtual void vfunc_03();
    virtual void vfunc_04();
    virtual void vfunc_05(void* memory);    // give memory back
};
extern "C" Allocator* DAT_004BDD60;

namespace core
{
    class IRefCount
    {
    public:
        virtual void AddRef();
        virtual void Release();
    };

    class IMutable
    {
    public:
        virtual void Lock();
        virtual void Unlock();
    };

    // The two owners a request counts itself on (SPEC-019): only what the requests use.
    class File : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        void* m_Drive;          // +0x0C
        int m_Priority;         // +0x10
        int m_LastError;        // +0x14
        int m_Outstanding;      // +0x18
    };

    class InstanceDrive : public IRefCount, public IMutable
    {
    public:
        int m_RefCount;         // +0x08
        void* m_Drive;          // +0x0C
        int m_Priority;         // +0x10
        int m_Outstanding;      // +0x14
    };

    // What a completion request calls back; counted like the owners.
    class Callback : public IRefCount
    {
    };

    // A request with its table written as a member: these are its constructors and destructors.
    class DriveRequest
    {
    public:
        DriveRequest* sub_002AAB70(InstanceDrive* owner);
        void* m_Table;          // +0x00
        void* m_Next;           // +0x04
        InstanceDrive* m_Owner;       // +0x08
    };
}

core::DriveRequest* core::DriveRequest::sub_002AAB70(InstanceDrive* owner)
{
    m_Table = DAT_003DA6C8;
    m_Next = 0;
    sub_00250EB0();
    m_Table = DAT_003DA790;
    m_Owner = owner;
    sub_00250EB0();
    m_Owner->Lock();
    m_Owner->m_Outstanding++;
    m_Owner->Unlock();
    m_Owner->AddRef();
    return this;
}

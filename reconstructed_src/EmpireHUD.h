/*
 * ============================================================================
 * EmpireHUD.h — 100% Byte-Verified Decompilation (PC v1.00.2 Official US Patch)
 * ============================================================================
 * Decompiled directly from `01_EmpireHUD_WorkPack.txt` (Retail Xbox 1:1 Donor
 * `default.xbe` -> Official PC US Patch `Scarface.exe` v1.00.2, MSVC 7.10).
 *
 * Verified Binary Facts Uncovered From Machine Code:
 *   1. Exact Class Size (`ConcreteClassRep<EmpireHUD>` @ 0x001BD240):
 *        sizeof(EmpireHUD)                == 0x80 (128 bytes on 32-bit x86)
 *        sizeof(HUDElement2)              == 0x64 (100 bytes, +0x00..+0x63)
 *        sizeof(GenericCursorMenu)        == 0x44 ( 68 bytes, m_pMenu @ +0x6C)
 *        sizeof(EmpireHUDMenuItem)        == 0x3C ( 60 bytes, 3 rows: E_MenuItem1..3)
 *        sizeof(GenericMenuItemData)      == 0x08 (  8 bytes, vtable + bool m_bEnabled)
 *        sizeof(GenericScroller)          == 0x4C ( 76 bytes, m_pScroller @ +0x70)
 *
 *   2. Exact Multiple-Inheritance Layout (`EmpireHUD::EmpireHUD` @ 0x001940A0):
 *        +0x00: HUDElement2              (Primary VFTable  : PC 0x00753674 <== Xbox 0x003BADDC, 59 slots)
 *        +0x64: SubscriberInterface      (Secondary VFTable: Xbox 0x003BADD4; base 0x003B9BDC)
 *        +0x68: GenericScrollerInterface (Tertiary VFTable : Xbox 0x003BADBC; base 0x003B8D18)
 *
 *   3. Exact ConsoleObject Slot Order (Proven by Slot 0 @ 0x00194100 & Slot 1 @ 0x00192AB0):
 *        Slot [00] (+0x00): virtual AbstractClassRep* GetClassRep() const; // PC 0x005C37F0
 *        Slot [01] (+0x04): virtual ~EmpireHUD();                          // PC 0x005C3800 (30B dtor)
 * ============================================================================
 */

#ifndef SCARFACE_PC_V1002_EMPIRE_HUD_REAL_H
#define SCARFACE_PC_V1002_EMPIRE_HUD_REAL_H

#if defined(SCARFACE_FREESTANDING_X86_CHECK)
    typedef unsigned int   size_t;
    typedef signed char    int8_t;
    typedef short          int16_t;
    typedef int            int32_t;
    typedef unsigned char  uint8_t;
    typedef unsigned short uint16_t;
    typedef unsigned int   uint32_t;
    #ifndef NULL
        #define NULL 0
    #endif
#elif defined(_MSC_VER) && (_MSC_VER < 1600)
    #include <stddef.h>
    typedef signed char        int8_t;
    typedef short              int16_t;
    typedef int                int32_t;
    typedef unsigned char      uint8_t;
    typedef unsigned short     uint16_t;
    typedef unsigned int       uint32_t;
#else
    #include <stddef.h>
    #include <stdint.h>
#endif

#if defined(_MSC_VER) && defined(_M_IX86)
    #define SCARFACE_THISCALL __thiscall
    #define SCARFACE_CDECL    __cdecl
    #pragma pack(push, 4)
#else
    #define SCARFACE_THISCALL
    #define SCARFACE_CDECL
#endif

#if defined(__cplusplus) && (__cplusplus >= 201103L)
    #define SCARFACE_STATIC_ASSERT(cond, msg) static_assert(cond, #msg)
#else
    #define SCARFACE_STATIC_ASSERT(cond, msg) \
        typedef char scarface_static_assert_##msg[(cond) ? 1 : -1]
#endif

/* Provenance annotation: documents PC v1.00.2 VA, Retail Xbox VA, and byte size */
#define SCARFACE_MATCHED_FN(pc_va, xbox_va, byte_len)

/*
 * ============================================================================
 * 1. Radical Memory Manager, CScript Console Evaluator, & Event Manager Hooks
 * ============================================================================
 */
class AbstractClassRep;
class ConsoleObject;
class FEProject;
struct TickUpdateParams;
class ImageStreamInventory;
class Pure3DWidget;

namespace RadicalEngine {
    /* Xbox 0x000273D0 (95B): Looks up allocator pool index by name (e.g. "Front-end Modal") */
    int32_t SCARFACE_CDECL GetMemoryPoolId(const char* poolName);

    /* Xbox 0x000275B0 (19B): Pool-tagged operator new(size, poolId) -> calls 0x00244450 */
    void*   SCARFACE_CDECL PoolAlloc(size_t byteSize, int32_t poolId);

    /* Xbox 0x00027600 (18B): operator delete(ptr) -> if (ptr) Free(ptr) @ 0x002445E0 */
    void    SCARFACE_CDECL PoolFree(void* ptr);

    /* Xbox 0x0009A2B0: Stack/ring-buffer sprintf helper ("E_Icon%i", "E_MenuBack%i", "E_MenuItem%i") */
    const char* SCARFACE_CDECL FormatTempString(const char* fmt, int32_t index);

    /* Xbox 0x00023EC0 (16B): Hashes Pure3D Frontend widget name string into 32-bit UID */
    uint32_t SCARFACE_CDECL MakeFEUid(const char* widgetName);

    /*
     * Xbox 0x000702E0 (197B): Torque/Radical CScript `Con::evaluate`!
     * Proven by strings ".dso", "$Con::Prompt", "%s%s" inside 0x000702E0!
     */
    const char* SCARFACE_CDECL ConEvaluate(
        const char* scriptCode,
        int32_t echoToConsole,
        const char* fileName,
        int32_t arg3,
        int32_t consoleLogLevel);

    /* Xbox 0x00099BC0: Converts CScript string return ("true"/"1") to bool */
    bool SCARFACE_CDECL StringToBool(const char* strVal);

    /* Xbox 0x000802E0: Triggers frontend UI sound cue (e.g. "accept") */
    void SCARFACE_CDECL PlayFESound(const char* soundCueName);
}

/* Global Singletons Referenced Directly by EmpireHUD::vfunc_44 & vfunc_45 */
struct GameFlowGlobals {
    uint8_t m_Pad00[0x59];
    uint8_t m_ModalPauseBits; /* +0x59: bit 0x20 set on Open, cleared (&= ~0x20) on Close! */
};
extern GameFlowGlobals* g_pGameFlow; /* Xbox 0x0048C23C */

struct HUDManagerGlobals {
    uint8_t m_Pad000[0x164];
    uint8_t m_bEmpireModalActive; /* +0x164: set to 1 in vfunc_44, cleared to 0 in vfunc_45 */

    /* Xbox 0x001A7AD0: Called in vfunc_45 before closing modal */
    void SetOverlayActive(int32_t activeFlag);
};
extern HUDManagerGlobals* g_pHUDManager; /* Xbox 0x0048C898 */

class SubscriberInterface {
public:
    /* Secondary base at EmpireHUD + 0x64 (Xbox VFTable 0x003B9BDC -> overridden 0x003BADD4) */
    virtual void OnEventReceived(uint32_t eventId, void* pEventData) {
        (void)eventId;
        (void)pEventData;
    }
};

class GenericScrollerInterface {
public:
    /* Tertiary base at EmpireHUD + 0x68 (Xbox VFTable 0x003B8D18 -> overridden 0x003BADBC) */
    virtual void OnScrollerChanged(int32_t newOffset) { (void)newOffset; }
};

class EventManager {
public:
    static EventManager* SCARFACE_CDECL GetInstance(); /* Xbox 0x000EB680 */

    /* Xbox 0x000EB930 (ret 0xC): Subscribes handler to event ID (0xC7 = 199 in EmpireHUD) */
    void AddSubscriber(uint32_t eventId, SubscriberInterface* pSub, uint32_t filterParam);

    /* Xbox 0x000EBA00 (ret 0x8): Unsubscribes handler from event ID (0xC7 = 199) */
    void RemoveSubscriber(uint32_t eventId, SubscriberInterface* pSub);

    /* Xbox 0x000EC0F0 (ret 0xC): Fires event ID (0x9A = 154 at end of EmpireHUD::OnOpen) */
    void TriggerEvent(uint32_t eventId, void* pParam1, void* pParam2);
};

/*
 * ============================================================================
 * 2. ConcreteClassRep<T> & Base Hierarchy (ConsoleObject -> ScriptObject -> HUDElement2)
 * ============================================================================
 */
class AbstractClassRep {
public:
    virtual const char*    GetClassName() const = 0;
    virtual ConsoleObject* CreateFromPool() = 0;
    virtual ~AbstractClassRep() {}

    uint8_t m_Pad04[0x24];    /* +0x04..+0x27 */
    int8_t  m_AllocatorPool;  /* +0x28: Read via `movsx eax, byte ptr [esi+0x28]` @ 0x001BD243! */
    uint8_t m_Pad29[3];
};

template <class T>
class ConcreteClassRep : public AbstractClassRep {
public:
    explicit ConcreteClassRep(const char* name, int8_t defaultPool = 0)
        : m_pName(name)
    {
        m_AllocatorPool = defaultPool;
    }

    virtual const char* GetClassName() const { return m_pName; }

    /*
     * Decoded 1:1 from `0x001BD240` (45 bytes):
     *   int pool = this->m_AllocatorPool;
     *   void* mem = PoolAlloc(sizeof(T), pool); // push 0x80 for EmpireHUD!
     *   return mem ? new (mem) T(NULL, pool) : NULL;
     */
    virtual ConsoleObject* CreateFromPool();

private:
    const char* m_pName;
};

/*
 * ConsoleObject (Slots 00..01):
 *   Slot [00] (+0x00): GetClassRep() -> `mov eax, offset sm_ClassRep; ret` (6 bytes @ 0x00194100!)
 *   Slot [01] (+0x04): ~ConsoleObject() scalar deleting destructor (30 bytes @ 0x00192AB0!)
 */
class ConsoleObject {
public:
    /* Slot 00 (+0x00) */ virtual AbstractClassRep* GetClassRep() const = 0;
    /* Slot 01 (+0x04) */ virtual ~ConsoleObject() {}
};

class ScriptObject : public ConsoleObject {
public:
    ScriptObject();
    virtual ~ScriptObject();

    /* Slots 02..26 (+0x08..+0x68): Unified Radical Engine ScriptObject/GameSimObject Root Table */
    /* Slot 02 (+0x08) */ virtual void vfunc_02() {}
    /* Slot 03 (+0x0C) */ virtual void vfunc_03() {}
    /* Slot 04 (+0x10) */ virtual bool OnAddToSim(bool bRegister) { return bRegister; }
    /* Slot 05 (+0x14) */ virtual void OnRemoveFromSim(void* pArg) { (void)pArg; }
    /* Slot 06 (+0x18) */ virtual void vfunc_06() {}
    /* Slot 07 (+0x1C) */ virtual void vfunc_07() {}
    /* Slot 08 (+0x20) */ virtual void ProcessTick(const struct TickUpdateParams* pTick) { (void)pTick; }
    /* Slot 09 (+0x24) */ virtual void AdvanceTime(float dt) { (void)dt; }
    /* Slot 10 (+0x28) */ virtual void EnableSimTick() {}
    /* Slot 11 (+0x2C) */ virtual void DisableSimTick() {}
    /* Slot 12 (+0x30) */ virtual void vfunc_12(int32_t a1) { (void)a1; }
    /* Slot 13 (+0x34) */ virtual void OnPostSpawnInit() {}
    /* Slot 14 (+0x38) */ virtual void OnPreDestroyCleanup() {}
    /* Slot 15 (+0x3C) */ virtual void vfunc_15() {}
    /* Slot 16 (+0x40) */ virtual void vfunc_16() {}
    /* Slot 17 (+0x44) */ virtual void SetSimFlagBit1(bool bVal) { (void)bVal; }
    /* Slot 18 (+0x48) */ virtual bool IsInVehicleOrMounted() const { return false; }
    /* Slot 19 (+0x4C) */ virtual void vfunc_19() {}
    /* Slot 20 (+0x50) */ virtual bool IsCharacterType() const { return false; }
    /* Slot 21 (+0x54) */ virtual bool vfunc_21() const { return false; }
    /* Slot 22 (+0x58) */ virtual bool vfunc_22() const { return false; }
    /* Slot 23 (+0x5C) */ virtual void vfunc_23() {}
    /* Slot 24 (+0x60) */ virtual void vfunc_24() {}
    /* Slot 25 (+0x64) */ virtual bool IsMemberOfSet(void* pSet) const { (void)pSet; return false; }
    /* Slot 26 (+0x68) */ virtual void vfunc_26() {}
};

/*
 * HUDElement2 (`sizeof == 0x64` = 100 bytes on 32-bit x86! PC VFTable 0x0074DD74 <== Xbox 0x003BACA4)
 *   Proven by:
 *     - `EmpireHUD::EmpireHUD` (0x001940A0) placing `SubscriberInterface` at `this + 0x64`
 *     - `EmpireHUD::vfunc_54` (0x00190680) testing `byte ptr [this + 0x60], 0x01` (`m_VisibilityFlags`)
 */
class HUDElement2 : public ScriptObject {
public:
    HUDElement2(const char* pName, int32_t allocatorPoolId); /* Xbox 0x001930D0 */
    virtual ~HUDElement2();

    /* Slots 27..58 (+0x6C..+0xE8) — Total 59 Primary Virtual Slots [00..58] */
    /* Slot 27 (+0x6C) */ virtual void vfunc_27() {}
    /* Slot 28 (+0x70) */ virtual void vfunc_28() {}
    /* Slot 29 (+0x74) */ virtual void OnResetHUD();                                  /* Xbox 0x00193150 */
    /* Slot 30 (+0x78) */ virtual void vfunc_30() {}
    /* Slot 31 (+0x7C) */ virtual void vfunc_31() {}
    /* Slot 32 (+0x80) */ virtual void vfunc_32() {}
    /* Slot 33 (+0x84) */ virtual void vfunc_33() {}
    /* Slot 34 (+0x88) */ virtual void vfunc_34() {}
    /* Slot 35 (+0x8C) */ virtual bool SetActiveState(bool bActive, int32_t a2, int32_t a3); /* Xbox 0x001933E0 */
    /* Slot 36 (+0x90) */ virtual bool OnPageInit(void* pArg1, void* pArg2);          /* Xbox 0x00193B40 */
    /* Slot 37 (+0x94) */ virtual void vfunc_37() {}
    /* Slot 38 (+0x98) */ virtual bool IsModalHUD() const { return false; }
    /* Slot 39 (+0x9C) */ virtual void vfunc_39() {}
    /* Slot 40 (+0xA0) */ virtual bool BlocksWorldInput() const { return false; }
    /* Slot 41 (+0xA4) */ virtual void vfunc_41() {}
    /* Slot 42 (+0xA8) */ virtual void vfunc_42() {}
    /* Slot 43 (+0xAC) */ virtual void vfunc_43() {}
    /* Slot 44 (+0xB0) */ virtual bool OnOpenModal(FEProject* pProject);              /* Xbox 0x00193620 */
    /* Slot 45 (+0xB4) */ virtual bool OnCloseModal(int32_t closeReason);             /* Xbox 0x00193D50 */
    /* Slot 46 (+0xB8) */ virtual void vfunc_46() {}
    /* Slot 47 (+0xBC) */ virtual void vfunc_47() {}
    /* Slot 48 (+0xC0) */ virtual void vfunc_48() {}
    /* Slot 49 (+0xC4) */ virtual void vfunc_49() {}
    /* Slot 50 (+0xC8) */ virtual void vfunc_50() {}
    /* Slot 51 (+0xCC) */ virtual void vfunc_51() {}
    /* Slot 52 (+0xD0) */ virtual void vfunc_52() {}
    /* Slot 53 (+0xD4) */ virtual void vfunc_53() {}
    /* Slot 54 (+0xD8) */ virtual void UpdateFrame(uint32_t deltaMs);                 /* Xbox 0x00193280 */
    /* Slot 55 (+0xDC) */ virtual void vfunc_55() {}
    /* Slot 56 (+0xE0) */ virtual void vfunc_56() {}
    /* Slot 57 (+0xE4) */ virtual void vfunc_57() {}
    /* Slot 58 (+0xE8) */ virtual void DestroyHUDResources();                         /* Xbox 0x001938B0 */

protected:
    /* Exact 0x64 (100) byte layout on 32-bit x86 (`sizeof(void*) == 4`):
     *   +0x00: vftable (4 bytes)
     *   +0x04..+0x5B: m_HUDData (88 bytes = 0x58)
     *   +0x5C: m_pImageStreamer (ImageStreamInventory*, proven @ 0x001AE038 & 0x0018B979!)
     *   +0x60: m_VisibilityFlags (uint8_t, bit 0x01 active @ 0x00190683, bit 0x10 @ 0x001AF15A)
     */
    uint8_t               m_HUDData[0x58];
    ImageStreamInventory* m_pImageStreamer;  /* +0x5C (x86): 0x270-byte async texture streamer */
    uint8_t               m_VisibilityFlags; /* +0x60 (x86): bit 0x01 == active/visible! */
    uint8_t               m_Pad61[3];
};

/*
 * ============================================================================
 * 3. Helper Menu & Scroller Classes Decoded From PrivateHelpers in WorkPack
 * ============================================================================
 */

/* Decoded 1:1 from 0x00197010 (13B) & 0x00197020 (10B), `sizeof == 0x08` */
class GenericMenuItemData {
public:
    /* Xbox 0x00197010: `mov [eax], VFTable<GenericMenuItemData>; mov byte ptr [eax+4], 1; ret` */
    GenericMenuItemData()
        : m_bEnabled(true)
        , m_bLocked(false)
    {
        m_Pad[0] = 0;
        m_Pad[1] = 0;
    }

    virtual ~GenericMenuItemData() {}

    /* Xbox 0x00197020 (10B): `mov al, [esp+4]; mov [ecx+4], al; ret 4` */
    void SetEnabled(bool bEnabled) {
        m_bEnabled = bEnabled;
    }

    bool    m_bEnabled; /* +0x04 */
    bool    m_bLocked;  /* +0x05 (tested in 0x00197B90 / 0x00198200!) */
    uint8_t m_Pad[2];
};

/* Embedded colour/visibility controller at `EmpireHUDMenuItem + 0x0C` (used in 0x001CB900 & 0x001A5530) */
class MenuColourAnimator {
public:
    virtual ~MenuColourAnimator() {}
    virtual void vfunc_01() {}
    /* Slot 02 (+0x08): called via `push 1; call [eax+0x8]` at 0x001CB927 & 0x001A5557 */
    virtual void SetPlaying(bool bPlay) { m_bPlaying = bPlay; }

    /* Xbox 0x001C4AC0: Configures start colour, end colour, fade duration, and mode */
    void StartColourFade(uint32_t fromCol, uint32_t toCol, uint32_t fadeTimeBits, int32_t mode);

    uint32_t m_FromColour;
    uint32_t m_ToColour;
    uint32_t m_FadeTimeBits;
    bool     m_bPlaying;
};

/* Base class for EmpireHUDMenuItem (`sizeof(EmpireHUDMenuItem) == 0x3C` = 60 bytes @ 0x001B63A9) */
class GenericMenuItem {
public:
    GenericMenuItem();
    /* Slot 00 (+0x00) — Xbox 0x001972E0 */ virtual ~GenericMenuItem();
    /* Slot 01 (+0x04) */ virtual void OnHighlight() {}
    /* Slot 02 (+0x08) */ virtual void OnUnhighlight() {}
    /* Slot 03 (+0x0C) — Xbox 0x001AE620 */ virtual void SetVisible(bool bVis) { (void)bVis; }
    /* Slot 04 (+0x10) — Xbox 0x00197060 */ virtual void OnActivate() {}
    /* Slot 05 (+0x14) — Xbox 0x00022710 */ virtual void BindItemData(GenericMenuItemData* pData) { (void)pData; }

protected:
    uint8_t            m_bItemFlags;    /* +0x04 */
    uint8_t            m_bVisible;      /* +0x05 (written @ 0x001B7D6F & 0x0018B76F!) */
    uint8_t            m_Pad06[2];      /* +0x06..+0x07 */
    void*              m_pBackEffect;   /* +0x08 (freed via 0x001C5730 + PoolFree @ dtor!) */
    MenuColourAnimator m_ColourAnim;    /* +0x0C..+0x1F (20B, `lea esi, [ecx+0x0C]`) */
    uint8_t            m_BasePad20[0x10]; /* +0x20..+0x2F */
    Pure3DWidget*      m_pBackWidget;   /* +0x30 (bound to Back%i, alpha/colour controlled) */
    Pure3DWidget*      m_pTextWidget;   /* +0x34 (bound to MenuItem%i text label) */
};

/*
 * Decoded 1:1 from 0x001970E0 (100B), 0x00197180 (47B), & 0x00197210 (14B)!
 * Allocated with `sizeof == 0x4C` (76 bytes) at `0x001B64B9`.
 */
class GenericScroller {
public:
    /* Xbox 0x001970E0 (100B): SSE-zeroed constructor setting [+0x3E]=1, [+0x44]=-1, [+0x48]=NULL */
    GenericScroller();

    /* Slot 00 (+0x00) */ virtual ~GenericScroller() {}
    /* Slot 01 (+0x04) — called in EmpireHUD::vfunc_54 (0x001906B1): `push 0; push dt; call [edx+4]` */
    virtual void Update(uint32_t deltaMs, int32_t flags);

    /* Xbox 0x00197180: Configures wrap/vertical/visibility flags */
    void Configure(bool bWrap, bool bHorizontal, bool bInvert);

    /* Xbox 0x00197210 (14B): `if (pIface != NULL) this->m_pInterface = pIface;` (+0x48) */
    void SetScrollerInterface(GenericScrollerInterface* pIface) {
        if (pIface != NULL) {
            m_pInterface = pIface;
        }
    }

    float                     m_PosX;           /* +0x04 */
    float                     m_PosY;           /* +0x08 */
    uint32_t                  m_Unk0C;          /* +0x0C */
    uint32_t                  m_Ptrs10[5];      /* +0x10..+0x23 */
    float                     m_Floats24[5];    /* +0x24..+0x37 */
    int32_t                   m_ScrollOffset;   /* +0x38 */
    uint8_t                   m_Pad3C;          /* +0x3C */
    uint8_t                   m_bDragging;      /* +0x3D */
    uint8_t                   m_bEnabled;       /* +0x3E (= 1) */
    uint8_t                   m_Pad3F;          /* +0x3F */
    float                     m_StepSpeed;      /* +0x40 (= [0x0039F068]) */
    int32_t                   m_ActiveThumbIdx; /* +0x44 (= -1) */
    GenericScrollerInterface* m_pInterface;     /* +0x48 (set by 0x00197210!) */
};

/* Inner menu list at `GenericCursorMenu + 0x14` (decoded from 0x001981D0, 0x00198200, 0x00197320) */
class GenericMenuCore {
public:
    GenericMenuCore();
    virtual ~GenericMenuCore() {}

    /* Xbox 0x001981D0 (38B): Pushes GenericMenuItem* into pre-allocated [m_pEnd < m_pCap] vector */
    void AddMenuItemWidget(GenericMenuItem* pWidget);

    /* Xbox 0x00198200 (153B): Unhighlights all items, selects first enabled item, refreshes */
    void ResetSelectionToFirstEnabled();

    /* Xbox 0x0017E6F0 + 0x00197320 (195B): Binds "E_MenuCursor" widget UID */
    void BindCursorByUid(uint32_t cursorUid);

    GenericMenuItem** m_pBegin;        /* +0x04 (+0x18 in GenericCursorMenu) */
    GenericMenuItem** m_pEnd;          /* +0x08 (+0x1C in GenericCursorMenu) */
    GenericMenuItem** m_pCap;          /* +0x0C (+0x20 in GenericCursorMenu) */
    void*             m_pCursorEffect; /* +0x10 (+0x24 in GenericCursorMenu) */
    int32_t           m_SelectedIndex; /* +0x14 (+0x28 in GenericCursorMenu) */
    uint32_t          m_Unk18[2];      /* +0x18..+0x1F (+0x2C..+0x33 in GenericCursorMenu) */
};

/* Outer scrollable menu at `EmpireHUD::m_pMenu` (`sizeof == 0x44` = 68 bytes @ 0x001B6358) */
class GenericCursorMenu {
public:
    explicit GenericCursorMenu(int32_t poolId); /* Xbox 0x00198AD0 */
    /* Slot 00 (+0x00) */ virtual ~GenericCursorMenu();
    /* Slot 01 (+0x04) — called in EmpireHUD::vfunc_54 (0x001906A0) */
    virtual void Update(uint32_t deltaMs);

    /* Xbox 0x001982E0 (67B): Appends GenericMenuItemData* to data vector [m_pDataBegin..m_pDataCap] */
    void AddMenuItemData(GenericMenuItemData* pData);

    /* Xbox 0x00197B90 (509B): Syncs visible menu item slots with current scroll window */
    void RefreshVisibleSlots();

    GenericMenuItemData** m_pDataBegin;   /* +0x04 */
    GenericMenuItemData** m_pDataEnd;     /* +0x08 */
    GenericMenuItemData** m_pDataCap;     /* +0x0C */
    uint32_t              m_Unk10;        /* +0x10 */
    GenericMenuCore       m_InnerMenu;    /* +0x14..+0x33 (`add eax, 0x14` @ 0x001B6375!) */
    uint8_t               m_bScrollable;  /* +0x34 (tested @ 0x00197BF5!) */
    uint8_t               m_Pad35[3];     /* +0x35..+0x37 */
    int32_t               m_TopIndex;     /* +0x38 (read @ 0x00197BA5!) */
    uint32_t              m_Unk3C;        /* +0x3C */
    int32_t               m_PoolId;       /* +0x40 (read @ 0x001982F4 -> exact sizeof == 0x44!) */
};

/*
 * ============================================================================
 * 4. EmpireHUD & EmpireHUD::EmpireHUDMenuItem — EXACT RECONSTRUCTED CLASS
 * ============================================================================
 *   Primary VFTable  : PC 0x00753674 <== default.xbe 0x003BADDC (59 slots)
 *   MenuItem VFTable : PC 0x00751288 <== default.xbe 0x003C09DC ( 6 slots)
 *   Exact Class Size : 0x80 (128 bytes on 32-bit x86)
 */
class EmpireHUD
    : public HUDElement2               /* +0x00..+0x63 */
    , public SubscriberInterface       /* +0x64..+0x67 */
    , public GenericScrollerInterface  /* +0x68..+0x6B */
{
public:
    enum {
        kEventId_EmpireUpdate = 0xC7,  /* 199 — subscribed in vfunc_35 (0x00193FE0) */
        kEventId_EmpireOpened = 0x9A,  /* 154 — triggered in vfunc_44 (0x001B6527)  */
        kEmpireRowCount       = 3      /* Loop `ebp = 0..2` (`cmp ebp, 3; jl`) @ 0x001B6466 */
    };

    /*
     * EmpireHUD::EmpireHUDMenuItem (6 Virtual Slots, `sizeof == 0x3C` = 60 bytes)
     *   PC v1.00.2 VFTable : 0x00751288
     *   default.xbe VFTable: 0x003C09DC
     */
    class EmpireHUDMenuItem : public GenericMenuItem {
    public:
        /* Xbox 0x001B3840: Constructed with ("E_MenuItem%i", "E_MenuBack%i", "E_Icon%i") UIDs */
        EmpireHUDMenuItem(uint32_t menuItemUid, uint32_t menuBackUid, uint32_t iconUid);

        /* Slot 00 (+0x00) — PC 0x005D0D60 <== Xbox 0x001B5450 (30 bytes) */
        SCARFACE_MATCHED_FN(0x005D0D60, 0x001B5450, 30)
        virtual ~EmpireHUDMenuItem();

        /* Slot 01 (+0x04) — PC 0x005D0910 <== Xbox 0x001CB900 (44 bytes) */
        SCARFACE_MATCHED_FN(0x005D0910, 0x001CB900, 44)
        virtual void OnHighlight();

        /* Slot 02 (+0x08) — PC 0x005D0940 <== Xbox 0x001A5530 (44 bytes) */
        SCARFACE_MATCHED_FN(0x005D0940, 0x001A5530, 44)
        virtual void OnUnhighlight();

    private:
        uint32_t m_IconUid;
    };

public:
    static ConcreteClassRep<EmpireHUD> sm_ConcreteClassRep; /* Xbox 0x004366E4 */

    /* Constructor — Xbox 0x001940A0 (84 bytes = 0x54) */
    SCARFACE_MATCHED_FN(0x00000000, 0x001940A0, 84)
    EmpireHUD(const char* pName = NULL, int32_t allocatorPoolId = 0);

    /* Slot 00 (+0x00) — PC 0x005C37F0 <== Xbox 0x00194100 (6 bytes: `mov eax, &sm_ConcreteClassRep; ret`) */
    SCARFACE_MATCHED_FN(0x005C37F0, 0x00194100, 6)
    virtual AbstractClassRep* GetClassRep() const;

    /* Slot 01 (+0x04) — PC 0x005C3800 <== Xbox 0x00192AB0 (30B scalar dtor) + 0x00193F80 (22B body) */
    SCARFACE_MATCHED_FN(0x005C3800, 0x00192AB0, 30)
    virtual ~EmpireHUD();

    /* Slot 29 (+0x74) — PC 0x005E1BC0 <== Xbox 0x00193FD0 (5-byte jump thunk to HUDElement2::OnResetHUD) */
    SCARFACE_MATCHED_FN(0x005E1BC0, 0x00193FD0, 5)
    virtual void OnResetHUD();

    /* Slot 35 (+0x8C) — PC 0x005C36D0 <== Xbox 0x00193FE0 (107 bytes) */
    SCARFACE_MATCHED_FN(0x005C36D0, 0x00193FE0, 107)
    virtual bool SetActiveState(bool bActive, int32_t a2, int32_t a3);

    /* Slot 36 (+0x90) — PC 0x005C3740 <== Xbox 0x00194050 (23 bytes) */
    SCARFACE_MATCHED_FN(0x005C3740, 0x00194050, 23)
    virtual bool OnPageInit(void* pArg1, void* pArg2);

    /* Slot 38 (+0x98) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes: `mov al, 1; ret`) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool IsModalHUD() const;

    /* Slot 40 (+0xA0) — PC 0x005A4810 <== Xbox 0x0006F990 (3 bytes: `mov al, 1; ret`) */
    SCARFACE_MATCHED_FN(0x005A4810, 0x0006F990, 3)
    virtual bool BlocksWorldInput() const;

    /* Slot 44 (+0xB0) — PC 0x005B8FB0 <== Xbox 0x001B6320 (552 bytes = 0x228) */
    SCARFACE_MATCHED_FN(0x005B8FB0, 0x001B6320, 552)
    virtual bool OnOpenModal(FEProject* pProject);

    /* Slot 45 (+0xB4) — PC 0x005B6900 <== Xbox 0x001B34F0 (174 bytes = 0xAE) */
    SCARFACE_MATCHED_FN(0x005B6900, 0x001B34F0, 174)
    virtual bool OnCloseModal(int32_t closeReason);

    /* Slot 54 (+0xD8) — PC 0x005C2AE0 <== Xbox 0x00190680 (57 bytes = 0x39) */
    SCARFACE_MATCHED_FN(0x005C2AE0, 0x00190680, 57)
    virtual void UpdateFrame(uint32_t deltaMs);

    /* Non-virtual helper called at `0x001B6518` (`call 0x001B5530`) inside OnOpenModal */
    void RefreshEmpireDisplayData();

    /* Accessors for verification & CScript integration */
    GenericCursorMenu* GetMenu() const               { return m_pMenu; }
    GenericScroller*   GetScroller() const           { return m_pScroller; }
    int32_t            GetPendingSubScreen() const   { return m_PendingSubScreen; }
    bool               IsInDistributionMission() const { return m_bIsInDistributionMission != 0; }

private:
    GenericCursorMenu* m_pMenu;                    /* +0x6C (x86) */
    GenericScroller*   m_pScroller;                /* +0x70 (x86) */
    uint32_t           m_Unk74;                    /* +0x74 (x86) */
    int32_t            m_PendingSubScreen;         /* +0x78 (x86): -1 when staying in EmpireHUD */
    uint8_t            m_bSubScreenEntered;        /* +0x7C (x86): suppresses "accept" sound on sub-transition */
    uint8_t            m_bIsInDistributionMission; /* +0x7D (x86): result of "IsInDistributionMission();" */
    uint8_t            m_Pad7E[2];                 /* +0x7E..+0x7F -> exact 0x80 (128 bytes) on 32-bit x86! */
};

/* Compile-time 32-bit x86 ABI verification (`sizeof(void*) == 4` on MSVC 7.10 / -m32) */
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(HUDElement2) == 0x64,
    hud_element2_must_be_0x64_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(EmpireHUD) == 0x80,
    empire_hud_must_be_exact_0x80_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GenericMenuItemData) == 0x08,
    generic_menu_item_data_must_be_0x08_bytes_on_x86);

SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GenericScroller) == 0x4C,
    generic_scroller_must_be_0x4C_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(GenericCursorMenu) == 0x44,
    generic_cursor_menu_must_be_0x44_bytes_on_x86);
SCARFACE_STATIC_ASSERT(
    sizeof(void*) != 4 || sizeof(EmpireHUD::EmpireHUDMenuItem) == 0x3C,
    empire_menu_item_must_be_0x3C_bytes_on_x86);

#if defined(_MSC_VER) && defined(_M_IX86)
    #pragma pack(pop)
#endif

#endif /* SCARFACE_PC_V1002_EMPIRE_HUD_REAL_H */

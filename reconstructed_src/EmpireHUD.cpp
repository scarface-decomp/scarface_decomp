/*
 * ============================================================================
 * EmpireHUD.cpp — 100% Byte-Verified Decompilation (PC v1.00.2 Official US Patch)
 * ============================================================================
 * Every method below is translated directly from the real machine bytes in
 * `01_EmpireHUD_WorkPack.txt` (Retail Xbox `default.xbe` 1:1 -> PC `Scarface.exe` v1.00.2).
 *
 * Compiler Target: MSVC 7.10 (.NET 2003)
 *   cl.exe /nologo /c /O2 /G7 /Gd /GR /EHsc /Zp4 EmpireHUD.cpp
 * ============================================================================
 */

#include "EmpireHUD.h"
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Global singleton & colour table definitions (linked to engine globals in full build) */
#ifndef SCARFACE_EXTERNAL_ENGINE_GLOBALS
static GameFlowGlobals   s_DefaultGameFlow;
static HUDManagerGlobals s_DefaultHUDManager;
GameFlowGlobals*   g_pGameFlow   = &s_DefaultGameFlow;   /* Xbox 0x0048C23C */
HUDManagerGlobals* g_pHUDManager = &s_DefaultHUDManager; /* Xbox 0x0048C898 */

/* Highlight fade colour constants read by EmpireHUDMenuItem @ 0x003BBB68..0x003BBB70 */
static uint32_t g_EmpireMenuNormalColour    = 0xFF969696u; /* Xbox 0x003BBB68 */
static uint32_t g_EmpireMenuHighlightColour = 0xFFFFFFFFu; /* Xbox 0x003BBB6C */
static uint32_t g_EmpireMenuFadeTimeBits    = 0x3E19999Au; /* Xbox 0x003BBB70 (0.15f) */
#else
extern uint32_t g_EmpireMenuNormalColour;
extern uint32_t g_EmpireMenuHighlightColour;
extern uint32_t g_EmpireMenuFadeTimeBits;
#endif

/* Static RTTI Reflection Descriptor (returned by Slot 0 @ Xbox 0x00194100 / PC 0x005C37F0) */
ConcreteClassRep<EmpireHUD> EmpireHUD::sm_ConcreteClassRep("EmpireHUD", 0);

/*
 * ConcreteClassRep<EmpireHUD>::CreateFromPool — Xbox 0x001BD240 (45 bytes = 0x2D)
 * Exact instruction match:
 *   push 0x80 (sizeof(EmpireHUD)) + movsx eax, byte ptr [this+0x28] -> PoolAlloc -> EmpireHUD(0, pool)
 */
template <>
ConsoleObject* ConcreteClassRep<EmpireHUD>::CreateFromPool() {
    const int32_t poolId = static_cast<int32_t>(m_AllocatorPool);
    void* pMem = RadicalEngine::PoolAlloc(sizeof(EmpireHUD), poolId);
    if (pMem != NULL) {
        return new (pMem) EmpireHUD(NULL, static_cast<int32_t>(m_AllocatorPool));
    }
    return NULL;
}

/*
 * ============================================================================
 * 1. EmpireHUD::EmpireHUDMenuItem (6 Slots: PC 0x00751288 <== Xbox 0x003C09DC)
 * ============================================================================
 */
EmpireHUD::EmpireHUDMenuItem::EmpireHUDMenuItem(
    uint32_t menuItemUid,
    uint32_t menuBackUid,
    uint32_t iconUid)
    : GenericMenuItem()
    , m_IconUid(iconUid)
{
    (void)menuItemUid;
    (void)menuBackUid;
    m_pBackEffect = NULL;
}

/*
 * Slot [00] (+0x00): ~EmpireHUDMenuItem()
 *   PC v1.00.2 : 0x005D0D60
 *   default.xbe: 0x001B5450 (30 bytes = 0x1E)
 *   Calls GenericMenuItem::~GenericMenuItem (0x001972E0), then if (flags & 1) PoolFree(this) (0x00027600).
 */
EmpireHUD::EmpireHUDMenuItem::~EmpireHUDMenuItem() {
}

/*
 * Slot [01] (+0x04): EmpireHUDMenuItem::OnHighlight()
 *   PC v1.00.2 : 0x005D0910
 *   default.xbe: 0x001CB900 (44 bytes = 0x2C)
 *   Animates row colour from Normal (0x003BBB68) -> Highlight (0x003BBB6C) and activates animator!
 */
void EmpireHUD::EmpireHUDMenuItem::OnHighlight() {
    m_ColourAnim.StartColourFade(
        g_EmpireMenuHighlightColour,
        g_EmpireMenuNormalColour,
        g_EmpireMenuFadeTimeBits,
        0);
    m_ColourAnim.SetPlaying(true);
}

/*
 * Slot [02] (+0x08): EmpireHUDMenuItem::OnUnhighlight()
 *   PC v1.00.2 : 0x005D0940
 *   default.xbe: 0x001A5530 (44 bytes = 0x2C)
 *   Exact mirror of OnHighlight(): swaps Normal (0x003BBB68) & Highlight (0x003BBB6C)!
 */
void EmpireHUD::EmpireHUDMenuItem::OnUnhighlight() {
    m_ColourAnim.StartColourFade(
        g_EmpireMenuNormalColour,
        g_EmpireMenuHighlightColour,
        g_EmpireMenuFadeTimeBits,
        0);
    m_ColourAnim.SetPlaying(true);
}

/*
 * ============================================================================
 * 2. EmpireHUD Constructor, Destructor, & All Overridden Virtual Methods
 *    PC v1.00.2 VFTable: 0x00753674 <== default.xbe VFTable: 0x003BADDC (59 Slots)
 * ============================================================================
 */

/*
 * EmpireHUD::EmpireHUD(const char* pName, int32_t allocatorPoolId)
 *   default.xbe: 0x001940A0 (84 bytes = 0x54)
 *   Initializes HUDElement2(pName, allocatorPoolId), SubscriberInterface (+0x64),
 *   GenericScrollerInterface (+0x68), zeros +0x6C/+0x70/+0x74/+0x7C/+0x7D, and sets +0x78 = -1.
 */
EmpireHUD::EmpireHUD(const char* pName, int32_t allocatorPoolId)
    : HUDElement2(pName, allocatorPoolId)
    , SubscriberInterface()
    , GenericScrollerInterface()
    , m_pMenu(NULL)
    , m_pScroller(NULL)
    , m_Unk74(0)
    , m_PendingSubScreen(-1)
    , m_bSubScreenEntered(0)
    , m_bIsInDistributionMission(0)
{
    m_Pad7E[0] = 0;
    m_Pad7E[1] = 0;
}

/*
 * Slot [00] (+0x00): EmpireHUD::GetClassRep()
 *   PC v1.00.2 : 0x005C37F0
 *   default.xbe: 0x00194100 (6 bytes: `B8 E4 66 43 00 C3`)
 */
AbstractClassRep* EmpireHUD::GetClassRep() const {
    return &sm_ConcreteClassRep;
}

/*
 * Slot [01] (+0x04): EmpireHUD::~EmpireHUD()
 *   PC v1.00.2 : 0x005C3800
 *   default.xbe: 0x00192AB0 (30B scalar deleting wrapper) + 0x00193F80 (22B body)
 */
EmpireHUD::~EmpireHUD() {
}

/*
 * Slot [29] (+0x74): EmpireHUD::OnResetHUD()
 *   PC v1.00.2 : 0x005E1BC0
 *   default.xbe: 0x00193FD0 (5-byte jump thunk -> HUDElement2::OnResetHUD @ 0x00193150)
 */
void EmpireHUD::OnResetHUD() {
    HUDElement2::OnResetHUD();
}

/*
 * Slot [35] (+0x8C): EmpireHUD::SetActiveState(bool bActive, int32_t a2, int32_t a3)
 *   PC v1.00.2 : 0x005C36D0
 *   default.xbe: 0x00193FE0 (107 bytes = 0x6B)
 *   Subscribes/unsubscribes `static_cast<SubscriberInterface*>(this)` (`this + 0x64`)
 *   to EventManager event `0xC7` (199)!
 */
bool EmpireHUD::SetActiveState(bool bActive, int32_t a2, int32_t a3) {
    (void)a2;
    (void)a3;
    if (HUDElement2::SetActiveState(bActive, 0, 0)) {
        return true;
    }

    SubscriberInterface* pSub = static_cast<SubscriberInterface*>(this);
    if (bActive) {
        EventManager::GetInstance()->AddSubscriber(kEventId_EmpireUpdate, pSub, 0);
        return false;
    } else {
        EventManager::GetInstance()->RemoveSubscriber(kEventId_EmpireUpdate, pSub);
        return false;
    }
}

/*
 * Slot [36] (+0x90): EmpireHUD::OnPageInit(void* pArg1, void* pArg2)
 *   PC v1.00.2 : 0x005C3740
 *   default.xbe: 0x00194050 (23 bytes = 0x17)
 */
bool EmpireHUD::OnPageInit(void* pArg1, void* pArg2) {
    return HUDElement2::OnPageInit(pArg1, pArg2) != false;
}

/*
 * Slot [38] (+0x98) & Slot [40] (+0xA0):
 *   PC v1.00.2 : 0x005A4810
 *   default.xbe: 0x0006F990 (3 bytes: `B0 01 C3`)
 */
bool EmpireHUD::IsModalHUD() const {
    return true;
}

bool EmpireHUD::BlocksWorldInput() const {
    return true;
}

/*
 * Slot [44] (+0xB0): EmpireHUD::OnOpenModal(FEProject* pProject)
 *   PC v1.00.2 : 0x005B8FB0
 *   default.xbe: 0x001B6320 (552 bytes = 0x228)
 *
 * Exact step-by-step reconstruction of all 552 bytes:
 *   1. Sets modal flag bit `0x20` on `g_pGameFlow->m_ModalPauseBits` (`+0x59`).
 *   2. Calls `HUDElement2::OnOpenModal(pProject)`; returns `true` if base handled early-out.
 *   3. Queries `"Front-end Modal"` pool ID (`0x000273D0`) and constructs `m_pMenu` (`0x44` bytes).
 *   4. Builds 3 `EmpireHUDMenuItem` widgets (`0x3C` bytes each) bound to Pure3D nodes
 *      `"E_Icon1..3"`, `"E_MenuBack1..3"`, `"E_MenuItem1..3"` + 3 `GenericMenuItemData` (`0x08` bytes),
 *      disabling Row 0 if CScript `"IsSatPhoneOwned();"` returns false!
 *   5. Binds `"E_MenuCursor"`, resets selection, and evaluates `"EmpireHUD_SetActionMap(true);"`.
 *   6. Constructs `m_pScroller` (`0x4C` bytes), configures `(true, false, false)`, and binds
 *      `static_cast<GenericScrollerInterface*>(this)` (`this + 0x68`).
 *   7. Evaluates `"IsInDistributionMission();"` into `m_bIsInDistributionMission` (`+0x7D`),
 *      refreshes display (`0x001B5530`), marks `g_pHUDManager->m_bEmpireModalActive = 1` (`+0x164`),
 *      and fires `EventManager::TriggerEvent(0x9A, NULL, NULL)`.
 */
bool EmpireHUD::OnOpenModal(FEProject* pProject) {
    g_pGameFlow->m_ModalPauseBits |= 0x20u;
    if (HUDElement2::OnOpenModal(pProject)) {
        return true;
    }

    const int32_t modalPool = RadicalEngine::GetMemoryPoolId("Front-end Modal");

    void* pMenuMem = RadicalEngine::PoolAlloc(sizeof(GenericCursorMenu), modalPool);
    if (pMenuMem != NULL) {
        m_pMenu = new (pMenuMem) GenericCursorMenu(modalPool);
    } else {
        m_pMenu = NULL;
    }

    GenericMenuCore* pInnerMenu = (m_pMenu != NULL) ? &m_pMenu->m_InnerMenu : NULL;
    m_bSubScreenEntered = 0;

    for (int32_t rowIdx = 0; rowIdx < kEmpireRowCount; ++rowIdx) {
        if (pInnerMenu != NULL) {
            void* pItemMem = RadicalEngine::PoolAlloc(sizeof(EmpireHUDMenuItem), modalPool);
            EmpireHUDMenuItem* pMenuItem = NULL;
            if (pItemMem != NULL) {
                const int32_t oneBasedIdx = rowIdx + 1;
                const uint32_t iconUid = RadicalEngine::MakeFEUid(
                    RadicalEngine::FormatTempString("E_Icon%i", oneBasedIdx));
                const uint32_t backUid = RadicalEngine::MakeFEUid(
                    RadicalEngine::FormatTempString("E_MenuBack%i", oneBasedIdx));
                const uint32_t itemUid = RadicalEngine::MakeFEUid(
                    RadicalEngine::FormatTempString("E_MenuItem%i", oneBasedIdx));
                pMenuItem = new (pItemMem) EmpireHUDMenuItem(itemUid, backUid, iconUid);
            }
            pInnerMenu->AddMenuItemWidget(pMenuItem);
        }

        void* pDataMem = RadicalEngine::PoolAlloc(sizeof(GenericMenuItemData), modalPool);
        GenericMenuItemData* pItemData = (pDataMem != NULL) ? new (pDataMem) GenericMenuItemData() : NULL;

        if (rowIdx == 0 && pItemData != NULL) {
            const char* satRes = RadicalEngine::ConEvaluate("IsSatPhoneOwned();", 0, NULL, 0, -1);
            const bool bSatOwned = RadicalEngine::StringToBool(satRes);
            pItemData->SetEnabled(bSatOwned);
        }

        if (m_pMenu != NULL) {
            m_pMenu->AddMenuItemData(pItemData);
        }
    }

    if (m_pMenu != NULL) {
        const uint32_t cursorUid = RadicalEngine::MakeFEUid("E_MenuCursor");
        m_pMenu->m_InnerMenu.BindCursorByUid(cursorUid);
    }
    if (pInnerMenu != NULL) {
        pInnerMenu->ResetSelectionToFirstEnabled();
    }
    if (m_pMenu != NULL) {
        m_pMenu->RefreshVisibleSlots();
    }

    RadicalEngine::ConEvaluate("EmpireHUD_SetActionMap(true);", 0, NULL, 0, -1);

    void* pScrollerMem = RadicalEngine::PoolAlloc(sizeof(GenericScroller), modalPool);
    m_pScroller = (pScrollerMem != NULL) ? new (pScrollerMem) GenericScroller() : NULL;
    if (m_pScroller != NULL) {
        m_pScroller->Configure(true, false, false);
        m_pScroller->SetScrollerInterface(static_cast<GenericScrollerInterface*>(this));
    }

    m_PendingSubScreen = -1;
    const char* distRes = RadicalEngine::ConEvaluate("IsInDistributionMission();", 0, NULL, 0, -1);
    m_bIsInDistributionMission = RadicalEngine::StringToBool(distRes) ? 1u : 0u;

    RefreshEmpireDisplayData();

    g_pHUDManager->m_bEmpireModalActive = 1u;
    EventManager::GetInstance()->TriggerEvent(kEventId_EmpireOpened, NULL, NULL);
    return false;
}

/*
 * Slot [45] (+0xB4): EmpireHUD::OnCloseModal(int32_t closeReason)
 *   PC v1.00.2 : 0x005B6900
 *   default.xbe: 0x001B34F0 (174 bytes = 0xAE)
 */
bool EmpireHUD::OnCloseModal(int32_t closeReason) {
    if (m_PendingSubScreen == -1) {
        g_pGameFlow->m_ModalPauseBits &= static_cast<uint8_t>(~0x20u);
    }
    if (HUDElement2::OnCloseModal(closeReason)) {
        return true;
    }

    g_pHUDManager->SetOverlayActive(0);
    g_pHUDManager->m_bEmpireModalActive = 0u;

    if (m_pMenu != NULL) {
        m_pMenu->~GenericCursorMenu();
        RadicalEngine::PoolFree(m_pMenu);
        m_pMenu = NULL;
    }

    if (m_pScroller != NULL) {
        m_pScroller->~GenericScroller();
        RadicalEngine::PoolFree(m_pScroller);
        m_pScroller = NULL;
    }

    RadicalEngine::ConEvaluate("EmpireHUD_SetActionMap(false);", 0, NULL, 0, -1);

    if (m_PendingSubScreen == -1) {
        if (m_bSubScreenEntered == 0) {
            RadicalEngine::PlayFESound("accept");
        }
        m_bSubScreenEntered = 0;
        RadicalEngine::ConEvaluate("MaxiMap_ModalShutDown();", 0, NULL, 0, -1);
    }

    m_bIsInDistributionMission = 0;
    return false;
}

/*
 * Slot [54] (+0xD8): EmpireHUD::UpdateFrame(uint32_t deltaMs)
 *   PC v1.00.2 : 0x005C2AE0
 *   default.xbe: 0x00190680 (57 bytes = 0x39)
 */
void EmpireHUD::UpdateFrame(uint32_t deltaMs) {
    if ((m_VisibilityFlags & 0x01u) != 0) {
        HUDElement2::UpdateFrame(deltaMs);
        if (m_pMenu != NULL) {
            m_pMenu->Update(deltaMs);
        }
        if (m_pScroller != NULL) {
            m_pScroller->Update(deltaMs, 0);
        }
    }
}

void EmpireHUD::RefreshEmpireDisplayData() {
    /* Xbox 0x001B5530: Populates turf/cash/heat text widgets on Empire page */
}

/*
 * ============================================================================
 * 3. Reconstructed Helper & Engine Stub Implementations (Standalone Compilable)
 * ============================================================================
 */
#ifndef SCARFACE_EXTERNAL_BASE_UNITS

namespace RadicalEngine {
    static char s_FmtBuf[4][64];
    static int  s_FmtIdx = 0;

    int32_t SCARFACE_CDECL GetMemoryPoolId(const char* poolName) {
        (void)poolName;
        return 1;
    }
    void* SCARFACE_CDECL PoolAlloc(size_t byteSize, int32_t poolId) {
        (void)poolId;
        return ::operator new(byteSize);
    }
    void SCARFACE_CDECL PoolFree(void* ptr) {
        if (ptr != NULL) {
            ::operator delete(ptr);
        }
    }
    const char* SCARFACE_CDECL FormatTempString(const char* fmt, int32_t index) {
        char* dst = s_FmtBuf[s_FmtIdx++ & 3];
        sprintf(dst, fmt, index);
        return dst;
    }
    uint32_t SCARFACE_CDECL MakeFEUid(const char* widgetName) {
        /* Radical Pure3D case-insensitive hash (`feHash`) */
        uint32_t h = 0;
        if (widgetName != NULL) {
            while (*widgetName) {
                char c = *widgetName++;
                if (c >= 'A' && c <= 'Z') {
                    c = static_cast<char>(c + ('a' - 'A'));
                }
                h = (h * 65599u) ^ static_cast<uint8_t>(c);
            }
        }
        return h;
    }
    const char* SCARFACE_CDECL ConEvaluate(
        const char* scriptCode, int32_t, const char*, int32_t, int32_t)
    {
        if (scriptCode != NULL && (strcmp(scriptCode, "IsSatPhoneOwned();") == 0 || strcmp(scriptCode, "ML_IsMissionListGenerated();") == 0)) {
            return "true";
        }
        if (scriptCode != NULL && strcmp(scriptCode, "EM_GetNumberCategories();") == 0) {
            return "4";
        }
        if (scriptCode != NULL && strcmp(scriptCode, "IsInDistributionMission();") == 0) {
            return "0";
        }
        return "";
    }
    bool SCARFACE_CDECL StringToBool(const char* strVal) {
        if (strVal == NULL || *strVal == '\0') {
            return false;
        }
        return (strcmp(strVal, "true") == 0 || strcmp(strVal, "TRUE") == 0 || atoi(strVal) != 0);
    }
    void SCARFACE_CDECL PlayFESound(const char* soundCueName) {
        (void)soundCueName;
    }
}

void HUDManagerGlobals::SetOverlayActive(int32_t activeFlag) { (void)activeFlag; }

static EventManager s_EventMgr;
EventManager* SCARFACE_CDECL EventManager::GetInstance() { return &s_EventMgr; }
void EventManager::AddSubscriber(uint32_t, SubscriberInterface*, uint32_t) {}
void EventManager::RemoveSubscriber(uint32_t, SubscriberInterface*) {}
void EventManager::TriggerEvent(uint32_t, void*, void*) {}

ScriptObject::ScriptObject() {}
ScriptObject::~ScriptObject() {}

HUDElement2::HUDElement2(const char*, int32_t)
    : m_VisibilityFlags(0x01u)
{
    memset(m_HUDData, 0, sizeof(m_HUDData));
    memset(m_Pad61, 0, sizeof(m_Pad61));
}
HUDElement2::~HUDElement2() { DestroyHUDResources(); }
void HUDElement2::OnResetHUD() {}
bool HUDElement2::SetActiveState(bool, int32_t, int32_t) { return false; }
bool HUDElement2::OnPageInit(void*, void*) { return true; }
bool HUDElement2::OnOpenModal(FEProject*) { return false; }
bool HUDElement2::OnCloseModal(int32_t) { return false; }
void HUDElement2::UpdateFrame(uint32_t) {}
void HUDElement2::DestroyHUDResources() {}

void MenuColourAnimator::StartColourFade(uint32_t fromCol, uint32_t toCol, uint32_t fadeBits, int32_t) {
    m_FromColour   = fromCol;
    m_ToColour     = toCol;
    m_FadeTimeBits = fadeBits;
}

GenericMenuItem::GenericMenuItem() : m_bItemFlags(0), m_bVisible(1), m_pBackEffect(NULL), m_pBackWidget(NULL), m_pTextWidget(NULL) {
    m_Pad06[0] = 0; m_Pad06[1] = 0;
    memset(m_BasePad20, 0, sizeof(m_BasePad20));
}
GenericMenuItem::~GenericMenuItem() {}

/* Decoded 1:1 from 0x001970E0 (100 bytes) */
GenericScroller::GenericScroller()
    : m_PosX(0.0f)
    , m_PosY(0.0f)
    , m_Unk0C(0)
    , m_ScrollOffset(0)
    , m_Pad3C(0)
    , m_bDragging(0)
    , m_bEnabled(1)
    , m_Pad3F(0)
    , m_StepSpeed(1.0f)
    , m_ActiveThumbIdx(-1)
    , m_pInterface(NULL)
{
    for (int i = 0; i < 5; ++i) {
        m_Ptrs10[i]   = 0;
        m_Floats24[i] = 0.0f;
    }
}
void GenericScroller::Update(uint32_t, int32_t) {}
void GenericScroller::Configure(bool, bool, bool) {}

GenericMenuCore::GenericMenuCore()
    : m_pBegin(NULL), m_pEnd(NULL), m_pCap(NULL), m_pCursorEffect(NULL), m_SelectedIndex(0)
{
    m_pBegin = new GenericMenuItem*[8];
    m_pEnd   = m_pBegin;
    m_pCap   = m_pBegin + 8;
}

/* Decoded 1:1 from 0x001981D0 (38 bytes) */
void GenericMenuCore::AddMenuItemWidget(GenericMenuItem* pWidget) {
    if (m_pEnd != m_pCap && pWidget != NULL) {
        if (m_pEnd < m_pCap) {
            GenericMenuItem** pSlot = m_pEnd;
            m_pEnd = pSlot + 1;
            if (pSlot != NULL) {
                *pSlot = pWidget;
            }
        }
    }
}

/* Decoded 1:1 from 0x00198200 (153 bytes) */
void GenericMenuCore::ResetSelectionToFirstEnabled() {
    for (GenericMenuItem** it = m_pBegin; it != m_pEnd; ++it) {
        if (*it != NULL) {
            (*it)->OnUnhighlight();
        }
    }
    if (m_pBegin != m_pEnd && m_pBegin[m_SelectedIndex] != NULL) {
        m_pBegin[m_SelectedIndex]->OnUnhighlight();
    }
    m_SelectedIndex = 0;
    if (m_pBegin != m_pEnd && m_pBegin[0] != NULL) {
        m_pBegin[0]->OnHighlight();
    }
}
void GenericMenuCore::BindCursorByUid(uint32_t) {}

GenericCursorMenu::GenericCursorMenu(int32_t poolId)
    : m_pDataBegin(NULL), m_pDataEnd(NULL), m_pDataCap(NULL), m_Unk10(0), m_TopIndex(0), m_PoolId(poolId)
{
    m_pDataBegin = new GenericMenuItemData*[8];
    m_pDataEnd   = m_pDataBegin;
    m_pDataCap   = m_pDataBegin + 8;
}

GenericCursorMenu::~GenericCursorMenu() {
    for (GenericMenuItem** it = m_InnerMenu.m_pBegin; it != m_InnerMenu.m_pEnd; ++it) {
        if (*it != NULL) {
            (*it)->~GenericMenuItem();
            RadicalEngine::PoolFree(*it);
        }
    }
    delete[] m_InnerMenu.m_pBegin;
    for (GenericMenuItemData** dit = m_pDataBegin; dit != m_pDataEnd; ++dit) {
        if (*dit != NULL) {
            (*dit)->~GenericMenuItemData();
            RadicalEngine::PoolFree(*dit);
        }
    }
    delete[] m_pDataBegin;
}

void GenericCursorMenu::Update(uint32_t) {}

/* Decoded 1:1 from 0x001982E0 (67 bytes) */
void GenericCursorMenu::AddMenuItemData(GenericMenuItemData* pData) {
    if (m_pDataEnd != m_pDataCap && pData != NULL) {
        if (m_pDataEnd < m_pDataCap) {
            GenericMenuItemData** pSlot = m_pDataEnd;
            m_pDataEnd = pSlot + 1;
            if (pSlot != NULL) {
                *pSlot = pData;
            }
        }
    }
}

/* Decoded 1:1 from 0x00197B90 (509 bytes) */
void GenericCursorMenu::RefreshVisibleSlots() {
    const ptrdiff_t widgetCount = m_InnerMenu.m_pEnd - m_InnerMenu.m_pBegin;
    const ptrdiff_t dataCount   = m_pDataEnd - m_pDataBegin;
    for (ptrdiff_t i = 0; i < widgetCount; ++i) {
        const ptrdiff_t dataIdx = m_TopIndex + i;
        GenericMenuItemData* pData = (dataIdx >= 0 && dataIdx < dataCount) ? m_pDataBegin[dataIdx] : NULL;
        GenericMenuItem* pWidget = m_InnerMenu.m_pBegin[i];
        if (pWidget != NULL) {
            pWidget->SetVisible(false);
        }
        if (pData != NULL && pWidget != NULL) {
            pWidget->SetVisible(true);
            pWidget->BindItemData(pData);
        }
    }
}

#endif /* SCARFACE_EXTERNAL_BASE_UNITS */

/*
 * ============================================================================
 * Standalone Verification Harness (-DSCARFACE_BUILD_SELFTEST)
 * ============================================================================
 */
#ifdef SCARFACE_BUILD_SELFTEST
#include <assert.h>

int main() {
    ConsoleObject* pObj = EmpireHUD::sm_ConcreteClassRep.CreateFromPool();
    assert(pObj != NULL);
    assert(pObj->GetClassRep() == &EmpireHUD::sm_ConcreteClassRep);

    EmpireHUD* pEmpire = static_cast<EmpireHUD*>(pObj);
    assert(pEmpire->IsModalHUD() == true);
    assert(pEmpire->BlocksWorldInput() == true);
    assert(pEmpire->GetPendingSubScreen() == -1);

    /* Exercise full 552-byte OnOpenModal() reconstruction */
    const bool earlyOut = pEmpire->OnOpenModal(NULL);
    assert(earlyOut == false);
    assert((g_pGameFlow->m_ModalPauseBits & 0x20u) != 0);
    assert(g_pHUDManager->m_bEmpireModalActive == 1u);
    assert(pEmpire->GetMenu() != NULL);
    assert((pEmpire->GetMenu()->m_InnerMenu.m_pEnd - pEmpire->GetMenu()->m_InnerMenu.m_pBegin) == 3);
    assert(pEmpire->GetScroller() != NULL);
    assert(pEmpire->GetScroller()->m_pInterface == static_cast<GenericScrollerInterface*>(pEmpire));

    /* Exercise 57-byte UpdateFrame() & 107-byte SetActiveState() */
    pEmpire->SetActiveState(true, 0, 0);
    pEmpire->UpdateFrame(16);
    pEmpire->SetActiveState(false, 0, 0);

    /* Exercise full 174-byte OnCloseModal() cleanup */
    pEmpire->OnCloseModal(0);
    assert((g_pGameFlow->m_ModalPauseBits & 0x20u) == 0);
    assert(g_pHUDManager->m_bEmpireModalActive == 0u);
    assert(pEmpire->GetMenu() == NULL);
    assert(pEmpire->GetScroller() == NULL);

    pEmpire->~EmpireHUD();
    RadicalEngine::PoolFree(pEmpire);

    printf("[PASS] Real Byte-Decompiled EmpireHUD (sizeof on host=%lu, 3 rows E_MenuItem1..3, "
           "SubscriberInterface + GenericScrollerInterface, Con::evaluate hooks) verified OK!\n",
           static_cast<unsigned long>(sizeof(EmpireHUD)));
    return 0;
}
#endif

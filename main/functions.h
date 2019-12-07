#ifndef __FUNCTIONSH__
#define __FUNCTIONSH__

#include <iostream>
#include <windows.h>
#include <stdint.h>

#include "const.h"
#include "structures.h"
#include "uitibia.h"

typedef void __cdecl _Error(const char* lpTitle, const char* lpText);
typedef void __cdecl _PushLetter(int Letter);
typedef void __cdecl _SetExperience(int Experience, int Level, int U3);
typedef int __cdecl _TextMetric(int font, char* text, int length);
typedef uint32_t __cdecl _GetItemProperty(uint32_t itemid, uint32_t flag);
typedef Creature_t* __cdecl _GetCreatureEntry(uint32_t id);
typedef void* __cdecl _GetPainter();
typedef void __cdecl _SetUseObject(uint32_t objectId, uint32_t u1, uint32_t u2, uint32_t u3, uint32_t x, uint32_t y, uint32_t z, uint32_t use);
typedef void __cdecl _Idle();

typedef void __stdcall _EnterCriticalSection(int section);
typedef void __stdcall _LeaveCriticalSection(int section);

/* Dialogs */
typedef Tibia::GUIDialog* __cdecl _CreateTextDialog(const char* caption, const char* text);
typedef Tibia::GUIDialog* __cdecl _CreateAcceptDialog(const char* caption, const char* text, uint32_t callback, uint32_t u1, uint32_t u2);
typedef Tibia::GUIDialog* __cdecl _CreateMoveObjectDialog();
typedef Tibia::GUIDialog* __cdecl _CreateOptionsDialog();
typedef Tibia::GUIDialog* __cdecl _CreateHelpDialog(void* u1);
typedef void* __cdecl _CreateCharacterListDialog(uint32_t u1);

/* Network */
typedef uint32_t __cdecl _NetworkGetU32();
typedef uint16_t __cdecl _NetworkGetU16();
typedef uint8_t __cdecl _NetworkGetU8();
typedef char* __cdecl _NetworkGetString();

/* Basic functions */
namespace Tibia {
	extern Tibia::GUI* GetGUIPointer();
	extern uint32_t GetPlayerInfo(playerInfo_t info);
	extern bool HasDialog();
	extern void SetCurrentDialog(GUIDialog* dialog);
	extern void FatalError(const char* error);
	extern void Exit();
	extern bool CanLogout();
	extern bool IsOnline();

	extern void AddContextMenu(uint32_t _THIS, uint32_t eventId, const char* text, const char* shortcut);
	extern void AddContextMenuEx(uint32_t _THIS, uint32_t eventId, const char* text, const char* shortcut);
	
	/* Critical sections */
	extern _EnterCriticalSection *EnterCriticalSection;
	extern _LeaveCriticalSection *LeaveCriticalSection;

	/* Tibia functions */
	extern _Error *Error;
	extern _TextMetric *TextMetric;

	extern _GetItemProperty * GetItemProperty;

	extern _SetExperience *SetExperience;
	extern _PushLetter *PushLetter;
	extern _GetCreatureEntry * GetCreatureEntry;

	extern _CreateTextDialog *CreateTextDialog;
	extern _CreateAcceptDialog *CreateAcceptDialog;
	extern _CreateCharacterListDialog *CreateCharacterListDialog;
	extern _CreateMoveObjectDialog* CreateMoveObjectDialog;
	extern _CreateOptionsDialog *CreateOptionsDialog;
	extern _CreateHelpDialog *CreateHelpDialog;
	extern _GetPainter *GetPainter;
	extern _SetUseObject *SetUseObject;
	extern _Idle *Idle;

	extern _NetworkGetU32 *NetworkGetU32;
	extern _NetworkGetU16 *NetworkGetU16;
	extern _NetworkGetU8 *NetworkGetU8;
	extern _NetworkGetString *NetworkGetString;
}

#endif

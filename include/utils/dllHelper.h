#pragma once
#include <stdio.h> 
#include <string>
#if (defined WIN32 || defined _WIN32 || defined WINCE || defined __CYGWIN__)
#include "windows.h"
#else
#include <dlfcn.h>
#include <errno.h>
#endif

// ��̬�⸨����
class CDllHelper
{
private:
	char					m_szFileName[_MAX_DIR];                  // �ļ���
#if defined WINDOWS || _WIN32
    HMODULE					m_hLibrary;                    // ģ����
#else
	void* m_hLibrary;
#endif

protected:
	 // ���ض�̬��
	void dll_Load()
	{
		if (m_szFileName == nullptr)
		{
			return;
		}

#if defined WINDOWS || _WIN32
		m_hLibrary =  LoadLibraryExA(m_szFileName, nullptr, LOAD_WITH_ALTERED_SEARCH_PATH);
#else
		return dlopen(libPath, RTLD_NOW);
#endif		
	}

	void dll_FreeLib()
	{
		if (m_hLibrary == NULL)
		{
			return;
		}

#if defined WINDOWS || _WIN32
		FreeLibrary(m_hLibrary);
#else
		dlclose(lib);
#endif
	}

public:
	CDllHelper(const char *lpszFileName) :
		m_hLibrary(NULL)
	{
		sprintf_s(m_szFileName, _MAX_DIR, lpszFileName);
		dll_Load();
	}

	~CDllHelper()
	{
		if (m_hLibrary != NULL)
		{
			dll_FreeLib();
			m_hLibrary = NULL;
		}
	}

public:
    // ��ȡProc
	template<typename Proc>
	Proc GetProcedure(LPCSTR lpszProc)
	{
		if (m_hLibrary == NULL)
		{
			return nullptr;
		}		

		Proc pfnProc = NULL;

#if defined WINDOWS || _WIN32
		
		pfnProc = (Proc)GetProcAddress(m_hLibrary, lpszProc);
		return pfnProc;
#else
		pfnProc = (Proc)dlsym(m_hLibrary, lpszProc)
		return pfnProc;
#endif
	}

	const char* dll_GetLastError()
	{
#if defined WINDOWS || _WIN32
		LPVOID lpMsgBuf;
		DWORD dw = GetLastError();
		FormatMessageA(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
			NULL,
			dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR)&lpMsgBuf,
			0, NULL);
		return (const char*)lpMsgBuf;
#else
		extern int errno;
		errno = 0;
		return dlerror();
#endif
	}
};
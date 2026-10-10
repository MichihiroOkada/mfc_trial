
// dialog_test.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CdialogtestApp:
// このクラスの実装については、dialog_test.cpp を参照してください
//

class CdialogtestApp : public CWinApp
{
public:
	CdialogtestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()

};

extern CdialogtestApp theApp;

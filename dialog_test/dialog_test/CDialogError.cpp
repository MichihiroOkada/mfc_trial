// CDialogError.cpp : 実装ファイル
//

#include "pch.h"
#include "dialog_test.h"
#include "afxdialogex.h"
#include "CDialogError.h"
#include "resource.h"

#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")

using namespace Gdiplus;

// CDialogError ダイアログ

IMPLEMENT_DYNAMIC(CDialogError, CDialogEx)

CDialogError::CDialogError(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_TEST_ERROR, pParent)
{

}

CDialogError::~CDialogError()
{
}

void CDialogError::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL CDialogError::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	Gdiplus::GdiplusStartupInput startupInput;

	Gdiplus::GdiplusStartup(
		&m_gdiplusToken,
		&startupInput,
		nullptr
	);


	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

BOOL CDialogError::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_gdiplusToken != 0)
	{
		Gdiplus::GdiplusShutdown(m_gdiplusToken);
		m_gdiplusToken = 0;
	}

	return TRUE;
}

#if 1
bool CDialogError::show()
{
	int nResponse = DoModal();
	if (nResponse == 100)
	{
		// OK ボタンが押された場合の処理
		return true;
	}
	else if (nResponse == 200)
	{
		// キャンセル ボタンが押された場合の処理
		return false;
	}
	return false;
}
#else
bool CDialogError::show(CWnd *pParent)
{
	if (GetSafeHwnd() == nullptr)
	{
		if (!Create(IDD_DIALOG_TEST_ERROR, pParent))
		{
			return false;
		}
	}

	ShowWindow(SW_SHOW);
	SetForegroundWindow();
	return true;
}
#endif



BEGIN_MESSAGE_MAP(CDialogError, CDialogEx)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDOK_ORIGINAL, &CDialogError::OnBnClickedOriginal)
	ON_BN_CLICKED(IDCANCEL_ORIGINAL, &CDialogError::OnBnClickedCancelOriginal)
END_MESSAGE_MAP()

void CDialogError::OnPaint()
{
	CPaintDC dc(this); // 描画のデバイス コンテキスト

	Gdiplus::Graphics graphics(dc.GetSafeHdc());

	Gdiplus::Image image(L".\\res\\olympus.png");
	if (image.GetLastStatus() != Gdiplus::Ok)
	{
		return;
	}

	// 座標 (20, 20) に、幅 300、高さ 200 で表示
	graphics.DrawImage(&image, 0, 40, 200, 200);

}


// CDialogError メッセージ ハンドラー

void CDialogError::OnBnClickedOriginal()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	EndDialog(100);
}

void CDialogError::OnBnClickedCancelOriginal()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	EndDialog(200);
}

// CDialogError.cpp : 実装ファイル
//

#include "pch.h"
#include "dialog_test.h"
#include "afxdialogex.h"
#include "CDialogError.h"
#include "resource.h"
#include "Controller.h"

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
	CRect clientRect;

	// ウィンドウのスタイルを変更してタイトルバーを非表示にする
	ModifyStyle(WS_CAPTION, 0);

	// ダイアログの位置とサイズを設定
	SetWindowPos(
		nullptr,
		1000, 300,	// x, y
		400, 400,   // width, height
		SWP_NOZORDER
	);

	// クライアント領域のサイズを取得
	GetClientRect(&clientRect);

	// ボタンの位置を設定
	CWnd* pOKButton = GetDlgItem(IDOK_ORIGINAL);
	CWnd* pCANCELButton = GetDlgItem(IDCANCEL_ORIGINAL);
	int buttonWidth = 100;
	int buttonHeight = 30;
	int margin = 10;

	int baseWindowWidth = clientRect.Width();
	int baseWindowHeight = clientRect.Height();

#if 0
	if (pOKButton != nullptr)
	{
		pOKButton->SetWindowPos(
			nullptr,
			200, 300,  // X座標、Y座標
			100, 30,      // 幅、高さ（変更しない）
			SWP_NOZORDER
		);
	}
	if (pCANCELButton != nullptr)
	{
		pCANCELButton->SetWindowPos(
			nullptr,
			300, 300,  // X座標、Y座標
			100, 30,      // 幅、高さ（変更しない）
			SWP_NOZORDER
		);
	}
#else
	if (pOKButton != nullptr)
	{
		pOKButton->SetWindowPos(
			nullptr,
			baseWindowWidth  - ( buttonWidth + margin ) * 2,  // X座標
			baseWindowHeight - ( buttonHeight + margin ),  // Y座標
			buttonWidth, buttonHeight,      // 幅、高さ（変更しない）
			SWP_NOZORDER
		);
	}
	if (pCANCELButton != nullptr)
	{
		pCANCELButton->SetWindowPos(
			nullptr,
			baseWindowWidth  - ( buttonWidth + margin ),  // X座標
			baseWindowHeight - ( buttonHeight + margin ),  // Y座標
			buttonWidth, buttonHeight,      // 幅、高さ（変更しない）
			SWP_NOZORDER
		);
	}

#endif
	CWnd* pStaticText = GetDlgItem(IDC_STATIC_TEXT_ORIGINAL);
	if (pStaticText != nullptr) {
		int textX = 100;
		int textY = 10;
		int textWidth = 100;
		int textHeight = 30;
		pStaticText->SetWindowText(_T("OlympusLOGO"));
		pStaticText->SetWindowPos(
			nullptr,
			textX, textY,  // X座標、Y座標
			textWidth, textHeight,      // 幅、高さ（変更しない）
			SWP_NOZORDER
		);
	}


	// フォントの作成
	m_font.CreatePointFont(100, _T("メイリオ"));

	// ダイアログのフォント
	SetFont(&m_font);

	// 子コントロールのフォント
	GetDlgItem(IDOK_ORIGINAL)->SetFont(&m_font);
	GetDlgItem(IDCANCEL_ORIGINAL)->SetFont(&m_font);
	GetDlgItem(IDC_STATIC_TEXT_ORIGINAL)->SetFont(&m_font);

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
int CDialogError::show()
{
	int nResponse = (int)DoModal();
	if (nResponse == RESULT_OK)
	{
		// OK ボタンが押された場合の処理
		return nResponse;
	}
	else if (nResponse == RESULT_CANCEL)
	{
		// キャンセル ボタンが押された場合の処理
		return nResponse;
	}
	return 0;
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
	EndDialog(RESULT_OK);
}

void CDialogError::OnBnClickedCancelOriginal()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	EndDialog(RESULT_CANCEL);
}

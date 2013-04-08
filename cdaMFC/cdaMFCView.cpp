
// cdaMFCView.cpp : CcdaMFCView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "cdaMFC.h"
#endif

#include "cdaMFCDoc.h"
#include "cdaMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcdaMFCView

IMPLEMENT_DYNCREATE(CcdaMFCView, CView)

BEGIN_MESSAGE_MAP(CcdaMFCView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CcdaMFCView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CcdaMFCView ����/����

CcdaMFCView::CcdaMFCView()
{
	// TODO: �ڴ˴���ӹ������

}

CcdaMFCView::~CcdaMFCView()
{
}

BOOL CcdaMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CcdaMFCView ����

void CcdaMFCView::OnDraw(CDC* /*pDC*/)
{
	CcdaMFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CcdaMFCView ��ӡ


void CcdaMFCView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CcdaMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CcdaMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CcdaMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CcdaMFCView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CcdaMFCView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CcdaMFCView ���

#ifdef _DEBUG
void CcdaMFCView::AssertValid() const
{
	CView::AssertValid();
}

void CcdaMFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CcdaMFCDoc* CcdaMFCView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CcdaMFCDoc)));
	return (CcdaMFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CcdaMFCView ��Ϣ�������

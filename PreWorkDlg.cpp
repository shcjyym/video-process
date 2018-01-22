// PreWorkDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "OpenCV.h"
#include "PreWork.h"
#include "PreWorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Pre_OpenCV Pre_Exp;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPreWorkDlg �Ի���



CPreWorkDlg::CPreWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PREWORK_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CPreWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MIN, m_min);
	DDX_Control(pDX, IDC_CLOSE, m_close);
	DDX_Control(pDX, IDC_CutVideo, m_transform);
}

BEGIN_MESSAGE_MAP(CPreWorkDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPreWorkDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CutVideo, &CPreWorkDlg::OnBnClickedCutvideo)
	ON_EN_CHANGE(IDC_OpenFile, &CPreWorkDlg::OnEnChangeOpenfile)
	ON_BN_CLICKED(IDC_CUTMAT, &CPreWorkDlg::OnBnClickedCutmat)
	ON_EN_CHANGE(IDC_ROW, &CPreWorkDlg::OnEnChangeRow)
	ON_EN_CHANGE(IDC_COLUMN, &CPreWorkDlg::OnEnChangeColumn)
	ON_WM_CTLCOLOR()
	ON_WM_NCHITTEST()
	ON_BN_CLICKED(IDCANCEL, &CPreWorkDlg::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_CLOSE, &CPreWorkDlg::OnStnClickedClose)
	ON_STN_CLICKED(IDC_MIN, &CPreWorkDlg::OnStnClickedMin)
	ON_EN_CHANGE(IDC_OpenFile2, &CPreWorkDlg::OnEnChangeOpenfile2)
END_MESSAGE_MAP()


// CPreWorkDlg ��Ϣ�������

BOOL CPreWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�
	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	newFont_1.CreatePointFont(160,"΢���ź�");
	newFont_2.CreatePointFont(100, "΢���ź�");
	m_min.SetFont(&newFont_1);
	m_close.SetFont(&newFont_2);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPreWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPreWorkDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CRect   rect;
		CPaintDC   dc(this);
		GetClientRect(rect);
		dc.FillSolidRect(rect, RGB(217, 226, 241));
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPreWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPreWorkDlg::OnBnClickedButton1()
{
	BOOL isOpen = TRUE;     //�Ƿ��(����Ϊ����)  
	CString defaultDir = "";   //Ĭ�ϴ򿪵��ļ�·��
	CString m_filename;
	CString filter = "�ļ� (*.avi; *.mp4; *.mov)|*.avi;*.mov;*.mp4||";   //�ļ����ǵ�����
	CFileDialog dlg(isOpen, defaultDir, m_filename, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);    //���ڴ�ָ��avi�ļ�
	if (dlg.DoModal() == IDOK){
		m_filename = dlg.GetPathName();
	}
	SetDlgItemText(IDC_OpenFile,m_filename);
}

void CPreWorkDlg::OnBnClickedCutvideo()
{
	CvCapture* pCapture = NULL;
	CString   strPath;
	CString outfilename;
	int nFrmNum = 0;
	CString m_filename_edit;
	if (nFrmNum == 0) {  //��һ�α���ʱѡ��Ҫ���浽���ļ���{
		BROWSEINFO bi = { 0 };
		char pszDisplayName[MAX_PATH] = "\0";
		bi.hwndOwner = NULL;
		bi.pszDisplayName = pszDisplayName;
		bi.lpszTitle = "��ѡ��Ŀ¼:";
		bi.ulFlags = BIF_RETURNONLYFSDIRS;
		LPITEMIDLIST lpIL = SHBrowseForFolder(&bi);
		if (lpIL) {
			SHGetPathFromIDList(lpIL, bi.pszDisplayName);
		}
		else {
			strPath = "";
		}
		strPath = bi.pszDisplayName;
		SetDlgItemText(IDC_OpenFile2, strPath);
	}
	GetDlgItem(IDC_OpenFile)->GetWindowText(m_filename_edit);
	pCapture = cvCaptureFromAVI(m_filename_edit);     //  ����ָ����Ƶ�ļ�  pCaptureΪ CvCapture* pCapture;
	if (pCapture == NULL)
		MessageBox("AVI��Ƶ��ʧ�ܻ��ʽ����", "������ʾ", IDOK);
	for (; ; ){
		IplImage* frame = NULL;
		frame = cvQueryFrame(pCapture);   //  cvQueryFrame( pCapture ) ������ȡָ����Ƶ�е�ÿһ֡
		if (!frame)           //��Ƶ��β�� ���˳�
			break;
		cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);      //�����洢ÿһ֡���ڴ滺��, Ϊ���汣��ͼƬ֮��
		outfilename.Format("%s//%d.jpg", strPath, nFrmNum);  //��Ϊ��ȡ����Ƶ�ܶ�֡, ʵ�ֶ�̬��������,���Զ�����ÿһ֡.
		if (!cvSaveImage(outfilename, frame)){        //cvSaveImage(outfilename,frame)    //��֡ͼ��frame����Ϊ�û���outfilename
			MessageBox("�ļ��޷����浽��Ӧ·��", "�������", IDOK);
			break;
		}
		nFrmNum = nFrmNum + 1;
	}
	cvReleaseCapture(&pCapture);
}


void CPreWorkDlg::OnEnChangeOpenfile()
{
}


void CPreWorkDlg::OnBnClickedCutmat()
{
	//������账�����зָ����
	CString m_rowstring, m_columnstring;
	GetDlgItem(IDC_ROW)->GetWindowText(m_rowstring);
	GetDlgItem(IDC_ROW)->GetWindowText(m_columnstring);
	int m_row = atoi(m_rowstring);
	int m_column = atoi(m_columnstring);
	int k = m_row*m_column;
	int o = 1;

	CvCapture* pCapture = NULL;
	CString   strPath;
	CString outfilename;
	CString infilename;
	CString m_filename_edit;
	CString m_outfile_start;
	CString create_file;
	GetDlgItem(IDC_OpenFile)->GetWindowText(m_filename_edit);
	GetDlgItem(IDC_OpenFile2)->GetWindowText(m_outfile_start);
	pCapture = cvCaptureFromAVI(m_filename_edit);     //  ����ָ����Ƶ�ļ�  pCaptureΪ CvCapture* pCapture;
	int video_width = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH);
	int video_height = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT);
	int numFrames = (int)cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_COUNT);
	int block_width = video_width / m_column;
	int block_height = video_height / m_row;
	int Num = 0;
	cvReleaseCapture(&pCapture);

	int p, q;
	IplImage* frame = NULL;
	//frame = cvLoadImage("D:/Out/1/0.jpg", -1);
	cvCreateImage(cvSize(block_width, block_height), IPL_DEPTH_8U, 1);
	if (Num == 0)  //ѡ��Ҫ���浽���ļ���
	{
		BROWSEINFO bi = { 0 };
		char pszDisplayName[MAX_PATH] = "\0";
		bi.hwndOwner = NULL;
		bi.pszDisplayName = pszDisplayName;
		bi.lpszTitle = "��ѡ��Ŀ¼:";
		bi.ulFlags = BIF_RETURNONLYFSDIRS;
		LPITEMIDLIST lpIL = SHBrowseForFolder(&bi);
		if (lpIL)
		{
			SHGetPathFromIDList(lpIL, bi.pszDisplayName);
		}
		else
		{
			strPath = "";
		}
		strPath = bi.pszDisplayName;
	}
	int rect_1;
	int rect_2;
	int rect_3;
	int rect_4;
	int a = 0;
	while (o <= k) {
		create_file.Format("%s/%d", strPath, o);
		CreateDirectory(create_file, 0);
		o++;
	}
	while (a < numFrames) {
		infilename.Format("%s/%d.jpg", m_outfile_start, a);
		p = q = 0; o = 1;
		k = m_row*m_column;
		while (o <=k ) {
			if (q == m_column) {
				q = 0;
				p++;
			}
			rect_1 = block_width*q;
			rect_2 = block_height*p;
			rect_3 = block_width;
			rect_4 = block_height;
			frame = cvLoadImage(infilename, -1);
			cv::Mat m = cv::cvarrToMat(frame);
			cv::Rect rect(rect_1, rect_2, rect_3, rect_4);
			cv::Mat image_frame = cv::Mat(m, rect);
			cv::Mat image_copy = image_frame.clone();
			frame = &IplImage(image_copy);
			outfilename.Format("%s/%d//%d_%d_%d.jpg", strPath, o, a, p + 1, q + 1); //ʵ�ֶ�̬��������
			if (!cvSaveImage(outfilename, frame)) {        //��֡ͼ��frame����Ϊ�û���outfilename
				MessageBox("�ļ��޷����浽��Ӧ·��", "�������", IDOK);
			}
			q++;
			o++;
		}
		a++;
	}
}

void CPreWorkDlg::OnEnChangeRow()
{
}


void CPreWorkDlg::OnEnChangeColumn()
{
}

HBRUSH CPreWorkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
	if (nCtlColor == CTLCOLOR_BTN)          //���İ�ť��ɫ  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(1, 121, 255));
		HBRUSH b = CreateSolidBrush(RGB(121, 121, 255));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_SCROLLBAR)  //  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(233, 233, 220));
		HBRUSH b = CreateSolidBrush(RGB(233, 233, 220));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_EDIT)   //���ı༭��  
	{
		//pDC->SetBkMode(TRANSPARENT);  
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(246, 246, 246));
		HBRUSH b = CreateSolidBrush(RGB(246, 246, 246));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_STATIC)  //���ľ�̬�ı�  
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(217, 226, 241));
		HBRUSH b = CreateSolidBrush(RGB(217, 226, 241));
		return b;
	}
	else if (nCtlColor == CTLCOLOR_DLG)   //���ĶԻ��򱳾�ɫ  
	{
		pDC->SetTextColor(RGB(0, 0, 0));
		pDC->SetBkColor(RGB(166, 254, 1));
		HBRUSH b = CreateSolidBrush(RGB(213, 226, 240));
		return b;
	}

	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������  
	return hbr;
}


LRESULT CPreWorkDlg::OnNcHitTest(CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	LRESULT ret = CDialogEx::OnNcHitTest(point);
	return (ret == HTCLIENT) ? HTCAPTION : ret;
}


void CPreWorkDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CPreWorkDlg::OnStnClickedClose()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CPreWorkDlg::OnStnClickedMin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::ShowWindow(SW_FORCEMINIMIZE);
}


void CPreWorkDlg::OnEnChangeOpenfile2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
}

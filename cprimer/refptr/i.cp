#line 1 "i.cpp"

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWndEx)

PTM_WARNING_DISABLE
const AFX_MSGMAP* CMainFrame::GetMessageMap() const
{
    return GetThisMessageMap();
}
const AFX_MSGMAP* PASCAL CMainFrame::GetThisMessageMap()
{
    typedef CMainFrame ThisClass;
    typedef CFrameWndEx TheBaseClass;
    __pragma(warning(push)) __pragma(warning(disable: 4640)) static const AFX_MSGMAP_ENTRY _messageEntries[] =
    {
        ON_WM_CREATE()
        ON_WM_SETFOCUS()
        ON_COMMAND(ID_VIEW_CUSTOMIZE, &CMainFrame::OnViewCustomize)
        ON_REGISTERED_MESSAGE(AFX_WM_CREATETOOLBAR, &CMainFrame::OnToolbarCreateNew)
        ON_COMMAND(ID_SIZEOF, &CMainFrame::OnSizeOfObject)
        ON_WM_PAINT()
        {
            0, 0, 0, 0, AfxSig_end, (AFX_PMSG)0
        }
    };
    __pragma(warning(pop)) static const AFX_MSGMAP messageMap = { &TheBaseClass::GetThisMessageMap, &_messageEntries[0] };
    return &messageMap;
}
PTM_WARNING_RESTORE

ASSERT(bNameValid);

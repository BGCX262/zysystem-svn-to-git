#include "..\stdafx.h"

class CXTPRibbonBarZ:public CXTPRibbonBar{

	public:
		DECLARE_XTP_COMMANDBAR(CXTPRibbonBarZ);
		DECLARE_MESSAGE_MAP();

		CXTPRibbonBarZ(void);
		~CXTPRibbonBarZ(void);

		afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};
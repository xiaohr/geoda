/**
 * GeoDa TM, Copyright (C) 2011-2015 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 *
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_REPORTBUG_DLG_H__
#define __GEODA_CENTER_REPORTBUG_DLG_H__

#include <string>
#include <wx/dialog.h>
#include <wx/bmpbuttn.h>
#include <wx/choice.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/hyperlink.h>

#include "../HLStateInt.h"
#include "../HighlightStateObserver.h"

using namespace std;

class PreferenceDlg : public wxDialog
{
public:
    PreferenceDlg(wxWindow* parent,
                  wxWindowID id = wxID_ANY,
                  const wxString& title = _("GeoDa Preference Setup"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxSize(580,450));
    
    PreferenceDlg(wxWindow* parent,
                  HLStateInt* highlight_state,
                  wxWindowID id = wxID_ANY,
                  const wxString& title = _("GeoDa Preference Setup"),
                  const wxPoint& pos = wxDefaultPosition,
                  const wxSize& size = wxSize(580,450));
 
    static void ReadFromCache();
    
protected:
    HLStateInt* highlight_state;
    
    void Init();
    
    void OnCrossHatch(wxCommandEvent& ev);
    void OnSlider1(wxScrollEvent& ev);
    void OnSlider2(wxScrollEvent& ev);
    //void OnSlider3(wxScrollEvent& ev);
    void OnChoice3(wxCommandEvent& ev);
    void OnDisableCrashDetect(wxCommandEvent& ev);
    void OnDisableAutoUpgrade(wxCommandEvent& ev);
   
    void OnHideTablePostGIS(wxCommandEvent& ev);
    void OnHideTableSQLITE(wxCommandEvent& ev);
    
    void OnReset(wxCommandEvent& ev);
};

class ReportResultDlg: public wxDialog
{
protected:
    wxHyperlinkCtrl* m_hyperlink1;
    
public:
    ReportResultDlg(wxWindow* parent,
                    wxString issue_url,
                    wxWindowID id = wxID_ANY,
                    const wxString& title = _("Check Bug Report on Github"),
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize);
    ~ReportResultDlg();
};



class ReportBugDlg : public wxDialog
{
public:
    ReportBugDlg(wxWindow* parent,
                 wxWindowID id = wxID_ANY,
                 const wxString& title = _("GeoDa Bug Report Dialog"),
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxSize(580,450));
    
    ~ReportBugDlg();
    
    static bool CreateIssue(wxString title, wxString body);
    
protected:
    wxString desc_tip;
    wxString steps_txt;
    
    
    wxTextCtrl* title_txt_ctrl;
    wxTextCtrl* steps_txt_ctrl;
    wxTextCtrl* user_txt_ctrl;
    wxTextCtrl* email_txt_ctrl;
    
    
    void OnOkClick( wxCommandEvent& event );
    void OnCancelClick( wxCommandEvent& event );
   
};

#endif

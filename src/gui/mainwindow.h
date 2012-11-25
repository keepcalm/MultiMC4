// 
//  Copyright 2012 MultiMC Contributors
// 
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
// 
//        http://www.apache.org/licenses/LICENSE-2.0
// 
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#pragma once
#include <wx/wx.h>
#include <wx/gbsizer.h>

#include <map>

#include "task.h"
#include "logintask.h"
#include "checkupdatetask.h"

#include "insticonlist.h"

#include "modlist.h"
#include "settingsdialog.h"

#include "instancemodel.h"

class InstanceCtrl;
class InstanceCtrlEvent;

class MainWindow : public wxFrame
{
public:
	MainWindow(void);
	~MainWindow(void);

	void OnStartup();

	// Toolbar
	void OnAddInstClicked(wxCommandEvent& event);
	void OnImportCPClicked(wxCommandEvent& event);
	void OnImportFTBClicked(wxCommandEvent& event);
	void OnViewFolderClicked(wxCommandEvent& event);
	void OnViewCMFolderClicked(wxCommandEvent& event);
	void OnRefreshClicked(wxCommandEvent& event);

	void OnSettingsClicked(wxCommandEvent& event);
	void OnCheckUpdateClicked(wxCommandEvent& event);

	void OnHelpClicked(wxCommandEvent& event);
	void OnAboutClicked(wxCommandEvent& event);
	void OnBugReportClicked(wxCommandEvent& event);


	// Instance menu
	void OnPlayClicked(wxCommandEvent& event);
	void OnInstActivated(InstanceCtrlEvent& event);
	void OnInstDeleteKey(InstanceCtrlEvent& event);
	void OnInstRenameKey(InstanceCtrlEvent& event);
	
	void OnRenameClicked(wxCommandEvent& event);
	void OnChangeGroupClicked(wxCommandEvent& event);
	void OnCopyInstClicked(wxCommandEvent &event);
	void OnChangeIconClicked(wxCommandEvent& event);
	void OnNotesClicked(wxCommandEvent& event);
	void OnInstanceSettingsClicked(wxCommandEvent& event);
	void OnMakeDesktopLinkClicked(wxCommandEvent& event);

	void OnManageSavesClicked(wxCommandEvent& event);
	void OnEditModsClicked(wxCommandEvent& event);
	void OnDowngradeInstClicked(wxCommandEvent& event);
	void OnSnapshotClicked(wxCommandEvent& event);
	void OnChangeLWJGLClicked(wxCommandEvent& event);
	void OnRebuildJarClicked(wxCommandEvent& event);
	void OnViewInstFolderClicked(wxCommandEvent& event);
	
	void OnDeleteClicked(wxCommandEvent& event);


	// Group menu
	void OnRenameGroupClicked(wxCommandEvent& event);
	void OnDeleteGroupClicked(wxCommandEvent& event);
	
	
	// Task Events
	void OnTaskEnd(TaskEvent &event);
	void OnTaskError(TaskErrorEvent &event);
	void OnLoginComplete(const LoginResult &result);
	void OnCheckUpdateComplete(CheckUpdateEvent &event);
	
	// Other events
	void OnInstMenuOpened(InstanceCtrlEvent& event);
	void OnWindowClosed(wxCloseEvent& event);
	void OnNotesLostFocus(wxFocusEvent& event);

	void OnExitApp(wxCommandEvent &event);
	
	enum task_type
	{
		TASK_BACKGROUND,
		TASK_MODAL
	};
	// Other functions

	int StartTask(Task *task);
	void LoginClicked();
	void DoLogin(UserInfo info, bool playOffline = false, bool forceUpdate = false);
	void DoLogin();
	void ShowLoginDlg(wxString errorMsg);

	void DownloadInstallUpdates(const wxString &downloadURL, bool installNow = true);
	
	void LoadInstanceList(wxFileName instDir = settings->GetInstDir());
	void LoadCentralModList();

	ModList *GetCentralModList();

	void BuildConfPack(Instance *inst, const wxString &packName, 
		const wxString &packNotes, const wxString &filename, wxArrayString &includedConfigs);

	bool GetNewInstName(wxString *instName, wxString *instDirName, const wxString title = _("Create new instance"));
	void AddInstance(Instance *inst);
	void RenameEvent();
	
	void OnNewInstance(wxCommandEvent& event);
	void OnImportMCFolder(wxCommandEvent& event);

	wxString launchInstance;
	
	DECLARE_EVENT_TABLE()

protected:
	wxMenu *instMenu;
	wxMenu *groupMenu;
	
	GUIMode m_guiMode;

	Instance* GetLinkedInst(int id);

	bool DeleteSelectedInstance();

	// maps index in the used list control to an instance.
	InstanceModel instItems;
	
	GUIMode GetGUIMode() const
	{
		return m_guiMode;
	};
	
	// Basic GUI (a simple list control with a context menu)
	void InitBasicGUI(wxBoxSizer *mainSz);
	void InitInstMenu();
	
	InstanceCtrl *instListCtrl;
	
	// Advanced GUI
	void InitAdvancedGUI(wxBoxSizer *mainSz);
	
	void OnInstSelected(InstanceCtrlEvent &event);

	void UpdateInstPanel();
	void UpdateInstNameLabel(Instance *inst);
	
	wxPanel *instPanel;
	
	wxButton *btnPlay;
	wxButton *btnRename;
	wxButton *btnChangeIcon;
	wxButton *btnCopyInst;
	wxButton *btnInstSettings;
	wxButton *btnEditMods;
	wxButton *btnManageSaves;
	wxButton *btnDowngrade;
	wxButton *btnSnapshot;
	wxButton *btnRebuildJar;
	wxButton *btnViewFolder;
	
	wxTextCtrl *instNotesEditor;
	wxButton *editNotesBtn;
	wxButton *cancelEditNotesBtn;
	
	wxBoxSizer *instNameSz;
	wxStaticText *instNameLabel;
	wxTextCtrl *instNameEditor;
	
	void UpdateNotesBox();
	void SaveNotesBox(bool current = true);
	
	void StartRename();
	void FinishRename();
	void CancelRename();
	void OnRenameEnterPressed(wxCommandEvent &event);
	bool renamingInst;
	
	void EnableInstActions(bool enabled = true);
	void DisableInstActions();
	bool instActionsEnabled;

	ModList centralModList;

	InstanceGroup *lastClickedGroup;
	
private:
	void NotImplemented();
};

enum
{
	// Toolbar
	ID_AddInst = 1,
	ID_NewInst,
	ID_ImportInst,
	ID_ImportCP,
	ID_ImportFTB,
	ID_ViewFolder,
	ID_ViewCMFolder,
	ID_ModsFolder,
	ID_Refresh,

	ID_Settings,
	ID_CheckUpdate,

	ID_Help,
	ID_About,
	ID_BugReport,

	// Instance menu
	ID_Play,

	ID_Rename,
	ID_SetGroup,
	ID_CopyInst,
	ID_ChangeIcon,
	ID_EditNotes,
	ID_Cancel_EditNotes,
	ID_Configure,
	ID_MakeDesktopLink,

	ID_ManageSaves,
	ID_EditMods,
	ID_DowngradeInst,
	ID_UseSnapshot,
	ID_ChangeLWJGL,
	ID_RebuildJar,
	ID_ViewInstFolder,

	ID_DeleteInst,

	// Group menu
	ID_RenameGroup,
	ID_DeleteGroup,

	// Other
	ID_InstListCtrl,
	
	ID_InstNameEditor,
	ID_NotesCtrl,
};


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
#include "instance.h"


class ServerInstance : public Instance 
{
private:
	wxString m_instRootPath;
protected:
	wxFileName m_serverJar;
	wxFileName m_instRoot;
public:
	wxString mcRootFolder;
	
	ServerInstance(wxString rootDir);

	wxFileName GetRootDir() const;
	wxFileName GetInstModsDir() const;
	
	// Minecraft dir subfolders
	wxFileName GetMCDir() const;
	wxFileName GetBinDir() const;
	wxFileName GetSavesDir() const;
	wxFileName GetMLModsDir() const;
	wxFileName GetCoreModsDir() const;
	wxFileName GetMCJar() const;
	wxFileName GetMCBackup() const;

		
	virtual Type GetType() const;
};
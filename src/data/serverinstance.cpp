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

#include "serverinstance.h"
#include "multimc_pragma.h"
#include <iostream>

using namespace std;
ServerInstance::ServerInstance(wxString rootDir): Instance(rootDir)
{
	cout << "My GOD, it's a server instance!" << endl;
	m_instRoot = wxFileNameFromPath(rootDir);
	m_instRootPath = rootDir;
	m_running = false;
	wxFileConfig fcfg(wxEmptyString, wxEmptyString, 
			Path::Combine(rootDir, "instance.cfg"), wxEmptyString,
			wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);
	
	fcfg.Write("type", (int)INST_TYPE_SERVER);
	
	mcRootFolder = wxFileNameFromPath(rootDir.Append("/minecraft"));
}

wxFileName ServerInstance::GetMCJar() const
{
	wxString x = mcRootFolder;
	return wxFileNameFromPath(x << wxStr("/minecraft_server.jar"));
}
wxFileName ServerInstance::GetBinDir() const
{
	return wxFileNameFromPath(mcRootFolder);
}

wxFileName ServerInstance::GetCoreModsDir() const
{
// 	mcRootFolder
	wxString x = mcRootFolder;
	return wxFileNameFromPath(x << wxStr("/coremods"));
}
wxFileName ServerInstance::GetInstModsDir() const
{
	wxString x = m_instRootPath;
	return wxFileNameFromPath(x << wxStr("/instmods"));
}
wxFileName ServerInstance::GetMLModsDir() const
{
	wxString x = mcRootFolder;
	return wxFileNameFromPath(x << wxStr("/mods"));
}
wxFileName ServerInstance::GetMCDir() const
{
	return wxFileNameFromPath(mcRootFolder);
}
wxFileName ServerInstance::GetRootDir() const
{
	return m_instRoot;
}
wxFileName ServerInstance::GetSavesDir() const
{
	return wxFileNameFromPath(mcRootFolder);
}
Instance::Type ServerInstance::GetType() const
{
	return INST_TYPE_SERVER;
}
wxFileName ServerInstance::GetMCBackup() const
{
	return wxFileNameFromPath(GetMCJar().GetFullName() << (".backup"));
}












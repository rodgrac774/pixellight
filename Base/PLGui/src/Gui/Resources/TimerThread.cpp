/*********************************************************\
 *  File: TimerThread.cpp                                *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/System/System.h>
#include <PLCore/System/CriticalSection.h>
#include "PLGui/Gui/Base/GuiMessage.h"
#include "PLGui/Gui/Resources/Timer.h"
#include "PLGui/Gui/Resources/TimerThread.h"
#include "PLGui/Gui/Gui.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
namespace PLGui {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
TimerThread::TimerThread(Timer &cTimer, uint64 nTimeout, bool bOnce) :
	m_cTimer(cTimer),
	m_pCriticalSection(new CriticalSection()),
	m_nTimeout(nTimeout),
	m_bOnce(bOnce),
	m_bShutdown(false)
{
}

/**
*  @brief
*    Destructor
*/
TimerThread::~TimerThread()
{
	// Delete critical section
	delete m_pCriticalSection;
}

/**
*  @brief
*    Stop timer thread
*/
void TimerThread::StopTimer()
{
	// Deactivate timer
	m_pCriticalSection->Lock();
	m_bShutdown = true;
	m_pCriticalSection->Unlock();

	// Wait for thread to exit
	if (!Join(200)) {
		// We asked politely, but the thread won't listen... so pull out the gun!
		// (the internal platform implementation may or may not accept this violent act)
		Terminate();
		m_pCriticalSection->Unlock();
	}
}

/**
*  @brief
*    Fire timer
*/
void TimerThread::Fire()
{
	// Send timer message
	m_cTimer.GetGui()->PostMessage(GuiMessage::OnTimer(&m_cTimer));
}


//[-------------------------------------------------------]
//[ Private virtual ThreadFunction functions              ]
//[-------------------------------------------------------]
int TimerThread::Run()
{
	// Start timer loop
	bool bRunning = true;
	do {
		// Wait for timeout
		System::GetInstance()->Sleep(m_nTimeout);

		// Timer fired
		Fire();

		// Check if timer is still active
		m_pCriticalSection->Lock();
		if (m_bOnce)	 bRunning = false;
		if (m_bShutdown) bRunning = false;
		m_pCriticalSection->Unlock();
	} while (bRunning);

	// Timer is no longer active
	m_cTimer.m_bActive = false;

	// Done
	return 0;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLGui

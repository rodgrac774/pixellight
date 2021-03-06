/*********************************************************\
 *  File: SurfaceWindow.cpp                              *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


//[-------------------------------------------------------]
//[ Definitions                                           ]
//[-------------------------------------------------------]
#define POINTER_64 __ptr64	// We need this for VC 2010, else we get "error C2146: syntax error : missing ';' before identifier 'PVOID64'"


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLRendererD3D9/Renderer.h"
#include "PLRendererD3D9/SurfaceWindow.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
using namespace PLCore;
using namespace PLMath;
namespace PLRendererD3D9 {


//[-------------------------------------------------------]
//[ Public functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Destructor
*/
SurfaceWindow::~SurfaceWindow()
{
	DeInit();
}


//[-------------------------------------------------------]
//[ Private functions                                     ]
//[-------------------------------------------------------]
/**
*  @brief
*    Constructor
*/
SurfaceWindow::SurfaceWindow(PLRenderer::SurfaceWindowHandler &cHandler, handle nNativeWindowHandle, bool bFullscreen) :
	PLRenderer::SurfaceWindow(cHandler, nNativeWindowHandle, bFullscreen),
	EventHandlerSize(&SurfaceWindow::OnSize, this),
	m_pSwapChain(nullptr),
	m_pBackBuffer(nullptr)
{
	// [TODO] Window size change
	// Connect event handler
//	cWindow.SignalSize.Connect(&EventHandlerSize);

	// Init
	Init();
}

/**
*  @brief
*    Called when the window size has been changed
*/
void SurfaceWindow::OnSize(const Vector2i &vSize)
{
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	Renderer &cRenderer = static_cast<Renderer&>(GetRenderer());
	LPDIRECT3D9 pD3D = cRenderer.GetInstance();
	if (pD3D) {
		LPDIRECT3DDEVICE9 pDevice = cRenderer.GetDevice();
		if (pDevice) {
			D3DDISPLAYMODE mode;
			if (SUCCEEDED(pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode))) {
				d3dpp.BackBufferFormat		 = mode.Format;
				d3dpp.BackBufferWidth		 = vSize.x;
				d3dpp.BackBufferHeight		 = vSize.y;
				d3dpp.EnableAutoDepthStencil = true;
			//	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
				d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
				d3dpp.Flags                  = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
				d3dpp.Windowed               = true;
				d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
				d3dpp.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;

				// After CreateDevice, the first swap chain already exists, so just get it...
				pDevice->Reset(&d3dpp);
			}
		}
	}
}


//[-------------------------------------------------------]
//[ Public virtual PLRenderer::SurfaceWindow functions    ]
//[-------------------------------------------------------]
bool SurfaceWindow::GetGamma(float &fRed, float &fGreen, float &fBlue) const
{
	// [TODO] Implement me

	// Error!
	return false;
}

bool SurfaceWindow::SetGamma(float fRed, float fGreen, float fBlue)
{
	// [TODO] Implement me

	// Error!
	return false;
}


//[-------------------------------------------------------]
//[ Public virtual PLRenderer::Surface functions          ]
//[-------------------------------------------------------]
Vector2i SurfaceWindow::GetSize() const
{
	if (!m_pSwapChain)
		return Vector2i::Zero; // Error!
	D3DDISPLAYMODE mode;
	m_pSwapChain->GetDisplayMode(&mode);

	// Return size
	return Vector2i(mode.Width, mode.Height);
}


//[-------------------------------------------------------]
//[ Private virtual PLRenderer::Surface functions         ]
//[-------------------------------------------------------]
bool SurfaceWindow::Init()
{
	// Get renderer
	Renderer &cRenderer = static_cast<Renderer&>(GetRenderer());
	if (GetNativeWindowHandle()) {
		LPDIRECT3D9 pD3D = cRenderer.GetInstance();
		if (pD3D) {
			// Get renderer device
			LPDIRECT3DDEVICE9 pDevice = cRenderer.GetDevice();
			if (pDevice) {
				// Create renderer device
				D3DPRESENT_PARAMETERS d3dpp;
				ZeroMemory(&d3dpp, sizeof(d3dpp));

				// Use the current display mode
				D3DDISPLAYMODE mode;
				if (SUCCEEDED(pD3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &mode))) {
					d3dpp.BackBufferFormat		 = mode.Format;
					d3dpp.BackBufferWidth		 = mode.Width;
					d3dpp.BackBufferHeight		 = mode.Height;
					d3dpp.EnableAutoDepthStencil = true;
				//	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
					d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
					d3dpp.Flags                  = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;
					d3dpp.Windowed               = true;
					d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD;
					d3dpp.PresentationInterval   = D3DPRESENT_INTERVAL_IMMEDIATE;

					// After CreateDevice, the first swap chain already exists, so just get it...
					if (cRenderer.m_pFirstSwapChainUserSurface) {
						pDevice->CreateAdditionalSwapChain(&d3dpp, &m_pSwapChain);
					} else { // But further one will need to be explicitly created...
				//		pDevice->Reset(&d3dpp);
						pDevice->GetSwapChain(0, &m_pSwapChain);
						cRenderer.m_pFirstSwapChainUserSurface = this;
					}

					// Done
					return true;
				}
			}
		}
	}

	// Error!
	return false;
}

void SurfaceWindow::DeInit()
{
	if (m_pSwapChain) {
		// Get renderer
		Renderer &cRenderer = static_cast<Renderer&>(GetRenderer());

		// Release swap chain
		if (cRenderer.m_pFirstSwapChainUserSurface == this)
			cRenderer.m_pFirstSwapChainUserSurface = nullptr;
		else
			m_pSwapChain->Release();
	}
}

bool SurfaceWindow::MakeCurrent(uint8 nFace)
{
	if (m_pSwapChain) {
		Renderer &cRenderer = static_cast<Renderer&>(GetRenderer());
		LPDIRECT3DDEVICE9 pDevice = cRenderer.GetDevice();
		if (pDevice) {
			// Tell the Direct3D device to render to the first swap chain�s back buffer
			m_pSwapChain->GetBackBuffer(0, D3DBACKBUFFER_TYPE_MONO, &m_pBackBuffer);
			return (pDevice->SetRenderTarget(0, m_pBackBuffer) == D3D_OK);
		}
	}

	// Error!
	return false;
}

bool SurfaceWindow::UnmakeCurrent()
{
	// Nothing to do here...
	return true;
}

bool SurfaceWindow::Present()
{
	// Is there a swap chain and a back buffer?
	if (m_pSwapChain && m_pBackBuffer && GetNativeWindowHandle()) {
		// Get surface window and present swap chain to window
		if (m_pSwapChain->Present(nullptr, nullptr, reinterpret_cast<HWND>(GetNativeWindowHandle()), nullptr, 0) == D3D_OK) {
			m_pBackBuffer->Release();
			m_pBackBuffer = nullptr;

			// Done
			return true;
		}
	}

	// Error!
	return false;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLRendererD3D9

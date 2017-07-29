#include "Visuals.h"
#include "Interfaces.h"
#include "RenderManager.h"

// Any init here
void CVisuals::Init()
{
	// Idk
}

// Don't really need to do anything in here
void CVisuals::Move(CUserCmd *pCmd, bool &bSendPacket) {}

// Main ESP Drawing loop
void CVisuals::Draw()
{

	// Crosshair
	DrawCrosshair();

	// Recoil Crosshair
	DrawRecoilCrosshair();

}

// Draw a basic crosshair
void CVisuals::DrawCrosshair()
{
	if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 1)
	{
		static float rainbow;
		rainbow += 0.005f;
		if (rainbow > 1.f) rainbow = 0.f;

		RECT View = Render::GetViewport();
		int MidX = View.right / 2;
		int MidY = View.bottom / 2;
		Render::Line(MidX - 4, MidY - 4, MidX + 4, MidY + 4, Color::FromHSB(rainbow, 1.f, 1.f));
		Render::Line(MidX + 4, MidY - 4, MidX - 4, MidY + 4, Color::FromHSB(rainbow, 1.f, 1.f));
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 2)
	{
		static float rainbow;
		rainbow += 0.005f;
		if (rainbow > 1.f) rainbow = 0.f;

		RECT View = Render::GetViewport();
		int drX = View.right / 2;
		int drY = View.bottom / 2;
		// Color color(255, 0, 0, 255);

		Render::Line(drX, drY, drX, drY - 30, Color::FromHSB(rainbow, 1.f, 1.f));
		Render::Line(drX, drY - 30, drX + 30, drY - 30, Color::FromHSB(rainbow, 1.f, 1.f));

		Render::Line(drX, drY, drX + 30, drY, Color::FromHSB(rainbow, 1.f, 1.f));
		Render::Line(drX + 30, drY, drX + 30, drY + 30, Color::FromHSB(rainbow, 1.f, 1.f));

		Render::Line(drX, drY, drX, drY + 30, Color::FromHSB(rainbow, 1.f, 1.f));
		Render::Line(drX, drY + 30, drX - 30, drY + 30, Color::FromHSB(rainbow, 1.f, 1.f));

		Render::Line(drX, drY, drX - 30, drY, Color::FromHSB(rainbow, 1.f, 1.f));
		Render::Line(drX - 30, drY, drX - 30, drY - 30, Color::FromHSB(rainbow, 1.f, 1.f));
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 3)
	{
		// For future codes
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 4)
	{
		// For future codes
	}
	else if (Menu::Window.VisualsTab.OtherCrosshair.GetIndex() == 5)
	{
		// For future codes
	}
}


// Recoil crosshair
void CVisuals::DrawRecoilCrosshair()
{
	if (Menu::Window.VisualsTab.OtherRecoilCrosshair.GetIndex() == 0)
	{
		// No recoil crosshair selected in menu.
	}

	else if (Menu::Window.VisualsTab.OtherRecoilCrosshair.GetIndex() == 1)
	{
		// Recoil Crosshair 1

		IClientEntity *pLocal = hackManager.pLocal();

		// Get the view with the recoil
		Vector ViewAngles;
		Interfaces::Engine->GetViewAngles(ViewAngles);
		ViewAngles += pLocal->localPlayerExclusive()->GetAimPunchAngle() * 2.f;

		// Build a ray going fowards at that angle
		Vector fowardVec;
		AngleVectors(ViewAngles, &fowardVec);
		fowardVec *= 10000;

		// Get ray start / end
		Vector start = pLocal->GetOrigin() + pLocal->GetViewOffset();
		Vector end = start + fowardVec, endScreen;

		if (Render::WorldToScreen(end, endScreen) && pLocal->IsAlive())
		{
			Render::Line(endScreen.x - 4, endScreen.y - 4, endScreen.x + 4, endScreen.y + 4, Color(0, 255, 0, 255));
			Render::Line(endScreen.x + 4, endScreen.y - 4, endScreen.x - 4, endScreen.y + 4, Color(0, 255, 0, 255));
			Render::Line(endScreen.x - 2, endScreen.y - 2, endScreen.x + 2, endScreen.y + 2, Color(0, 0, 0, 200));
			Render::Line(endScreen.x + 2, endScreen.y - 2, endScreen.x - 2, endScreen.y + 2, Color(0, 0, 0, 200));
		}
	}
}

void CVisuals::DrawCenterRadar()
{
}

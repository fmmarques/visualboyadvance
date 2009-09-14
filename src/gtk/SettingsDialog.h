// -*- C++ -*-
// VisualBoyAdvance - Nintendo Gameboy/GameboyAdvance (TM) emulator.
// Copyright (C) 2008 VBA-M development team

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or(at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef __VBA_SETTINGS_H__
#define __VBA_SETTINGS_H__

#include <gtkmm.h>

#include "ConfigFile.h"
#include "Window.h"

namespace VBA
{

class SettingsDialog : public Gtk::Dialog
{
public:
	SettingsDialog(GtkDialog* _pstDialog, const Glib::RefPtr<Gtk::Builder>& refBuilder);

	void vSetConfig(Config::Section * _poSoundConfig, Config::Section * _poDisplayConfig,
	                Config::Section * _poCoreConfig, Config::Section * _poDirConfig, VBA::Window * _poWindow);

private:
	VBA::Window *             m_poWindow;

	// General
	void vOnPauseChanged();
	void vOnFrameskipChanged();

	Config::Section *         m_poCoreConfig;
	Gtk::CheckButton *        m_poPauseOnInactiveCheckButton;
	Gtk::CheckButton *        m_poEnableFrameskipCheckButton;

	// Sound
	void vOnVolumeChanged();
	void vOnRateChanged();

	Config::Section *         m_poSoundConfig;
	Gtk::ComboBox *           m_poVolumeComboBox;
	Gtk::ComboBox *           m_poRateComboBox;

	// Display
	void vOnOutputChanged();
	void vOnScaleChanged();
	void vOnShowSpeedChanged();

	Config::Section *         m_poDisplayConfig;
	Gtk::ComboBox *           m_poDefaultScaleComboBox;
	Gtk::CheckButton *        m_poUseOpenGLCheckButton;
	Gtk::CheckButton *        m_poShowSpeedCheckButton;

	// Paths
	void vOnBiosChanged();
	void vOnRomsChanged();
	void vOnBatteriesChanged();
	void vOnSavesChanged();

	Config::Section *         m_poDirConfig;
	Gtk::FileChooserButton *  m_poBiosFileChooserButton;
	Gtk::FileChooserButton *  m_poRomsFileChooserButton;
	Gtk::FileChooserButton *  m_poBatteriesFileChooserButton;
	Gtk::FileChooserButton *  m_poSavesFileChooserButton;
};

} // namespace VBA


#endif // __VBA_SETTINGS_H__
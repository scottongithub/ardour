/*
    Copyright (C) 2010 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifndef __gtk2_ardour_engine_dialog_h__
#define __gtk2_ardour_engine_dialog_h__

#include <map>
#include <vector>
#include <string>

#include <gtkmm/checkbutton.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/notebook.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/table.h>
#include <gtkmm/expander.h>
#include <gtkmm/box.h>
#include <gtkmm/buttonbox.h>
#include <gtkmm/button.h>

class EngineControl : public Gtk::VBox {
  public:
	EngineControl ();
	~EngineControl ();

	static bool need_setup ();
	int setup_engine (bool start);

	bool was_used() const { return _used; }
	XMLNode& get_state ();
	void set_state (const XMLNode&);

  private:
    /* core fields used by all backends */

    Gtk::ComboBoxText backend_combo;
    Gtk::ComboBoxText input_device_combo;
    Gtk::ComboBoxText output_device_combo;
    Gtk::ComboBoxText sample_rate_combo;
    Gtk::ComboBoxText buffer_size_combo;
    Gtk::Adjustment input_latency_adjustment;
    Gtk::SpinButton input_latency;
    Gtk::Adjustment output_latency_adjustment;
    Gtk::SpinButton output_latency;
    Gtk::Adjustment input_channels_adjustment;
    Gtk::SpinButton input_channels;
    Gtk::Adjustment output_channels_adjustment;
    Gtk::SpinButton output_channels;
    Gtk::Adjustment ports_adjustment;
    Gtk::SpinButton ports_spinner;
    Gtk::Label latency_label;

    /* JACK specific */
    
    Gtk::CheckButton realtime_button;
    Gtk::CheckButton no_memory_lock_button;
    Gtk::CheckButton unlock_memory_button;
    Gtk::CheckButton soft_mode_button;
    Gtk::CheckButton monitor_button;
    Gtk::CheckButton force16bit_button;
    Gtk::CheckButton hw_monitor_button;
    Gtk::CheckButton hw_meter_button;
    Gtk::CheckButton verbose_output_button;
    
    
    Gtk::ComboBoxText preset_combo;
    Gtk::ComboBoxText serverpath_combo;
    Gtk::ComboBoxText driver_combo;
    Gtk::ComboBoxText interface_combo;
    Gtk::ComboBoxText timeout_combo;
    Gtk::ComboBoxText dither_mode_combo;
    Gtk::ComboBoxText audio_mode_combo;
    Gtk::ComboBoxText midi_driver_combo;
    
    Gtk::Table basic_packer;
    Gtk::Table options_packer;
    Gtk::Table device_packer;
    Gtk::HBox basic_hbox;
    Gtk::HBox options_hbox;
    Gtk::HBox device_hbox;
    Gtk::Notebook notebook;
    
    bool _used;
    
    static bool engine_running ();
    
    void driver_changed ();
    void backend_changed ();

    void redisplay_latency ();

    uint32_t get_rate() const;
    uint32_t get_buffer_size() const;
    uint32_t get_input_channels() const;
    uint32_t get_output_channels() const;
    uint32_t get_input_latency() const;
    uint32_t get_output_latency() const;
    std::string get_device_name() const;
    std::string get_driver() const;

    void audio_mode_changed ();
    void interface_changed ();
    void list_devices ();
};

#endif /* __gtk2_ardour_engine_dialog_h__ */

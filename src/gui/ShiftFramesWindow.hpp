/*
 * Copyright (C) 2018 Werner Turing <werner.turing@protonmail.com>
 *
 * This file is part of multi-delogo.
 *
 * multi-delogo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * multi-delogo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with multi-delogo.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MDL_SHIFT_FRAMES_WINDOW_H
#define MDL_SHIFT_FRAMES_WINDOW_H

#include <gtkmm.h>

#include "FilterListModel.hpp"


namespace mdl {
  class ShiftFramesWindow : public Gtk::Dialog
  {
  public:
    static ShiftFramesWindow* create(Glib::RefPtr<FilterListModel> filter_model,
                                     int total_frames, int start_frame);

    ShiftFramesWindow(BaseObjectType* cobject,
                      const Glib::RefPtr<Gtk::Builder>& builder,
                      Glib::RefPtr<FilterListModel> filter_model,
                      int total_frames, int start_frame);

    int get_initial_frame() const;
    int get_final_frame() const;
    int get_amount() const;

  private:
    Glib::RefPtr<FilterListModel>& filter_model_;

    Gtk::SpinButton* txt_initial_frame_;
    Gtk::SpinButton* txt_final_frame_;
    Gtk::SpinButton* txt_amount_;

    void configure_spin(Gtk::SpinButton& spin, int max);
  };
}

#endif // MDL_SHIFT_FRAMES_WINDOW_H
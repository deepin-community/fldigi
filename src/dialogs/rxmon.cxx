// generated by Fast Light User Interface Designer (fluid) version 1.0309

#include "gettext.h"
#include "rxmon.h"
#include <config.h>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Box.H>
#include <FL/filename.H>
#include <FL/Fl_File_Chooser.H>
#include "main.h"
#include "fl_digi.h"
#include "soundconf.h"
#include "icons.h"
#include "status.h"
#include "fileselect.h"
#include "audio_alert.h"

Fl_Check_Button *btn_mon_xcvr_audio=(Fl_Check_Button *)0;

static void cb_btn_mon_xcvr_audio(Fl_Check_Button* o, void*) {
  progdefaults.mon_xcvr_audio = o->value();
}

Fl_Value_Slider2 *sldrRxFilt_vol=(Fl_Value_Slider2 *)0;

static void cb_sldrRxFilt_vol(Fl_Value_Slider2* o, void*) {
  progdefaults.RxFilt_vol = o->value();
progdefaults.changed = true;
}

Fl_Check_Button *btn_rxgain_x10=(Fl_Check_Button *)0;

static void cb_btn_rxgain_x10(Fl_Check_Button* o, void*) {
  progdefaults.rxgain_x10 = o->value();
}

Fl_Check_Button *btn_mon_dsp_audio=(Fl_Check_Button *)0;

static void cb_btn_mon_dsp_audio(Fl_Check_Button* o, void*) {
  progdefaults.mon_dsp_audio = o->value();
}

Fl_Value_Slider2 *sldrRxFilt_bw=(Fl_Value_Slider2 *)0;

static void cb_sldrRxFilt_bw(Fl_Value_Slider2* o, void*) {
  progdefaults.RxFilt_bw = o->value();

int bw2 = progdefaults.RxFilt_bw / 2;
progdefaults.RxFilt_low = progdefaults.RxFilt_mid - bw2;
if (progdefaults.RxFilt_low < 100) progdefaults.RxFilt_low = 100;

progdefaults.RxFilt_high = progdefaults.RxFilt_mid + bw2;
if (progdefaults.RxFilt_high > 4000) progdefaults.RxFilt_high = 4000;

sldrRxFilt_low->value(progdefaults.RxFilt_low);
sldrRxFilt_low->redraw();
sldrRxFilt_high->value(progdefaults.RxFilt_high);
sldrRxFilt_high->redraw();

progdefaults.changed = true;
audio_alert->init_filter();
}

Fl_Value_Slider2 *sldrRxFilt_mid=(Fl_Value_Slider2 *)0;

static void cb_sldrRxFilt_mid(Fl_Value_Slider2* o, void*) {
  progdefaults.RxFilt_mid = o->value();

int bw2 = progdefaults.RxFilt_bw / 2;
progdefaults.RxFilt_low = progdefaults.RxFilt_mid - bw2;
if (progdefaults.RxFilt_low < 100) progdefaults.RxFilt_low = 100;

progdefaults.RxFilt_high = progdefaults.RxFilt_mid + bw2;
if (progdefaults.RxFilt_high > 4000) progdefaults.RxFilt_high = 4000;

sldrRxFilt_low->value(progdefaults.RxFilt_low);
sldrRxFilt_low->redraw();
sldrRxFilt_high->value(progdefaults.RxFilt_high);
sldrRxFilt_high->redraw();

progdefaults.changed = true;
audio_alert->init_filter();
}

Fl_Value_Slider2 *sldrRxFilt_low=(Fl_Value_Slider2 *)0;

static void cb_sldrRxFilt_low(Fl_Value_Slider2* o, void*) {
  progdefaults.RxFilt_low = o->value();

int bw = progdefaults.RxFilt_high - progdefaults.RxFilt_low;
progdefaults.RxFilt_bw = bw;
sldrRxFilt_bw->value(bw);
sldrRxFilt_bw->redraw();

int mid = (progdefaults.RxFilt_high + progdefaults.RxFilt_low) / 2;
progdefaults.RxFilt_mid = mid;
sldrRxFilt_mid->value(mid);
sldrRxFilt_mid->redraw();

progdefaults.changed = true;
audio_alert->init_filter();
}

Fl_Value_Slider2 *sldrRxFilt_high=(Fl_Value_Slider2 *)0;

static void cb_sldrRxFilt_high(Fl_Value_Slider2* o, void*) {
  progdefaults.RxFilt_high = o->value();

int bw = progdefaults.RxFilt_high - progdefaults.RxFilt_low;
progdefaults.RxFilt_bw = bw;
sldrRxFilt_bw->value(bw);
sldrRxFilt_bw->redraw();

int mid = (progdefaults.RxFilt_high + progdefaults.RxFilt_low) / 2;
progdefaults.RxFilt_mid = mid;
sldrRxFilt_mid->value(mid);
sldrRxFilt_mid->redraw();

progdefaults.changed = true;
audio_alert->init_filter();
}

Fl_Check_Button *btn_RxFilt_at_track=(Fl_Check_Button *)0;

static void cb_btn_RxFilt_at_track(Fl_Check_Button* o, void*) {
  progdefaults.RxFilt_track_wf = o->value();

if (o->value() == 1) center_rxfilt_at_track();
}

Fl_Check_Button *btn_mon_wf_display=(Fl_Check_Button *)0;

static void cb_btn_mon_wf_display(Fl_Check_Button* o, void*) {
  progdefaults.mon_wf_display = o->value();
}

Fl_Check_Button *btn_mon_xmt_audio=(Fl_Check_Button *)0;

static void cb_btn_mon_xmt_audio(Fl_Check_Button* o, void*) {
  progdefaults.mon_xmt_audio = o->value();
}

Fl_Value_Slider2 *sldr_tx_vol=(Fl_Value_Slider2 *)0;

static void cb_sldr_tx_vol(Fl_Value_Slider2* o, void*) {
  progdefaults.mon_tx_vol = o->value();
progdefaults.changed = true;
}

Fl_Double_Window* make_rxaudio_dialog() {
  Fl_Double_Window* w;
  { Fl_Double_Window* o = new Fl_Double_Window(360, 290, _("Rx Audio Monitor"));
    w = o; if (w) {/* empty */}
    { Fl_Group* o = new Fl_Group(5, 4, 350, 50);
      o->box(FL_BORDER_FRAME);
      o->color(FL_FOREGROUND_COLOR);
      { Fl_Check_Button* o = btn_mon_xcvr_audio = new Fl_Check_Button(15, 8, 70, 18, _("RX Monitor"));
        btn_mon_xcvr_audio->tooltip(_("Rx audio stream ON"));
        btn_mon_xcvr_audio->down_box(FL_DOWN_BOX);
        btn_mon_xcvr_audio->callback((Fl_Callback*)cb_btn_mon_xcvr_audio);
        o->value(progdefaults.mon_xcvr_audio);
      } // Fl_Check_Button* btn_mon_xcvr_audio
      { Fl_Value_Slider2* o = sldrRxFilt_vol = new Fl_Value_Slider2(15, 28, 290, 20, _("Rx Vol"));
        sldrRxFilt_vol->tooltip(_("Rx audio volume"));
        sldrRxFilt_vol->type(5);
        sldrRxFilt_vol->box(FL_DOWN_BOX);
        sldrRxFilt_vol->color((Fl_Color)206);
        sldrRxFilt_vol->selection_color((Fl_Color)2);
        sldrRxFilt_vol->labeltype(FL_NORMAL_LABEL);
        sldrRxFilt_vol->labelfont(0);
        sldrRxFilt_vol->labelsize(14);
        sldrRxFilt_vol->labelcolor(FL_FOREGROUND_COLOR);
        sldrRxFilt_vol->maximum(100);
        sldrRxFilt_vol->step(1);
        sldrRxFilt_vol->value(50);
        sldrRxFilt_vol->textsize(14);
        sldrRxFilt_vol->callback((Fl_Callback*)cb_sldrRxFilt_vol);
        sldrRxFilt_vol->align(Fl_Align(FL_ALIGN_RIGHT));
        sldrRxFilt_vol->when(FL_WHEN_CHANGED);
        o->value(progdefaults.RxFilt_vol);
      } // Fl_Value_Slider2* sldrRxFilt_vol
      { Fl_Check_Button* o = btn_rxgain_x10 = new Fl_Check_Button(212, 7, 93, 18, _("Gain X 10"));
        btn_rxgain_x10->tooltip(_("Rx audio stream ON"));
        btn_rxgain_x10->down_box(FL_DOWN_BOX);
        btn_rxgain_x10->callback((Fl_Callback*)cb_btn_rxgain_x10);
        o->value(progdefaults.rxgain_x10);
      } // Fl_Check_Button* btn_rxgain_x10
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(5, 58, 350, 168, _("Filter Settings"));
      o->box(FL_BORDER_FRAME);
      o->color(FL_FOREGROUND_COLOR);
      o->align(Fl_Align(FL_ALIGN_TOP_LEFT|FL_ALIGN_INSIDE));
      { Fl_Check_Button* o = btn_mon_dsp_audio = new Fl_Check_Button(191, 68, 70, 18, _("Rx audio filter ON"));
        btn_mon_dsp_audio->tooltip(_("Enable DSP filtering of rx audio stream"));
        btn_mon_dsp_audio->down_box(FL_DOWN_BOX);
        btn_mon_dsp_audio->callback((Fl_Callback*)cb_btn_mon_dsp_audio);
        o->value(progdefaults.mon_dsp_audio);
      } // Fl_Check_Button* btn_mon_dsp_audio
      { Fl_Value_Slider2* o = sldrRxFilt_bw = new Fl_Value_Slider2(10, 93, 300, 20, _("BW"));
        sldrRxFilt_bw->tooltip(_("Filter bandwidth"));
        sldrRxFilt_bw->type(5);
        sldrRxFilt_bw->box(FL_DOWN_BOX);
        sldrRxFilt_bw->color((Fl_Color)206);
        sldrRxFilt_bw->selection_color((Fl_Color)2);
        sldrRxFilt_bw->labeltype(FL_NORMAL_LABEL);
        sldrRxFilt_bw->labelfont(0);
        sldrRxFilt_bw->labelsize(14);
        sldrRxFilt_bw->labelcolor(FL_FOREGROUND_COLOR);
        sldrRxFilt_bw->minimum(50);
        sldrRxFilt_bw->maximum(4000);
        sldrRxFilt_bw->step(10);
        sldrRxFilt_bw->value(500);
        sldrRxFilt_bw->textsize(14);
        sldrRxFilt_bw->callback((Fl_Callback*)cb_sldrRxFilt_bw);
        sldrRxFilt_bw->align(Fl_Align(FL_ALIGN_RIGHT));
        sldrRxFilt_bw->when(FL_WHEN_CHANGED);
        o->value(progdefaults.RxFilt_bw);
      } // Fl_Value_Slider2* sldrRxFilt_bw
      { Fl_Value_Slider2* o = sldrRxFilt_mid = new Fl_Value_Slider2(10, 120, 300, 20, _("Mid"));
        sldrRxFilt_mid->tooltip(_("Filter center frequ ency"));
        sldrRxFilt_mid->type(5);
        sldrRxFilt_mid->box(FL_DOWN_BOX);
        sldrRxFilt_mid->color((Fl_Color)206);
        sldrRxFilt_mid->selection_color((Fl_Color)2);
        sldrRxFilt_mid->labeltype(FL_NORMAL_LABEL);
        sldrRxFilt_mid->labelfont(0);
        sldrRxFilt_mid->labelsize(14);
        sldrRxFilt_mid->labelcolor(FL_FOREGROUND_COLOR);
        sldrRxFilt_mid->minimum(400);
        sldrRxFilt_mid->maximum(3500);
        sldrRxFilt_mid->step(10);
        sldrRxFilt_mid->value(1500);
        sldrRxFilt_mid->textsize(14);
        sldrRxFilt_mid->callback((Fl_Callback*)cb_sldrRxFilt_mid);
        sldrRxFilt_mid->align(Fl_Align(FL_ALIGN_RIGHT));
        sldrRxFilt_mid->when(FL_WHEN_CHANGED);
        o->value(progdefaults.RxFilt_mid);
      } // Fl_Value_Slider2* sldrRxFilt_mid
      { Fl_Value_Slider2* o = sldrRxFilt_low = new Fl_Value_Slider2(10, 147, 300, 20, _("Low"));
        sldrRxFilt_low->tooltip(_("Filter low cutoff frequency"));
        sldrRxFilt_low->type(5);
        sldrRxFilt_low->box(FL_DOWN_BOX);
        sldrRxFilt_low->color((Fl_Color)206);
        sldrRxFilt_low->selection_color((Fl_Color)2);
        sldrRxFilt_low->labeltype(FL_NORMAL_LABEL);
        sldrRxFilt_low->labelfont(0);
        sldrRxFilt_low->labelsize(14);
        sldrRxFilt_low->labelcolor(FL_FOREGROUND_COLOR);
        sldrRxFilt_low->minimum(100);
        sldrRxFilt_low->maximum(3000);
        sldrRxFilt_low->step(10);
        sldrRxFilt_low->value(500);
        sldrRxFilt_low->textsize(14);
        sldrRxFilt_low->callback((Fl_Callback*)cb_sldrRxFilt_low);
        sldrRxFilt_low->align(Fl_Align(FL_ALIGN_RIGHT));
        sldrRxFilt_low->when(FL_WHEN_CHANGED);
        o->value(progdefaults.RxFilt_low);
      } // Fl_Value_Slider2* sldrRxFilt_low
      { Fl_Value_Slider2* o = sldrRxFilt_high = new Fl_Value_Slider2(10, 174, 300, 20, _("High"));
        sldrRxFilt_high->tooltip(_("Filter high cutoff frequency"));
        sldrRxFilt_high->type(5);
        sldrRxFilt_high->box(FL_DOWN_BOX);
        sldrRxFilt_high->color((Fl_Color)206);
        sldrRxFilt_high->selection_color((Fl_Color)2);
        sldrRxFilt_high->labeltype(FL_NORMAL_LABEL);
        sldrRxFilt_high->labelfont(0);
        sldrRxFilt_high->labelsize(14);
        sldrRxFilt_high->labelcolor(FL_FOREGROUND_COLOR);
        sldrRxFilt_high->minimum(500);
        sldrRxFilt_high->maximum(4000);
        sldrRxFilt_high->step(10);
        sldrRxFilt_high->value(900);
        sldrRxFilt_high->textsize(14);
        sldrRxFilt_high->callback((Fl_Callback*)cb_sldrRxFilt_high);
        sldrRxFilt_high->align(Fl_Align(FL_ALIGN_RIGHT));
        sldrRxFilt_high->when(FL_WHEN_CHANGED);
        o->value(progdefaults.RxFilt_high);
      } // Fl_Value_Slider2* sldrRxFilt_high
      { Fl_Check_Button* o = btn_RxFilt_at_track = new Fl_Check_Button(15, 201, 70, 18, _("track WF cursor"));
        btn_RxFilt_at_track->tooltip(_("Filter center freq tracks waterfall track point"));
        btn_RxFilt_at_track->down_box(FL_DOWN_BOX);
        btn_RxFilt_at_track->callback((Fl_Callback*)cb_btn_RxFilt_at_track);
        o->value(progdefaults.RxFilt_track_wf);
      } // Fl_Check_Button* btn_RxFilt_at_track
      { Fl_Check_Button* o = btn_mon_wf_display = new Fl_Check_Button(195, 201, 70, 18, _("Waterfall display"));
        btn_mon_wf_display->tooltip(_("DSP filter width visible on waterfall"));
        btn_mon_wf_display->down_box(FL_DOWN_BOX);
        btn_mon_wf_display->callback((Fl_Callback*)cb_btn_mon_wf_display);
        o->value(progdefaults.mon_wf_display);
      } // Fl_Check_Button* btn_mon_wf_display
      o->end();
    } // Fl_Group* o
    { Fl_Group* o = new Fl_Group(5, 230, 350, 54);
      o->box(FL_BORDER_FRAME);
      o->color(FL_FOREGROUND_COLOR);
      { Fl_Check_Button* o = btn_mon_xmt_audio = new Fl_Check_Button(10, 238, 70, 18, _("TX Monitor"));
        btn_mon_xmt_audio->tooltip(_("Transmit audio monitored"));
        btn_mon_xmt_audio->down_box(FL_DOWN_BOX);
        btn_mon_xmt_audio->callback((Fl_Callback*)cb_btn_mon_xmt_audio);
        o->value(progdefaults.mon_xmt_audio);
      } // Fl_Check_Button* btn_mon_xmt_audio
      { Fl_Value_Slider2* o = sldr_tx_vol = new Fl_Value_Slider2(10, 257, 290, 20, _("Tx Vol"));
        sldr_tx_vol->tooltip(_("Rx audio volume"));
        sldr_tx_vol->type(5);
        sldr_tx_vol->box(FL_DOWN_BOX);
        sldr_tx_vol->color((Fl_Color)206);
        sldr_tx_vol->selection_color((Fl_Color)2);
        sldr_tx_vol->labeltype(FL_NORMAL_LABEL);
        sldr_tx_vol->labelfont(0);
        sldr_tx_vol->labelsize(14);
        sldr_tx_vol->labelcolor(FL_FOREGROUND_COLOR);
        sldr_tx_vol->maximum(100);
        sldr_tx_vol->step(1);
        sldr_tx_vol->value(50);
        sldr_tx_vol->textsize(14);
        sldr_tx_vol->callback((Fl_Callback*)cb_sldr_tx_vol);
        sldr_tx_vol->align(Fl_Align(FL_ALIGN_RIGHT));
        sldr_tx_vol->when(FL_WHEN_CHANGED);
        o->value(progdefaults.mon_tx_vol);
      } // Fl_Value_Slider2* sldr_tx_vol
      o->end();
    } // Fl_Group* o
    o->end();
  } // Fl_Double_Window* o
  return w;
}

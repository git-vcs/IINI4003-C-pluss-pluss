#include <gtkmm.h>
using namespace std;
class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label labelFirstName;
  Gtk::Entry entryFirstName;
  Gtk::Label labelSecoundName;
  Gtk::Entry entrySecoundName;
  Gtk::Button button;
  Gtk::Label label;

void buttonupdate() {
    //for å sjekke om begge felt er fylt ut
    if(entryFirstName.get_text().size()&&entrySecoundName.get_text().size()){
        button.set_sensitive(true);
    } else{
        button.set_sensitive(false);
    }



}

    Window() {
        button.set_label("Combine names");
        labelFirstName.set_label("First name:");
        labelSecoundName.set_label("Last name:");
        vbox.pack_start(labelFirstName);
        vbox.pack_start(entryFirstName);  //Add the widget entry to vbox
        vbox.pack_start(labelSecoundName);
        vbox.pack_start(entrySecoundName);
        vbox.pack_start(button); //Add the widget button to vbox
        button.set_sensitive(false);
        vbox.pack_start(label);  //Add the widget label to vbox
        add(vbox);  //Add vbox to window
        show_all(); //Show all widgets
        entryFirstName.signal_changed().connect([this](){
        buttonupdate();
    });

    entrySecoundName.signal_changed().connect([this](){
        buttonupdate();
    });

      button.signal_clicked().connect([this]() {
          label.set_text(entryFirstName.get_text()+" "+entrySecoundName.get_text());
      });
  }

};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}
